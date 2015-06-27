#include "BattleCard.h"

//BattleCard::eSelect BattleCard::e_select = eSelect::First;

BattleCard::BattleCard()
{
	m_pDataCard = std::make_unique<DataCard>();
	m_pDataCard->DeckDataSetUp();

	m_vBattleDeckData.resize(m_pDataCard->GetCSVLineData());

	for (int i = 0; i < m_pDataCard->GetCSVLineData(); i++){
		m_vBattleDeckData[i].m_sId = m_pDataCard->m_vDeckList[i].m_sId;
		m_vBattleDeckData[i].m_sType = m_pDataCard->m_vDeckList[i].m_sType;
		m_vBattleDeckData[i].m_sKind = m_pDataCard->m_vDeckList[i].m_sKind;
		m_vBattleDeckData[i].m_sName = m_pDataCard->m_vDeckList[i].m_sName;
		m_vBattleDeckData[i].m_sGrHand = m_pDataCard->m_vDeckList[i].m_sGrHand;
	}

	s_pos[0].pos_x1 = 10;
	s_pos[0].pos_x2 = 150;

	s_pos[1].pos_x1 = 160;
	s_pos[1].pos_x2 = 300;

	s_pos[2].pos_x1 = 310;
	s_pos[2].pos_x2 = 450;

	s_pos[3].pos_x1 = 460;
	s_pos[3].pos_x2 = 600;

	s_pos[4].pos_x1 = 610;
	s_pos[4].pos_x2 = 750;

	BattleCardStandbyPhase();
}


BattleCard::~BattleCard()
{
}

void BattleCard::BattleCardSetUp()
{
	m_vBattleDeckData.resize(m_pDataCard->GetCSVLineData());

	for (int i = 0; i < m_pDataCard->GetCSVLineData(); i++){
		m_vBattleDeckData[i].m_sId = m_pDataCard->m_vDeckList[i].m_sId;
		m_vBattleDeckData[i].m_sType = m_pDataCard->m_vDeckList[i].m_sType;
		m_vBattleDeckData[i].m_sKind = m_pDataCard->m_vDeckList[i].m_sKind;
		m_vBattleDeckData[i].m_sName = m_pDataCard->m_vDeckList[i].m_sName;
		m_vBattleDeckData[i].m_sGrHand = m_pDataCard->m_vDeckList[i].m_sGrHand;
	}
}

void BattleCard::BattleCardStandbyPhase()
{
	/*		//	ドローするよ！	//		*/
	if (m_vBattleDeckData.size() == 0){
		BattleCardSetUp();
	}

	if (m_vBattleHandData.size() < 5){
		if (m_vBattleDeckData.size() < 5){

			for (int i = m_vBattleHandData.size(); i < m_vBattleDeckData.size(); i++){
				std::vector<SBattleCard>::const_iterator itr = m_vBattleDeckData.begin();

				m_vBattleHandData.push_back(m_vBattleDeckData.front());

				m_vBattleDeckData.erase(itr);
			}
		}
		else
		{
			for (int i = m_vBattleHandData.size(); i < 5; i++){
				std::vector<SBattleCard>::const_iterator itr = m_vBattleDeckData.begin();

				m_vBattleHandData.push_back(m_vBattleDeckData.front());

				m_vBattleDeckData.erase(itr);
			}
		}
	}
	for (int i = 0; i < 5; i++){
		GrHand[i] = LoadGraph(m_vBattleHandData[i].m_sGrHand.c_str());
	}
}

int BattleCard::BattleCardSelect_C_Phase(int* type, int* kind)
{

	static int cnt = 0;

	if (CheckHitKey(KEY_INPUT_RETURN)){
		*type = m_vBattleHandData[cnt].m_sType;
		*kind = m_vBattleHandData[cnt].m_sKind;
		//ここにスキルデータ（今は無い）
		return 1;
	}
	else if (cnt == 5){
		if (CheckHitKey(KEY_INPUT_RIGHT)){
			cnt = 0;
			DrawExtendGraph(s_pos[cnt].pos_x1, 550, s_pos[cnt].pos_x2, 690, GrHand[cnt], FALSE);
			DrawExtendGraph(s_pos[5].pos_x1, 530, s_pos[5].pos_x2, 710, GrHand[5], FALSE);
		}
	}
	else if (cnt == 0){
		if (CheckHitKey(KEY_INPUT_LEFT)){
			cnt = 5;
			DrawExtendGraph(s_pos[cnt].pos_x1, 550, s_pos[cnt].pos_x2, 690, GrHand[cnt], FALSE);
			DrawExtendGraph(s_pos[0].pos_x1, 530, s_pos[0].pos_x2, 710, GrHand[0], FALSE);
		}
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)){
		cnt++;
		DrawExtendGraph(s_pos[cnt].pos_x1, 550, s_pos[cnt].pos_x2, 690, GrHand[cnt], FALSE);
		DrawExtendGraph(s_pos[cnt - 1].pos_x1, 530, s_pos[cnt - 1].pos_x2, 710, GrHand[cnt - 1], FALSE);
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)){
		cnt--;
		DrawExtendGraph(s_pos[cnt].pos_x1, 550, s_pos[cnt].pos_x2, 690, GrHand[cnt], FALSE);
		DrawExtendGraph(s_pos[cnt - 1].pos_x1, 530, s_pos[cnt - 1].pos_x2, 710, GrHand[cnt - 1], FALSE);
	}
	return 0;
}

void BattleCard::Render()
{
	/*		//	手札を表示するよ！	//		*/
	for (int i = 0; i < 5; i++){
		DrawExtendGraph(s_pos[i].pos_x1, 530, s_pos[i].pos_x2, 710, GrHand[i], FALSE);
	}
}

void BattleCard::ImageDelete()
{
	for (int i = 0; i < 5; i++){
		DeleteGraph(GrHand[i]);
	}
	m_vBattleHandData.clear();
}