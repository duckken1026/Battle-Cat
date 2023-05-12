namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���Ѥɯſ��]���s����O
	// 
	/////////////////////////////////////////////////////////////////////////////

	class levelUpButton {
	public:
		levelUpButton();
		void LoadBitmap();				//Ū���Ϥ�
		void ShowBitmap();				//��ܹϤ�
		void SetTopLeft();				//�]�w�y��
		int  getCurrentLevel();			//���o�ثe����
		bool checkAffordable(int currentMoney);	//�O�_�����������ɯŨæ^�ǥ��L��
		bool clickAction(int pointX, int pointY);//���U�ɪ��ʧ@�æ^�Ǧ��S���ɯ�
		int  requireMoney[7];					//�ɯũһݶO��
		int  maxMoney;							//�ɯū�W�[�h�֨�̤j���B
		int  addSpeed[8];						//���P���Ū����W�[���t��
		void SetInitLevel();					//�]�w��l�Ƶ���
	private:
		static CMovingBitmap button[15];		//���s�ϧ�
		bool isBmpLoaded;						//�O�_�w�g���J�ϧ�
		int  level;								//�ثe����
		void levelUp();							//�ɯ�level
		bool affordable;						//�O�_�����������ɯ�
		
	};
}