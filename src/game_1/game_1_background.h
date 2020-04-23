
//{{BLOCK(game1Background)

//======================================================================
//
//	game1Background, 512x256@4, 
//	+ palette 16 entries, not compressed
//	+ 77 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x32 
//	Total size: 32 + 2464 + 4096 = 6592
//
//	Time-stamp: 2020-04-22, 20:20:06
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GAME1BACKGROUND_H
#define GRIT_GAME1BACKGROUND_H

#define game1BackgroundTilesLen 2464
extern const unsigned short game1BackgroundTiles[1232];

#define game1BackgroundMapLen 4096
extern const unsigned short game1BackgroundMap[2048];

#define game1BackgroundPalLen 32
extern const unsigned short game1BackgroundPal[16];

#endif // GRIT_GAME1BACKGROUND_H

//}}BLOCK(game1Background)
