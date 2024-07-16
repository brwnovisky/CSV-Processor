#include "../../inc/CsvTable.hpp"

const Filter CsvTable::setFilter(const std::string& rawFilter) const
{
	TokVec tokens;

	for (const Comparison& comparison : this->comparisons)
	{
		if (rawFilter.find(comparison.first) != std::string::npos)
		{
			const TokVec tokens = tokenizerVec(rawFilter, comparison.first);
		
			const std::string header = tokens[HEADER_INDEX];

			auto it = std::find(this->headers.begin(), 
								this->headers.end(), header);

			if (it == this->headers.end())
			{
				throw std::logic_error("Header '" + header + 
									   "' not found in CSV file/string");
			}
			
			const Operator& operation = comparison.second;
			
			const std::string& parameter = tokens[PARAMETER_INDEX];  

			return Filter(header, operation, parameter);
		}
	}

	throw std::logic_error("Invalid filter: '" + rawFilter + "'");
}

bool CsvTable::filter(TokVec& filtering, const std::string* registry) const
{
	std::pair<Filter, bool> last(Filter(), true);
	
	bool matchFilter = true;

	for (const std::string& rawfilter : filtering)
	{
		const Filter filter = setFilter(rawfilter);

		auto it = std::find(this->headers.begin(), 
							this->headers.end(), filter.header);

		const size_t valueIndex = std::distance(this->headers.begin(), it);
		
		const std::string dataValue = registry[valueIndex];

		matchFilter = filter.operation(dataValue, filter.parameter); 
		
		if (last.second == false)
		{
			if (last.first.header != filter.header)
			{
				return false;
			}
		}

		last.first = filter;
		last.second = matchFilter;
	}

	return matchFilter;
}
