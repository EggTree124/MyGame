#ifndef BN_SPRITE_ITEMS_CIRCLE_H
#define BN_SPRITE_ITEMS_CIRCLE_H

#include "bn_sprite_item.h"

//{{BLOCK(circle_bn_gfx)

//======================================================================
//
//	circle_bn_gfx, 16x16@8, 
//	+ palette 32 entries, not compressed
//	+ 4 tiles Metatiled by 2x2 not compressed
//	Total size: 64 + 256 = 320
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CIRCLE_BN_GFX_H
#define GRIT_CIRCLE_BN_GFX_H

#define circle_bn_gfxTilesLen 256
extern const bn::tile circle_bn_gfxTiles[8];

#define circle_bn_gfxPalLen 64
extern const bn::color circle_bn_gfxPal[32];

#endif // GRIT_CIRCLE_BN_GFX_H

//}}BLOCK(circle_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item circle(sprite_shape_size(sprite_shape::SQUARE, sprite_size::NORMAL), 
            sprite_tiles_item(span<const tile>(circle_bn_gfxTiles, 8), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(circle_bn_gfxPal, 32), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

