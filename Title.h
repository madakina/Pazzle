#ifndef _TITLE_H_
#define _TITLE_H_

const int TG_NUM = 8;	// TitleGraphicNumberの略
enum eTG_INDEX {
	TG_BACK,
	TG_Stage1, TG_Stage1View,
	TG_Stage2, TG_Stage2View,
	TG_Stage3, TG_Stage3View,
};
struct STitle {
	int Graphic[TG_NUM];

	void Process();		// この中でループする
	void Init();		// 初期化
	void FirstInit();	// コンストラクタ
	void Load();		// ロード
	void Draw();		// 描画系をここにまとめる
};

#endif