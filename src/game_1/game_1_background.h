
//{{BLOCK(game1Background)

//======================================================================
//
//	game1Background, 256x256@4, 
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

#ifndef GRIT_GAME1BACKGROUND_H
#define GRIT_GAME1BACKGROUND_H

#define game1BackgroundTilesLen 2016
extern const unsigned short game1BackgroundTiles[1008];

#define game1BackgroundMapLen 2048
extern const unsigned short game1BackgroundMap[1024];

#define game1BackgroundPalLen 512
extern const unsigned short game1BackgroundPal[256];

#endif // GRIT_GAME1BACKGROUND_H

//}}BLOCK(game1Background)
