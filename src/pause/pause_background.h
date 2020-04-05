
//{{BLOCK(pauseBackground)

//======================================================================
//
//	pauseBackground, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 201 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 6432 + 2048 = 8992
//
//	Time-stamp: 2020-04-05, 15:31:25
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_PAUSEBACKGROUND_H
#define GRIT_PAUSEBACKGROUND_H

#define pauseBackgroundTilesLen 6432
extern const unsigned short pauseBackgroundTiles[3216];

#define pauseBackgroundMapLen 2048
extern const unsigned short pauseBackgroundMap[1024];

#define pauseBackgroundPalLen 512
extern const unsigned short pauseBackgroundPal[256];

#endif // GRIT_PAUSEBACKGROUND_H

//}}BLOCK(pauseBackground)
