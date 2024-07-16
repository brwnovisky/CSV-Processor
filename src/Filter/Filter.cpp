#include "../../inc/Filter.hpp"

Filter::~Filter(void) {}

Filter::Filter(void) {}

Filter::Filter(const std::string& header, 
			   const Operator& operation, 
			   const std::string& parameter) : header(header), 
			  								   operation(operation), 
											   parameter(parameter) {}

Filter& Filter::operator=(const Filter &rightHand)
{
	this->header = rightHand.header;
	this->operation = rightHand.operation;
	this->parameter = rightHand.parameter;

	return *this;
}
