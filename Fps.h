#ifndef _FPS_H_
#define _FPS_H_

struct SFpsControl {
	int Index, One;		// �Y�����A1�t���[��������̎���
	double Fps;			// Fps
	int RemTime[60];	// 60��̕`��ɂǂꂾ�����Ԃ�����������
	int PreCount;		// 1�t���[���O�̎��Ԃ��L��

	void FirstInit();
	void Process();
};

#endif
