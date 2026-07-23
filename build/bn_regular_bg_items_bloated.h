#ifndef BN_REGULAR_BG_ITEMS_BLOATED_H
#define BN_REGULAR_BG_ITEMS_BLOATED_H

#include "bn_regular_bg_item.h"

//{{BLOCK(bloated_bn_gfx)

//======================================================================
//
//	bloated_bn_gfx, 256x256@8, 
//	+ palette 48 entries, not compressed
//	+ 144 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 96 + 9216 + 2048 = 11360
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BLOATED_BN_GFX_H
#define GRIT_BLOATED_BN_GFX_H

#define bloated_bn_gfxTilesLen 9216
extern const bn::tile bloated_bn_gfxTiles[288];

#define bloated_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell bloated_bn_gfxMap[1024];

#define bloated_bn_gfxPalLen 96
extern const bn::color bloated_bn_gfxPal[48];

#endif // GRIT_BLOATED_BN_GFX_H

//}}BLOCK(bloated_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item bloated(
            regular_bg_tiles_item(span<const tile>(bloated_bn_gfxTiles, 288), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(bloated_bn_gfxPal, 48), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(bloated_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

