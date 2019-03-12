#ifndef _FPS_H_
#define _FPS_H_

struct SFpsControl {
	int Index, One;		// 添え字、1フレームあたりの時間
	double Fps;			// Fps
	int RemTime[60];	// 60回の描画にどれだけ時間がかかったか
	int PreCount;		// 1フレーム前の時間を記憶

	void FirstInit();
	void Process();
};

#endif
