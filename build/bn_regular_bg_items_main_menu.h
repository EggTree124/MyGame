#ifndef BN_REGULAR_BG_ITEMS_MAIN_MENU_H
#define BN_REGULAR_BG_ITEMS_MAIN_MENU_H

#include "bn_regular_bg_item.h"

//{{BLOCK(main_menu_bn_gfx)

//======================================================================
//
//	main_menu_bn_gfx, 256x256@8, 
//	+ palette 112 entries, not compressed
//	+ 136 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 224 + 8704 + 2048 = 10976
//
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MAIN_MENU_BN_GFX_H
#define GRIT_MAIN_MENU_BN_GFX_H

#define main_menu_bn_gfxTilesLen 8704
extern const bn::tile main_menu_bn_gfxTiles[272];

#define main_menu_bn_gfxMapLen 2048
extern const bn::regular_bg_map_cell main_menu_bn_gfxMap[1024];

#define main_menu_bn_gfxPalLen 224
extern const bn::color main_menu_bn_gfxPal[112];

#endif // GRIT_MAIN_MENU_BN_GFX_H

//}}BLOCK(main_menu_bn_gfx)

namespace bn::regular_bg_items
{
    constexpr inline regular_bg_item main_menu(
            regular_bg_tiles_item(span<const tile>(main_menu_bn_gfxTiles, 272), bpp_mode::BPP_8, compression_type::NONE), 
            bg_palette_item(span<const color>(main_menu_bn_gfxPal, 112), bpp_mode::BPP_8, compression_type::NONE),
            regular_bg_map_item(main_menu_bn_gfxMap[0], size(32, 32), compression_type::NONE, 1, false));
}

#endif

