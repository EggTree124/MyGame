#ifndef BN_SPRITE_ITEMS_FRIED_C_H
#define BN_SPRITE_ITEMS_FRIED_C_H

#include "bn_sprite_item.h"

//{{BLOCK(fried_c_bn_gfx)

//======================================================================
//
//	fried_c_bn_gfx, 32x32@8, 
//	+ palette 96 entries, not compressed
//	+ 16 tiles Metatiled by 4x4 not compressed
//	Total size: 192 + 1024 = 1216
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FRIED_C_BN_GFX_H
#define GRIT_FRIED_C_BN_GFX_H

#define fried_c_bn_gfxTilesLen 1024
extern const bn::tile fried_c_bn_gfxTiles[32];

#define fried_c_bn_gfxPalLen 192
extern const bn::color fried_c_bn_gfxPal[96];

#endif // GRIT_FRIED_C_BN_GFX_H

//}}BLOCK(fried_c_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item fried_c(sprite_shape_size(sprite_shape::SQUARE, sprite_size::BIG), 
            sprite_tiles_item(span<const tile>(fried_c_bn_gfxTiles, 32), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(fried_c_bn_gfxPal, 96), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

