namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѿ�����d����O
	// 
	/////////////////////////////////////////////////////////////////////////////

	class stageSelector {
	public:
		stageSelector();
		void LoadBitmap();				//Ū���Ϥ�
		void ShowBitmap();				//��ܹϤ�
		void SetTopLeft();				//�]�w�y��
		void clickRight();				//������d���U���k���m��
		void clickLeft();				//������d���U�������m��
		int  getStage();				//���o�襤�����d
	private:
		static CMovingBitmap stageImage[30];//���d�Ϥ�
		bool isBmpLoaded;				// �O�_�w�g���J�ϧ�
		int  targetStage;				//�襤�����d
		int  finalStage;				//�̫�@��
	};
}