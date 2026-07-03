#ifndef BN_SPRITE_ITEMS_COW_MEAT_H
#define BN_SPRITE_ITEMS_COW_MEAT_H

#include "bn_sprite_item.h"

//{{BLOCK(cow_meat_bn_gfx)

//======================================================================
//
//	cow_meat_bn_gfx, 64x64@8, 
//	+ palette 128 entries, not compressed
//	+ 64 tiles Metatiled by 8x8 not compressed
//	Total size: 256 + 4096 = 4352
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_COW_MEAT_BN_GFX_H
#define GRIT_COW_MEAT_BN_GFX_H

#define cow_meat_bn_gfxTilesLen 4096
extern const bn::tile cow_meat_bn_gfxTiles[128];

#define cow_meat_bn_gfxPalLen 256
extern const bn::color cow_meat_bn_gfxPal[128];

#endif // GRIT_COW_MEAT_BN_GFX_H

//}}BLOCK(cow_meat_bn_gfx)

namespace bn::sprite_items
{
    constexpr inline sprite_item cow_meat(sprite_shape_size(sprite_shape::SQUARE, sprite_size::HUGE), 
            sprite_tiles_item(span<const tile>(cow_meat_bn_gfxTiles, 128), bpp_mode::BPP_8, compression_type::NONE, 1), 
            sprite_palette_item(span<const color>(cow_meat_bn_gfxPal, 128), bpp_mode::BPP_8, compression_type::NONE));
}

#endif

