#pragma once
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Include.h"

/************************************************************************
//	カードデータの読み込み関連はこちら。
//	要望、ご相談はこちらまで。
//
//	（株）湯川コーポレーション
************************************************************************/
class DataCard
{
public:

	typedef struct _CardData
	{
		std::string m_sName;
		int m_sId;
		int m_sType;
		int m_sKind;
		std::string m_sGrHand;
	}SCardData;


	std::vector<std::string>vdata;
	std::vector<SCardData>vCardData;

	unsigned int num;
	int i;
	const char* filePath;

public:
	DataCard();
	~DataCard();

	bool CardCSVReading(const char* filename);

	int GetIDdata(int i){ return vCardData[i].m_sId; }
	int GetTypedata(int i){ return vCardData[i].m_sType; }
	int GetAttributedata(int i){ return vCardData[i].m_sKind; }
	std::string GetNamedata(int i){ return vCardData[i].m_sName; }
	std::string GetGrHanddata(int i){ return vCardData[i].m_sGrHand; }

	int GetCSVLineData(){ return num; }

	void CSVAdd(std::string filename, std::string id, std::string type, std::string kind,
		std::string name, std::string GrHand);
	void CSVDel(const char* filename, std::string name);

	void CSVSort_asc_ID();
	void CSVSort_desc_ID();

	void CSVSort_asc_Type();
	void CSVSort_desc_Type();

	void CSVSort_asc_Attribute();
	void CSVSort_desc_Attribute();

	void CSVSort_asc_Name();
	void CSVSort_desc_Name();

	void CSVSortCUpdate();


	std::vector<SCardData>m_vDeckList;

	void DeckDataSetUp();

};