#ifndef BN_REGULAR_BG_ITEMS_BG_H
#define BN_REGULAR_BG_ITEMS_BG_H

#include "bn_regular_bg_item.h"

//{{BLOCK(bg_bn_gfx)

//======================================================================
//
//	bg_bn_gfx, 512x512@4, 
//	+ palette 16 entries, not compressed
//	+ 2 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x64 
//	Total size: 32 + 64 + 8192 = 8288
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BG_BN_GFX_H
#define GRIT_BG_BN_GFX_H

#define bg_bn_gfxTilesLen 64
extern const bn::tile bg_bn_gfxTiles[2];

#define bg_bn_gfxMapLen 8192
extern const bn::regular_bg_map_cell bg_bn_gfxMap[4096];

#define bg_bn_gfxPalLen 32
extern const bn::color bg_bn_gfxPal[16];

#endif // GRIT_BG_BN_GFX_H

//}}BLOCK(bg_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item bg(
            regular_bg_tiles_item(span<const tile>(bg_bn_gfxTiles, 2), bpp_mode::BPP_4, compression_type::NONE), 
            bg_palette_item(span<const color>(bg_bn_gfxPal, 16), bpp_mode::BPP_4, compression_type::NONE),
            regular_bg_map_item(bg_bn_gfxMap[0], size(64, 64), compression_type::NONE, 1, false));
}

#endif

