
//{{BLOCK(loseBackground)

//======================================================================
//
//	loseBackground, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 119 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 3808 + 2048 = 6368
//
//	Time-stamp: 2020-04-20, 21:00:39
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_LOSEBACKGROUND_H
#define GRIT_LOSEBACKGROUND_H

#define loseBackgroundTilesLen 3808
extern const unsigned short loseBackgroundTiles[1904];

#define loseBackgroundMapLen 2048
extern const unsigned short loseBackgroundMap[1024];

#define loseBackgroundPalLen 512
extern const unsigned short loseBackgroundPal[256];

#endif // GRIT_LOSEBACKGROUND_H

//}}BLOCK(loseBackground)
