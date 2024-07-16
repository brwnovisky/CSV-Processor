#include "../../inc/CsvTable.hpp"

const std::string CsvTable::subTable(const std::string rawSelection, 
								 	 const std::string rawFiltering) const
{
	std::stringstream subCsvTable;

	TokSet selection = tokenizerSet(rawSelection, ",");
	
	TokVec filtering = tokenizerVec(rawFiltering, "\n");

	subCsvTable << extractHeaders(selection) 
				<< extractData(filtering, selection);

	return subCsvTable.str();
}

const std::string CsvTable::extractHeaders(TokSet rawHeaders) const
{
	std::stringstream csvHeaders;

	bool hasSelection = !(rawHeaders.empty());

	for (const std::string& header : this->headers)
	{	
		if (hasSelection)
		{
			if (!rawHeaders.count(header))
			{
				continue;
			}
				
			rawHeaders.erase(header);
		}

		csvHeaders << header;

		if (header != *(this->headers.rbegin()))
		{
			if (hasSelection && rawHeaders.empty())
			{
				continue;
			}
				
			csvHeaders << ',';
		}
	}

	if (!rawHeaders.empty())
	{
		throw std::logic_error("Header '" + *rawHeaders.begin() + 
							   "' not found in CSV file/string");
	}

	csvHeaders << '\n';

	return csvHeaders.str();
}

const std::string CsvTable::extractData(TokVec& filtering, TokSet& selection) const
{
	std::stringstream csvData;

	for (size_t indexColumn = DEFAULT_INDEX; 
		 indexColumn < this->columnSize; 
		 indexColumn++)
	{
		const std::string* registry = this->data[indexColumn];
		
		if(!filter(filtering, registry))
		{
			continue;
		}

		csvData << select(selection, registry);
	}

	return csvData.str();
}
