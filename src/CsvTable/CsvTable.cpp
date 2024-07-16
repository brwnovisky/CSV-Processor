#include "../../inc/CsvTable.hpp"

CsvTable::~CsvTable()
{
	for (size_t indexColumn = DEFAULT_INDEX; 
		 indexColumn < this->columnSize; 
		 indexColumn++)
	{
		delete[] this->data[indexColumn];
	}

	delete[] this->data;

}

CsvTable::CsvTable(const std::string csv) : columnSize(0), 
											data(NULL)
{
	std::string rawCsvData(csv);

	if (isCsvFilePath(rawCsvData))
	{
		rawCsvData = extractFile(csv);
	}

	TokVec csvTok = tokenizerVec(rawCsvData, "\n");

	cleanEmptyStrings(csvTok);

	const_cast<size_t&>(this->columnSize) = csvTok.size() - 1;

	setupHeaders(csvTok[HEADER_INDEX]);

	csvTok.erase(csvTok.begin());

	setupData(csvTok);

	loadComparison();
}
