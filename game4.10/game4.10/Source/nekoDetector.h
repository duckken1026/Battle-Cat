namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���Ѱ��������߫}�n�]���ؼЪ���O
	// 
	/////////////////////////////////////////////////////////////////////////////

	class nekoDetector {
	public:
		nekoDetector();
		int findTarget(nekoAnimation *nekolist,int quantityOfNeko);	//�q�߫}�}�C����X�ؼ�

	private:
		int target;		//�N�Q�]���ؼЪ��߫}�s�b���ܼƤ�
	};
}