#include "BattleMedium.h"
#include "AppController.h"

BattleMedium::BattleMedium()
{

}

void BattleMedium::m_DataInit(){
	m_target = 0;
	Medium1.m_SetMedium("メデュ子", 10, 1000, 150, 130, 180, 0, 0);
	Medium2.m_SetMedium("尾崎の奢り", 1, 2, 3, 4, 5, 0, 0);
	Medium3.m_SetMedium("選ばれたのは”綾鷹”でした。", 10000, 1000000, 10000000, 100000000, 1, 0, 0);
}

void BattleMedium::m_Skill(){
	//湯川'sCardからどこに何がセットされているか受け取る
	switch (/*媒体をゲットする関数*/1)
	{
	case m_MEDIUM1:
		Medium1.m_MediumSkl(/*スキルをゲットする関数*/1);
		break;
	case m_MEDIUM2:
		Medium2.m_MediumSkl(/*スキルをゲットする関数*/4);
		break;
	case m_MEDIUM3:
		Medium3.m_MediumSkl(/*スキルをゲットする関数*/3);
		break;
	default:
		break;
	}
}

void BattleMedium::m_Target(){

	//仮操作
	if (CheckHitKey(KEY_INPUT_A)) m_target = 1;
	if (CheckHitKey(KEY_INPUT_B)) m_target = 2;
	if (CheckHitKey(KEY_INPUT_C)) m_target = 3;

	if (CheckHitKey(KEY_INPUT_RETURN)){
		switch (/*媒体をゲットする関数*/1)
		{
		case m_MEDIUM1:
			Medium1.m_MediumTag(m_target);
			break;
		case m_MEDIUM2:
			Medium2.m_MediumTag(m_target);
			break;
		case m_MEDIUM3:
			Medium3.m_MediumTag(m_target);
			break;
		default:
			break;
		}

		/*カード選択に戻る*/
	}
}

void BattleMedium::m_Proc(){
	m_Skill();
	m_Target();
}