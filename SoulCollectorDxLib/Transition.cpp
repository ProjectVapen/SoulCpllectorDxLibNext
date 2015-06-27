#include "Transition.h"
#include "Include.h"



Transition::Transition():
b_fade(true)
{
	m_fadeInValue = 255;
	m_fadeOutValue = 0;
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

		if (b_fade){
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, m_fadeInValue);
			DrawBox(0, 0, 1280, 720, GetColor(255, 255, 255), TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

			m_fadeInValue -= 10;
			if (m_fadeInValue < 0)
			{
				m_fadeOutValue = m_fadeInValue;
				m_state = State::End;
				break;

			}
		}
		
		break;
		
	case Transition::State::BlackOut:

		
		if (b_fade){
			SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, m_fadeOutValue);
			DrawBox(0, 0, 1280, 720, GetColor(255, 255, 255), TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

			m_fadeOutValue += 10;
			if (m_fadeOutValue > 255)
			{
				m_fadeInValue=m_fadeOutValue;
				m_fadeOutValue = 0;
				m_state = State::End;
				break;

			}
		}

		
		
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

