namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// �o��class���Ѱ��������Ĥ�n�]���ؼЪ���O
	// 
	/////////////////////////////////////////////////////////////////////////////

	class rivalDetector {
	public:
		rivalDetector();
		int findTarget(rivalAnimation *rivallist, int quantityOfRival);	//�q�Ĥ�}�C����X�ؼ�

	private:
		int target;		//�N�Q�]���ؼЪ��ĤH�s�b���ܼƤ�
	};
}