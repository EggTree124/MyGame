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
#include "bn_sprite_items_bacon.h"

void randomPosition(bn::sprite_ptr& sprite, bn::random& rng);
bool timerOff(int& frame, int second);
void updateScore( 
    bn::sprite_text_generator &text_gen, 
    const bn::fixed_point &f_point, 
    bn::vector<bn::sprite_ptr,32> &text_cont, 
    bn::string<32> &score_text, 
    int score
);
enum class SceneType{
    MAIN_MENU,
    GAME,
    DEATH
};

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

SceneType game_play(){
    int half_size = 8;
    int score = 0;
    float fatness = 1.0;
    bn::random rng;

    //FONT
    bn::sprite_font font(bn::sprite_items::common_fixed_8x16_font);
    bn::sprite_text_generator text_gen(font); //this bullshit created sprites from the text
    bn::point points(0,0);
    bn::fixed_point f_point(points);
    bn::vector<bn::sprite_ptr,32> text_cont; //text container
    bn::string<32> score_text("Score: ");
    text_gen.generate_top_left(f_point,score_text,text_cont);
    int second = 0;
    //SPRITES
    bn::sprite_ptr sprite = bn::sprite_items::circle.create_sprite(0,0);
    sprite.set_scale(fatness);
    bn::regular_bg_ptr background_re = bn::regular_bg_items::red.create_bg(0,0);
    bn::sprite_ptr bacon = bn::sprite_items::bacon.create_sprite(0,0);
    //GAME LOGIC
    while(true)
    {   
        
        //Movement: Left, right, up, right
        if(bn::keypad::left_held() && sprite.x() > -120 + half_size){
            sprite.set_x(sprite.x() - 1);
        } 
        if(bn::keypad::right_held() && sprite.x() < 120 - half_size){
            sprite.set_x(sprite.x() + 1);   
        } 
        if(bn::keypad::up_held() && sprite.y() > -80 + half_size){
            sprite.set_y(sprite.y()-1);
        }
        if(bn::keypad::down_held() && sprite.y() < 80 - half_size){
            sprite.set_y(sprite.y()+1);
        }
        if(bn::keypad::select_held()){
            return SceneType::MAIN_MENU;
        }
        //Fatness and score manipulation
        if(bn::keypad::a_pressed()){
            score++;
            updateScore(text_gen, f_point,text_cont,score_text,score);
        }
        //Timer  seconds for now.
        if(timerOff(second, 1)){
            randomPosition(bacon, rng);
        }
        //UPDATE THE WHOLE GAME
        bn::core::update();
        
    }
}
int main()
{
    bn::core::init();
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

void randomPosition(bn::sprite_ptr& sprite, bn::random& rng){
    int x = -120 + (rng.get() % 240);
    int y = -80 + (rng.get() % 160);

    sprite.set_position(x, y);
}

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