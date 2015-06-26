#include "AppController.h"


AppController::AppController()
{
	m_joyInfoEx.dwSize = sizeof(JOYINFOEX);
	m_joyInfoEx.dwFlags = JOY_RETURNALL;
	m_appGetKey = eNULL;
	for (unsigned int i = 0; i < joyGetNumDevs(); i++)
	{
		if (JOYERR_NOERROR == joyGetPosEx(i, &m_joyInfoEx))
		{
			DrawFormatString(0, 0, GetColor(0, 0, 0), "ジョイスティック NO.%d 接続されています", i);
		}
	}
}


AppController::~AppController()
{
}


AppController::eGetController AppController::m_PadInput(){
	
	m_keyCount++;
	if (JOYERR_NOERROR == joyGetPosEx(0, &m_joyInfoEx))
	{
		if (m_keyCount > 10)
		{
			m_keyCount = 0;
			
			if (m_joyInfoEx.dwYpos < 0x4000) m_appGetKey = eUP;
			if (m_joyInfoEx.dwYpos > 0xC000) m_appGetKey = eDOWN;
			if (m_joyInfoEx.dwXpos < 0x4000) m_appGetKey = eLEFT;
			if (m_joyInfoEx.dwXpos > 0xC000) m_appGetKey = eRIGHT;

			switch (m_joyInfoEx.dwButtons)
			{
			case 1:    m_appGetKey = eBUTTON1;  break;
			case 2:    m_appGetKey = eBUTTON2;  break;
			case 4:    m_appGetKey = eBUTTON3;  break;
			case 8:    m_appGetKey = eBUTTON4;  break;
			case 16:   m_appGetKey = eBUTTON5;  break;
			case 32:   m_appGetKey = eBUTTON6;  break;
			case 64:   m_appGetKey = eBUTTON7;  break;
			case 128:  m_appGetKey = eBUTTON8;  break;
			case 256:  m_appGetKey = eBUTTON9;  break;
			case 512:  m_appGetKey = eBUTTON10; break;
			case 1024: m_appGetKey = eBUTTON11; break;
			case 2048: m_appGetKey = eBUTTON12; break;
			default:   m_appGetKey = eNULL;     break;
			}
		}
	}
	else
	{
		MessageBox(NULL, "ジョイスティックが検出できなくなりました", "エラー", MB_OK);
	}
	
	return m_appGetKey;
}