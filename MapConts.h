#ifndef _MAPCONTS_H_
#define _MAPCONTS_H_

// 各マップにおけるブロックの初期配置を入れておく構造体
typedef struct {
	int BlockY;
	int BlockX;
	int BlockColor;
}BlockInit;
// 各マップにおけるブロックの個数を入れておく構造体
typedef struct {
	// 各ブロックの残り個数の判定
	int RedBlockCnt;
	int BlueBlockCnt;
	int GreenBlockCnt;
	int YellowBlockCnt;
}BlockCnt;

#endif