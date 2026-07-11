#ifndef BN_SPRITE_ITEMS_GRAPE_H
#define BN_SPRITE_ITEMS_GRAPE_H

#include "bn_sprite_item.h"

//{{BLOCK(grape_bn_gfx)

//======================================================================
//
//	grape_bn_gfx, 32x32@8, 
//	+ palette 128 entries, not compressed
//	+ 16 tiles Metatiled by 4x4 not compressed
//	Total size: 256 + 1024 = 1280
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GRAPE_BN_GFX_H
#define GRIT_GRAPE_BN_GFX_H

#define grape_bn_gfxTilesLen 1024
extern const bn::tile grape_bn_gfxTiles[32];

#define grape_bn_gfxPalLen 256
extern const bn::color grape_bn_gfxPal[128];

#endif // GRIT_GRAPE_BN_GFX_H

//}}BLOCK(grape_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item grape(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(grape_bn_gfxTiles, 32), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(grape_bn_gfxPal, 128), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

