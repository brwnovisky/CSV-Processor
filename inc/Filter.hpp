#ifndef FILTER_HPP
#define FILTER_HPP

#include <string>

#include "utility.hpp"

typedef bool (*Operator)(const std::string&, const std::string&);

struct Filter
{
	~Filter(void);
	Filter(void);
	Filter
	(
		const std::string& header, 
		const Operator& operation, 
		const std::string& parameter
	);

	Filter& operator=(const Filter& rightHande);

	std::string header;
	Operator operation;
	std::string parameter;
};

#endif // FILTER_HPP
