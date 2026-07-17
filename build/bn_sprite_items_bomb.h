#ifndef BN_SPRITE_ITEMS_BOMB_H
#define BN_SPRITE_ITEMS_BOMB_H

#include "bn_sprite_item.h"

//{{BLOCK(bomb_bn_gfx)

//======================================================================
//
//	bomb_bn_gfx, 16x16@8, 
//	+ palette 80 entries, not compressed
//	+ 4 tiles Metatiled by 2x2 not compressed
//	Total size: 160 + 256 = 416
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BOMB_BN_GFX_H
#define GRIT_BOMB_BN_GFX_H

#define bomb_bn_gfxTilesLen 256
extern const bn::tile bomb_bn_gfxTiles[8];

#define bomb_bn_gfxPalLen 160
extern const bn::color bomb_bn_gfxPal[80];

#endif // GRIT_BOMB_BN_GFX_H

//}}BLOCK(bomb_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item bomb(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(bomb_bn_gfxTiles, 8), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(bomb_bn_gfxPal, 80), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

