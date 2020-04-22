
//{{BLOCK(pauseBackground)

//======================================================================
//
//	pauseBackground, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 134 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 4288 + 2048 = 6848
//
//	Time-stamp: 2020-04-20, 21:03:59
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PAUSEBACKGROUND_H
#define GRIT_PAUSEBACKGROUND_H

#define pauseBackgroundTilesLen 4288
extern const unsigned short pauseBackgroundTiles[2144];

#define pauseBackgroundMapLen 2048
extern const unsigned short pauseBackgroundMap[1024];

#define pauseBackgroundPalLen 512
extern const unsigned short pauseBackgroundPal[256];

#endif // GRIT_PAUSEBACKGROUND_H

//}}BLOCK(pauseBackground)
