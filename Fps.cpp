#include"Pazzle.h"

// �t���[���R���g���[��
void SFpsControl::Process() {
	int Difference = GetNowCount() - PreCount;
	PreCount = GetNowCount();
	RemTime[Index] += Difference;
	Index++;

	if (Index == 60) {					// 60�񃋁[�v���Ă����Ȃ�
		Index = 0;						// �Y����������
		Fps = 0;						// ������
		for (int i = 0; i < 60; i++)	// 60��łǂꂾ���̎��Ԃ��o�߂�����
			Fps += RemTime[i];
		One = (int)(Fps / 60);			// ���ς�1�t���[���ɉ��~���b����������
		if (Fps != 0)					// �O�Ŋ���Ȃ����߂̏���
			Fps = ((60 / Fps) * 1000);	// Fps�����Ƃ߂�
		memset(RemTime, 0, sizeof(RemTime));
	}

	int WaitCount = 16 - Difference;
	if (WaitCount > 0) {				// ���������ɂ�����
		RemTime[Index] += WaitCount;
		Sleep(WaitCount);				// �҂�
	}
//	DrawFormatString(0, 0, White, "%3.1f", Fps);
//	DrawFormatString(0, 20, White, "%d", One);
}

void SFpsControl::FirstInit() {
	memset(this, 0, sizeof(SFpsControl));
}

