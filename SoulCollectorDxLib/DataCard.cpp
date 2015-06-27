#include "DataCard.h"

DataCard::DataCard()
{
}


DataCard::~DataCard()
{
}

bool DataCard::CardCSVReading(const char* filename)
{
	std::ifstream file;
	file.open(filename);
	filePath = filename;
	if (!file)
	{
		return false;
	}

	std::string csvLine;
	std::string csvCol;

	i = 0;
	num = 0;

	while (std::getline(file, csvLine)){
		std::stringstream csvStream(csvLine);

		num += 1;

		while (std::getline(csvStream, csvCol, ',')){
			vdata.push_back(csvCol);
		}

		vCardData.resize(num);
		vCardData[i].m_sId = std::atoi(vdata[0].c_str());
		vCardData[i].m_sType = std::atoi(vdata[1].c_str());
		vCardData[i].m_sKind = std::atoi(vdata[2].c_str());
		vCardData[i].m_sName = vdata[3];
		vCardData[i].m_sGrHand = vdata[4];

		++i;
		vdata.clear();
	}

	file.close();
	return true;
}

void DataCard::CSVSort_asc_ID()
{
	std::sort(vCardData.begin(), vCardData.end(), [](const SCardData& x, const SCardData& y){return x.m_sId < y.m_sId; });
	CSVSortCUpdate();
}

void DataCard::CSVSort_desc_ID()
{
	std::sort(vCardData.begin(), vCardData.end(), [](const SCardData& x, const SCardData& y){return x.m_sId > y.m_sId; });
	CSVSortCUpdate();
}

void DataCard::CSVSort_asc_Type()
{
	std::sort(vCardData.begin(), vCardData.end(), [](const SCardData& x, const SCardData& y){return x.m_sType < y.m_sType; });
	CSVSortCUpdate();
}

void DataCard::CSVSort_desc_Type()
{
	std::sort(vCardData.begin(), vCardData.end(), [](const SCardData& x, const SCardData& y){return x.m_sType > y.m_sType; });
	CSVSortCUpdate();
}

void DataCard::CSVSort_asc_Attribute()
{
	std::sort(vCardData.begin(), vCardData.end(), [](const SCardData& x, const SCardData& y){return x.m_sKind < y.m_sKind; });
	CSVSortCUpdate();
}

void DataCard::CSVSort_desc_Attribute()
{
	std::sort(vCardData.begin(), vCardData.end(), [](const SCardData& x, const SCardData& y){return x.m_sKind > y.m_sKind; });
	CSVSortCUpdate();
}

void DataCard::CSVSort_asc_Name()
{
	std::sort(vCardData.begin(), vCardData.end(), [](const SCardData& x, const SCardData& y){return x.m_sName < y.m_sName; });
	CSVSortCUpdate();
}

void DataCard::CSVSort_desc_Name()
{
	std::sort(vCardData.begin(), vCardData.end(), [](const SCardData& x, const SCardData& y){return x.m_sName > y.m_sName; });
	CSVSortCUpdate();
}

void DataCard::CSVSortCUpdate()
{

	std::ofstream offile;
	offile.open(filePath);

	int j = 0;

	for (std::vector<SCardData>::const_iterator i = vCardData.begin(); i != vCardData.end(); i++){
		offile << vCardData[j].m_sId << ","
			<< vCardData[j].m_sType << ","
			<< vCardData[j].m_sKind << ","
			<< vCardData[j].m_sName << ","
			<< vCardData[j].m_sGrHand << ","
			<< std::endl;

		++j;
	}
}

void DataCard::DeckDataSetUp()
{
	CardCSVReading("Asset/CSV/Card/decklist.csv");
	m_vDeckList.resize(GetCSVLineData());

	for (int i = 0; i < GetCSVLineData(); i++){
		m_vDeckList[i].m_sId = GetIDdata(i);
		m_vDeckList[i].m_sType = GetTypedata(i);
		m_vDeckList[i].m_sKind = GetAttributedata(i);
		m_vDeckList[i].m_sName = GetNamedata(i);
		m_vDeckList[i].m_sGrHand = GetGrHanddata(i);
	}
}