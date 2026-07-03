#ifndef BN_SPRITE_ITEMS_BANANA_H
#define BN_SPRITE_ITEMS_BANANA_H

#include "bn_sprite_item.h"

//{{BLOCK(banana_bn_gfx)

//======================================================================
//
//	banana_bn_gfx, 64x64@8, 
//	+ palette 96 entries, not compressed
//	+ 64 tiles Metatiled by 8x8 not compressed
//	Total size: 192 + 4096 = 4288
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BANANA_BN_GFX_H
#define GRIT_BANANA_BN_GFX_H

#define banana_bn_gfxTilesLen 4096
extern const bn::tile banana_bn_gfxTiles[128];

#define banana_bn_gfxPalLen 192
extern const bn::color banana_bn_gfxPal[96];

#endif // GRIT_BANANA_BN_GFX_H

//}}BLOCK(banana_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item banana(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(banana_bn_gfxTiles, 128), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(banana_bn_gfxPal, 96), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

