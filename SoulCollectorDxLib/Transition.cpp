#include "Transition.h"


Transition::Transition()
{
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

	case Transition::State::BlackOut:
		break;

	case Transition::State::BlackIn:
		m_state = State::End;
		break;

	case Transition::State::WhiteOut:


	default:
		break;
	}
}

bool Transition::IsEnd(){
	if (m_state == State::End)
	{
		m_state = State::None;
		return true;
	}
	return false;
}