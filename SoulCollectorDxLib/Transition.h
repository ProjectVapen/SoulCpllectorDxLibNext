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

		//状態を設定して開始
		void Start(const State state);

		void UpData();

		//終了したかの処理
		bool IsEnd();


	private:

		//フェード状態
		State m_state;
};