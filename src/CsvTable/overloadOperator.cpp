#include "../../inc/CsvTable.hpp"

std::ostream &operator<<(std::ostream &ouputStream, const CsvTable &rightHand)
{
	ouputStream << rightHand.subTable("", "") << std::endl;

	return ouputStream;
}
