
//{{BLOCK(game2Background)

//======================================================================
//
//	game2Background, 512x256@4, 
//	+ palette 16 entries, not compressed
//	+ 164 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x32 
//	Total size: 32 + 5248 + 4096 = 9376
//
//	Time-stamp: 2020-04-22, 20:02:26
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GAME2BACKGROUND_H
#define GRIT_GAME2BACKGROUND_H

#define game2BackgroundTilesLen 5248
extern const unsigned short game2BackgroundTiles[2624];

#define game2BackgroundMapLen 4096
extern const unsigned short game2BackgroundMap[2048];

#define game2BackgroundPalLen 32
extern const unsigned short game2BackgroundPal[16];

#endif // GRIT_GAME2BACKGROUND_H

//}}BLOCK(game2Background)
