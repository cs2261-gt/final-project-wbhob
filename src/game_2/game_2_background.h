
//{{BLOCK(game2Background)

//======================================================================
//
//	game2Background, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 63 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 2016 + 2048 = 4576
//
//	Time-stamp: 2020-04-05, 15:09:15
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GAME2BACKGROUND_H
#define GRIT_GAME2BACKGROUND_H

#define game2BackgroundTilesLen 2016
extern const unsigned short game2BackgroundTiles[1008];

#define game2BackgroundMapLen 2048
extern const unsigned short game2BackgroundMap[1024];

#define game2BackgroundPalLen 512
extern const unsigned short game2BackgroundPal[256];

#endif // GRIT_GAME2BACKGROUND_H

//}}BLOCK(game2Background)
