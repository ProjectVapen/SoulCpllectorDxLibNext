#pragma once
#include "Include.h"
#include "DataCard.h"
/***************************************************************************/
//	まあ簡単に流れを説明しておくとね、
//	DataCardでCSV読み込みして、そのデータを ""データとしての"" デッキデータとして保存するんだ。
//	その後、BattleCardで上記のデッキデータから "バトル用の"デッキデータに読み込むんだ。
//	なんでこんな面倒なことしてるかって言うと、
//	デッキ空になるとさー、墓地から戻ってくるじゃん？不死身ジャン？じゃん？JAN！？
//	ってことでデータあるならそっからまた読み込んじゃおうって魂胆。
/***************************************************************************/


class BattleCard
{
private:

	typedef struct _BattleCard
	{
		int m_sId;
		int m_sType;
		int m_sKind;
		std::string m_sName;
		std::string m_sGrHand;
	}SBattleCard;

	typedef enum class _Select
	{
		First,
		Second,
		Third,
		Fourth,
		Fifth,
	}eSelect;

	typedef struct _POS
	{

		int pos_x1;
		int pos_x2;

	}SPOS;

	int GrHand[5];

	SPOS s_pos[5];

	//static eSelect e_select;

	std::unique_ptr<DataCard>m_pDataCard;

	std::vector<SBattleCard>m_vBattleDeckData;
	std::vector<SBattleCard>m_vBattleHandData;

public:
	BattleCard();
	~BattleCard();

	//デッキとか初期化されるんだよね。
	void BattleCardSetUp();

	//ドローフェイズみたいなやつよ。
	void BattleCardStandbyPhase();

	//まずはカードを選択するところからはじまる
	int BattleCardSelect_C_Phase(int *type, int *kind);

	//媒体選択するよ。媒体さんやっほー
	int BattleCardSelect_M_Phase(int *type, int *kind);
	//ｵﾜﾀ
	void BattleCardEndPhase();

	//画像が消えるおまじない
	void ImageDelete();

	//††手札公開††
	void Render();
};

