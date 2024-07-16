#ifndef CSVTABLE_HPP
#define CSVTABLE_HPP

#include <vector>
#include <map>
#include <set>
#include <string>

#include "utility.hpp"
#include "Filter.hpp"

#define DEFAULT_INDEX	0
#define HEADER_INDEX	0
#define PARAMETER_INDEX	1
#define COLUMNS_LIMIT	256

typedef std::pair<std::string, Operator> Comparison;

class	CsvTable
{
	public:
		
		~CsvTable(void);
		CsvTable(const std::string csv);
		
		const std::string subTable(const std::string rawSelection,
							 	   const std::string rawFiltering) const;
	private:
		
		void setupHeaders(const std::string& rawHeaders);
		void setupData(const TokVec& rawData);
		void loadComparison(void);

		const std::string extractHeaders(TokSet selection)  const;		
		
		const std::string extractData(TokVec& filtering, 
									  TokSet& selection) const;		
		
		const std::string select(TokSet selection, 
								 const std::string* registry) const;
		
		bool filter(TokVec &filtering, 
					const std::string* registry) const;

		const Filter setFilter(const std::string& filter) const;
				
		const size_t columnSize; 
		std::string** data;
		std::vector<std::string> headers;
		std::vector<std::pair<std::string, Operator>> comparisons;
};

std::ostream& operator<<(std::ostream& ouputStream, const CsvTable& rightHand);

#endif // CSVTABLE_HPP
