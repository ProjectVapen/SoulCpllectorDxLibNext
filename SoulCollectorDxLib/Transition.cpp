#include "Transition.h"
#include "Include.h"

Transition::Transition():
m_fadeInValue(0),
m_fadeOutValue(255),
b_fade(true)
{
	m_fadeValue = 0;
}


Transition::~Transition()
{
}

void Transition::Start(const State state){
	m_state = state;
}

void Transition::UpData(){
	if (m_state == State::None)return;

	switch (m_state)
	{

	case Transition::State::BlackIn:
		MessageBox(NULL, "BlackIn！", "デバッグ", MB_OK);
		
		break;
		
		
	case Transition::State::BlackOut:
		MessageBox(NULL, "BlackOut！", "デバッグ", MB_OK);
		m_state = State::End;
		break;
		
		
	case Transition::State::WhiteOut:

		break;

	case Transition::State::WhiteIn:
		break;
	default:
		m_state = State::End;
		break;
	}
	
}

bool Transition::IsEnd(){

	if (m_state == State::End)
	{
		m_state = State::None;
		return true;
	}
	else
	{
		return false;
	}
	
}