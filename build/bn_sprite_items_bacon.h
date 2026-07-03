#ifndef BN_SPRITE_ITEMS_BACON_H
#define BN_SPRITE_ITEMS_BACON_H

#include "bn_sprite_item.h"

//{{BLOCK(bacon_bn_gfx)

//======================================================================
//
//	bacon_bn_gfx, 64x64@8, 
//	+ palette 32 entries, not compressed
//	+ 64 tiles Metatiled by 8x8 not compressed
//	Total size: 64 + 4096 = 4160
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACON_BN_GFX_H
#define GRIT_BACON_BN_GFX_H

#define bacon_bn_gfxTilesLen 4096
extern const bn::tile bacon_bn_gfxTiles[128];

#define bacon_bn_gfxPalLen 64
extern const bn::color bacon_bn_gfxPal[32];

#endif // GRIT_BACON_BN_GFX_H

//}}BLOCK(bacon_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item bacon(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(bacon_bn_gfxTiles, 128), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(bacon_bn_gfxPal, 32), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

