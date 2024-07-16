#include "../../inc/CsvTable.hpp"

static bool greater(const std::string &dataValue, const std::string &parameter)
{
	const int valueDifference = dataValue.compare(parameter);

	if (valueDifference > 0)
	{
		return true;
	}

	return false;
}

static bool less(const std::string &dataValue, const std::string &parameter)
{
	const int valueDifference = dataValue.compare(parameter);

	if(valueDifference < 0)
	{
		return true;
	}

	return false;
}

static bool equal(const std::string &dataValue, const std::string &parameter)
{
	const int valueDifference = dataValue.compare(parameter);

	if (valueDifference == 0)
	{
		return true;
	}

	return false;
}

static bool notEqual(const std::string &dataValue, const std::string &parameter)
{
	return !equal(dataValue, parameter);
}

static bool greaterEqual(const std::string &dataValue, 
						 const std::string &parameter)
{
	return (greater(dataValue, parameter) || equal(dataValue, parameter));
}

static bool lessEqual(const std::string &dataValue, 
					  const std::string &parameter)
{
	return (less(dataValue, parameter) || equal(dataValue, parameter));
}

void CsvTable::loadComparison(void)
{
	this->comparisons.push_back(std::pair<std::string, Operator>("!=", 
																 notEqual));
	this->comparisons.push_back(std::pair<std::string, Operator>(">=", 
																 greaterEqual));
	this->comparisons.push_back(std::pair<std::string, Operator>("<=", 
																 lessEqual));
	this->comparisons.push_back(std::pair<std::string, Operator>(">", greater));
	this->comparisons.push_back(std::pair<std::string, Operator>("<", less));
	this->comparisons.push_back(std::pair<std::string, Operator>("=", equal));
}
