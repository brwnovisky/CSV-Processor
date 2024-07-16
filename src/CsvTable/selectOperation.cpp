#include "../../inc/CsvTable.hpp"

const std::string CsvTable::select(TokSet selection, 
								   const std::string* registry) const
{
	std::stringstream csvRegistry;

	bool hasSelection = !(selection.empty());
	
	size_t index = DEFAULT_INDEX;

	for (const std::string& header : this->headers)
	{	
		if (hasSelection && !selection.count(header))
		{
			index++;
			continue;
		}
		
		selection.erase(header);

		csvRegistry << registry[index];

		if (header != *(this->headers.rbegin()))
		{
			if (hasSelection && selection.empty())
			{
				continue;
			}
				
			csvRegistry << ',';
		}

		index++;
	}

	csvRegistry << '\n';

	return csvRegistry.str();
}
