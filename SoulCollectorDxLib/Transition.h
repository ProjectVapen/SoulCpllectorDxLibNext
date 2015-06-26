#pragma once
class Transition{

	public:
		Transition();
		~Transition();

		enum class State
		{
			None,
			BlackIn,
			BlackOut,
			WhiteIn,
			WhiteOut,
			End
		};

		//��Ԃ�ݒ肵�ĊJ�n
		void Start(const State state);

		void UpData();

		//�I���������̏���
		bool IsEnd();


	private:

		//�t�F�[�h���
		State m_state;
};