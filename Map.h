#ifndef _MAPDATA_H_
#define _MAPDATA_H_

const int MDG_NUM = 10;	// MapDataGraphicNumberの略
// 各画像用の変数
enum eMDG_INDEX {
	MDG_GroundBlock,
	MDG_Block1, MDG_Block2, MDG_Block3, MDG_Block4, MDG_Block5,
	MDG_Look1, MDG_Look2, MDG_Look3,
};
// MapData.cppファイルで使用する関数の構造体
struct SMapData {
	int Graphic[MG_NUM];

	// 画像の初期化
	void Load();
	// マップのデータを確認
	void Map1();
	void Map2();
	void Map3();
	// ブロックの初期位置を記憶
	void BlockInitPosition();
	// ブロック画像の表示
	void BlockDisplay(int blockcolor, int blockx, int blocky);
	// 各画像の落下処理
	void BlockFallMove(int blockx, int blocky);
	// 各画像の左の移動処理
	void BlockLeftMove(int blockx, int blocky);
	// 各画像の右の移動処理
	void BlockRightMove(int blockx, int blocky);
	// 各画像と錠前付ブロックの衝突した時にブロックを消去処理
	void BlockDelete(int blockcolor, int blockx, int blocky);
	// 対応するブロックが全て消えた後に錠前付ブロックを消去処理
	void BlockLookDelete(int blockccolor, int blockx, int blocky);
	// マップに配置された各ブロックの座標を探す
	void MousePosition(int blockcolor, int blockx, int blocky);

	// ブロックの初期位置を記憶
	void BlockInitPosition2();
	// ブロック画像の表示
	void BlockDisplay2(int blockcolor, int blockx, int blocky);
	// 各画像の落下処理
	void BlockFallMove2(int blockx, int blocky);
	// 各画像の左の移動処理
	void BlockLeftMove2(int blockx, int blocky);
	// 各画像の右の移動処理
	void BlockRightMove2(int blockx, int blocky);
	// 各画像と錠前付ブロックの衝突した時にブロックを消去処理
	void BlockDelete2(int blockcolor, int blockx, int blocky);
	// 対応するブロックが全て消えた後に錠前付ブロックを消去処理
	void BlockLookDelete2(int blockccolor, int blockx, int blocky);
	// マップに配置された各ブロックの座標を探す
	void MousePosition2(int blockcolor, int blockx, int blocky);

	// ブロックの初期位置を記憶
	void BlockInitPosition3();
	// ブロック画像の表示
	void BlockDisplay3(int blockcolor, int blockx, int blocky);
	// 各画像の落下処理
	void BlockFallMove3(int blockx, int blocky);
	// 各画像の左の移動処理
	void BlockLeftMove3(int blockx, int blocky);
	// 各画像の右の移動処理
	void BlockRightMove3(int blockx, int blocky);
	// 各画像と錠前付ブロックの衝突した時にブロックを消去処理
	void BlockDelete3(int blockcolor, int blockx, int blocky);
	// 対応するブロックが全て消えた後に錠前付ブロックを消去処理
	void BlockLookDelete3(int blockccolor, int blockx, int blocky);
	// マップに配置された各ブロックの座標を探す
	void MousePosition3(int blockcolor, int blockx, int blocky);
};
#endif