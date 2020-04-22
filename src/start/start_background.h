
//{{BLOCK(startBackground)

//======================================================================
//
//	startBackground, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 119 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 3808 + 2048 = 6368
//
//	Time-stamp: 2020-04-20, 20:06:06
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_STARTBACKGROUND_H
#define GRIT_STARTBACKGROUND_H

#define startBackgroundTilesLen 3808
extern const unsigned short startBackgroundTiles[1904];

#define startBackgroundMapLen 2048
extern const unsigned short startBackgroundMap[1024];

#define startBackgroundPalLen 512
extern const unsigned short startBackgroundPal[256];

#endif // GRIT_STARTBACKGROUND_H

//}}BLOCK(startBackground)
