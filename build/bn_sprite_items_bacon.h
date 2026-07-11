#ifndef BN_SPRITE_ITEMS_BACON_H
#define BN_SPRITE_ITEMS_BACON_H

#include "bn_sprite_item.h"

//{{BLOCK(bacon_bn_gfx)

//======================================================================
//
//	bacon_bn_gfx, 32x32@4, 
//	+ palette 16 entries, not compressed
//	+ 16 tiles Metatiled by 4x4 not compressed
//	Total size: 32 + 512 = 544
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BACON_BN_GFX_H
#define GRIT_BACON_BN_GFX_H

#define bacon_bn_gfxTilesLen 512
extern const bn::tile bacon_bn_gfxTiles[16];

#define bacon_bn_gfxPalLen 32
extern const bn::color bacon_bn_gfxPal[16];

#endif // GRIT_BACON_BN_GFX_H

//}}BLOCK(bacon_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item bacon(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(bacon_bn_gfxTiles, 16), bpp_mode::BPP_4, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(bacon_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE));
}

#endif

