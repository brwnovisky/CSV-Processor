#include "../../inc/CsvTable.hpp"

void CsvTable::setupHeaders(const std::string &rawHeaders)
{
	this->headers = tokenizerVec(rawHeaders, ",");

	const size_t headerSize = this->headers.size();

	if (headerSize > COLUMNS_LIMIT)
	{
		std::stringstream error;

		error << "The CSV file/string has more than " 
			  << COLUMNS_LIMIT 
			  << " columns";

		throw std::logic_error(error.str());
	}
	
	if (headerSize != tokenizerSet(rawHeaders, ",").size())
	{
		throw std::logic_error("The CSV file/string has duplicate headers");
	}
}

void CsvTable::setupData(const TokVec& rawData)
{
	this->data = new std::string*[rawData.size()];

	size_t indexLine = 0;

	for (const std::string& registry : rawData)
	{
		TokVec tokens = tokenizerVec(registry, ",");
		
		this->data[indexLine] = new std::string[tokens.size()];

		size_t indexCollumn = 0;

		for (const std::string& token : tokens)
		{
			this->data[indexLine][indexCollumn] = token;

			indexCollumn++;
		}

		indexLine++;
	}
}
