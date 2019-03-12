#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#ifdef _GLOBAL_SET_
#define GLOBAL  
#else
#define GLOBAL extern
#endif


// ŠO•”•Ï”éŒ¾‚ğ‚Ü‚Æ‚ß‚éB

GLOBAL int Key[256];
GLOBAL int GameState;
GLOBAL int StageFlag;
GLOBAL int Stage;
GLOBAL int centerx;

GLOBAL int Mousex;
GLOBAL int Mousey;

GLOBAL int input_RIGHT;
GLOBAL int input_LEFT;
GLOBAL int RIGHT_Move;
GLOBAL int LEFT_Move;

GLOBAL SGameClear GameClear;
GLOBAL SGameMain GameMain;
GLOBAL STitle Title;
GLOBAL SMapView MapView;
GLOBAL SMapData MapData;
GLOBAL SBgmControl BgmControl;
GLOBAL SSeControl SeControl;
GLOBAL SFpsControl FpsControl;

// ’l‚ğ•Ï‚¦‚é‚±‚Æ‚ª‚Å‚«‚È‚¢
const int White = GetColor(255, 255, 255);
const int Black = GetColor(0, 0, 0);
const int Red = GetColor(255, 0, 0);
const int Green = GetColor(0, 255, 0);
const int Blue = GetColor(0, 0, 255);

#endif