#pragma once
#include "Include.h"
class AppController
{

	public:
		typedef enum _EGetController{
			eNULL,
			eUP,
			eDOWN,
			eRIGHT,
			eLEFT,
			eBUTTON1,
			eBUTTON2,
			eBUTTON3,
			eBUTTON4,
			eBUTTON5,
			eBUTTON6,
			eBUTTON7,
			eBUTTON8,
			eBUTTON9,
			eBUTTON10,
			eBUTTON11,
			eBUTTON12
		}eGetController;

	private:
		
		int m_keyCount = 0;
		JOYINFOEX m_joyInfoEx;
		eGetController m_appGetKey;
	
	public:
		AppController();
		~AppController();
		eGetController m_PadInput();

		
};

