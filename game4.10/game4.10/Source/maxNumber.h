namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class������̤ܳj��ƹϧΪ���O
	// 
	/////////////////////////////////////////////////////////////////////////////

	class maxNumber {
	public:
		maxNumber(int = 3);			// default 5 digits
		void Add(int n);			// �W�[��ƭ�
		int  GetInteger();			// �^�Ǿ�ƭ�
		void LoadBitmap();			// ���J0..9�έt�����ϧ�
		void SetInteger(int);		// �]�w��ƭ�
		void SetTopLeft(int, int);	// �N�ʵe�����W���y�в��� (x,y)
		void ShowBitmap();			// �N�ʵe�K��ù�
		void SetDigits(int);			// �]�w���
	private:
		int NUMDIGITS;			// �@���NUMDIGITS�Ӧ��
		static CMovingBitmap digit[13]; // �x�s0..9�έt�����ϧ�(bitmap)
		int x, y;						// ��ܪ��y��
		int n;							// ��ƭ�
		bool isBmpLoaded = false;				// �O�_�w�g���J�ϧ�
	};
}