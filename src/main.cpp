//Components
#include "bn_core.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_items_circle.h"
#include "bn_keypad.h"
#include "bn_random.h"
#include "bn_regular_bg_items_red.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_items_main_menu.h"
#include "bn_regular_bg_items_ds.h"
#include "bn_string_view.h"
#include "bn_string.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_font.h"
#include "bn_sprite_items_common_fixed_8x16_font.h"
#include "bn_vector.h"
#include "bn_rect.h"
#include "bn_fixed_rect.h"
//SPRITES FOR FOODS: BACON, COW MEAT, FRIED, BANANA, GRAPE
#include "bn_sprite_items_bacon.h"
#include "bn_sprite_items_cow_meat.h"
#include "bn_sprite_items_fried_c.h"
#include "bn_sprite_items_banana.h"
#include "bn_sprite_items_grape.h"

//Functions for the game cores
bool timerOff(int& frame, int second);
void updateScore( 
    bn::sprite_text_generator &text_gen, 
    const bn::fixed_point &f_point, 
    bn::vector<bn::sprite_ptr,32> &text_cont, 
    bn::string<32> &score_text, 
    int score
);
void movement(bn::sprite_ptr &sprite, int &half_size, bn::fixed &speed);
void random_sprite(bn::random &sprite_gen, bn::vector<bn::sprite_ptr, 6>& Sprites);
//Scenes for the game.
enum class SceneType{
    MAIN_MENU,
    GAME,
    DEATH
};


//Main Menu Mechanism
SceneType play_menu(){
    bn::regular_bg_ptr main = bn::regular_bg_items::main_menu.create_bg(0,0);
    while(true){
        if(bn::keypad::start_pressed()){
            return SceneType::GAME;
        }
        if(bn::keypad::select_pressed()){
            bn::core::reset();
        }
        bn::core::update();
    }
}
//End of Main Menu Mechanism

//Death Screen Mechanism
SceneType death(){
    bn::regular_bg_ptr death = bn::regular_bg_items::ds.create_bg(0,0);
    while(true){
        if(bn::keypad::a_pressed()){
            return SceneType::GAME;
        }
        if(bn::keypad::b_pressed()){
            return SceneType::MAIN_MENU;
        }
        bn::core::update();
    }
}
//END OF Death Screen Mechanism

//Game core
SceneType game_play(){
    int half_size = 8;
    int score = 0;
    bn::fixed fatness = 1.0;
    bn::random rng;
    bn::fixed speed = 2.0;

    //FONT AND STARTING TEXT
    bn::sprite_font font(bn::sprite_items::common_fixed_8x16_font);
    bn::sprite_text_generator text_gen(font); //this bullshit created sprites from the text
    bn::point points(0,0);
    bn::fixed_point f_point(points);
    bn::vector<bn::sprite_ptr,32> text_cont;
     //text container
    bn::string<32> score_text("Score: ");
    text_gen.generate_top_left(f_point,score_text,text_cont);
    //End of Starting Text

    //Frame
    int second = 0;
    //End of frame

    //Initialize Sprite
    bn::sprite_ptr sprite = bn::sprite_items::circle.create_sprite(0,0);
    sprite.set_scale(fatness);
    bn::regular_bg_ptr background_re = bn::regular_bg_items::red.create_bg(0,0);
    //End of sprite initialization

    //RNG for the sprites
    bn::vector<bn::sprite_ptr, 6> active_sprites;
    bn::random sprite_gen;

    //GAME LOGIC
    while(true)
    {   
        movement(sprite, half_size, speed);
        if(bn::keypad::select_held()){
            return SceneType::MAIN_MENU;
        }
        //Score manipulation
        if(bn::keypad::a_pressed()){
            score++;
            updateScore(text_gen, f_point,text_cont,score_text,score);
            
        }
        //Timer.
        if(timerOff(second, 1)){
            random_sprite(sprite_gen, active_sprites);
        }

        auto it = active_sprites.begin();
        while(it != active_sprites.end())
        {
            // Move the food sprite down
            it->set_y(it->y() + 1);
            //Adding the rect
            bn::fixed_rect player_rect(sprite.x(), sprite.y(), 16,16);
            bn::fixed_rect food_rect(it->x(), it->y(), 16,16);

            if(player_rect.intersects(food_rect)){
                score++;
                updateScore(text_gen, f_point, text_cont, score_text, score);
                fatness += 0.05;
                speed -= 0.05;
                sprite.set_scale(fatness);
                it = active_sprites.erase(it);
            } else if(it->y() > 80 + 32)
            {
                it = active_sprites.erase(it); // Remove off-screen sprite safely
            }
            else
            {
                ++it; // Move to the next sprite
            }
}
        //UPDATE THE WHOLE GAME
        bn::core::update();
        
    }
    //end of game core
}

//The engine
int main()
{
    bn::core::init();
    //Start with the main menu
    SceneType current_scene = SceneType::MAIN_MENU;
    while(true){
        switch(current_scene){
            case SceneType::MAIN_MENU:
                current_scene = play_menu();
                break;
            case SceneType::GAME:
                current_scene = game_play();
                break;
            default:
                break;
        }
    }
}

//Implementation of functions
bool timerOff(int& frame, int second){
    frame++;
    if(frame >= second * 60){
        frame = 0;
        return true;
    }
    return false;
}

void updateScore( 
    bn::sprite_text_generator &text_gen, 
    const bn::fixed_point &f_point, 
    bn::vector<bn::sprite_ptr,32> &text_cont, 
    bn::string<32> &score_text, 
    int score
){
    text_cont.clear();
    score_text = "Score: ";
    score_text.append(bn::to_string<10>(score));
    text_gen.generate_top_left(f_point, score_text, text_cont);
}

void movement(bn::sprite_ptr &sprite, int &half_size, bn::fixed &speed){
     //Movement: Left, right, up, right. The half size is needed so that the sprite wont go off bound.
        if(bn::keypad::left_held() && sprite.x() > -120 + half_size){
            sprite.set_x(sprite.x() - speed);
        } 
        if(bn::keypad::right_held() && sprite.x() < 120 - half_size){
            sprite.set_x(sprite.x() + speed);   
        } 
        if(bn::keypad::up_held() && sprite.y() > -80 + half_size){
            sprite.set_y(sprite.y()- speed);
        }
        if(bn::keypad::down_held() && sprite.y() < 80 - half_size){
            sprite.set_y(sprite.y()+ speed);
        }
}

void random_sprite(bn::random &sprite_gen, bn::vector<bn::sprite_ptr, 6>& Sprites){
    if(Sprites.full()){
        return;
    }
    bn::fixed rand_x = sprite_gen.get_int(240) - 120;
    bn::fixed rand_y = -80;

    // Pick a random sprite out of 5 rm -rf build && make -j$(nproc)options
    int sprite_choice = sprite_gen.get_int(5);
    
    switch (sprite_choice) {
        case 0:
            Sprites.push_back(bn::sprite_items::bacon.create_sprite(rand_x, rand_y));
            break;
        case 1:
            Sprites.push_back(bn::sprite_items::banana.create_sprite(rand_x, rand_y));
            break;
        case 2:
            Sprites.push_back(bn::sprite_items::cow_meat.create_sprite(rand_x, rand_y));
            break;
        case 3:
            Sprites.push_back(bn::sprite_items::fried_c.create_sprite(rand_x, rand_y));
            break;
        case 4:
            Sprites.push_back(bn::sprite_items::grape.create_sprite(rand_x, rand_y));
            break;
    }
}