#ifndef BN_SPRITE_ITEMS_FRIED_C_H
#define BN_SPRITE_ITEMS_FRIED_C_H

#include "bn_sprite_item.h"

//{{BLOCK(fried_c_bn_gfx)

//======================================================================
//
//	fried_c_bn_gfx, 64x64@8, 
//	+ palette 96 entries, not compressed
//	+ 64 tiles Metatiled by 8x8 not compressed
//	Total size: 192 + 4096 = 4288
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FRIED_C_BN_GFX_H
#define GRIT_FRIED_C_BN_GFX_H

#define fried_c_bn_gfxTilesLen 4096
extern const bn::tile fried_c_bn_gfxTiles[128];

#define fried_c_bn_gfxPalLen 192
extern const bn::color fried_c_bn_gfxPal[96];

#endif // GRIT_FRIED_C_BN_GFX_H

//}}BLOCK(fried_c_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item fried_c(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(fried_c_bn_gfxTiles, 128), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(fried_c_bn_gfxPal, 96), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

