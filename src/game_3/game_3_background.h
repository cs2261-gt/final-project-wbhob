
//{{BLOCK(game3Background)

//======================================================================
//
//	game3Background, 256x256@4, 
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

#ifndef GRIT_GAME3BACKGROUND_H
#define GRIT_GAME3BACKGROUND_H

#define game3BackgroundTilesLen 2016
extern const unsigned short game3BackgroundTiles[1008];

#define game3BackgroundMapLen 2048
extern const unsigned short game3BackgroundMap[1024];

#define game3BackgroundPalLen 512
extern const unsigned short game3BackgroundPal[256];

#endif // GRIT_GAME3BACKGROUND_H

//}}BLOCK(game3Background)
