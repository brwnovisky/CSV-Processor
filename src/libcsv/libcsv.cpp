#include <iostream>
#include <string>

# include "../../inc/libcsv.h"
# include "../../inc/utility.hpp"
# include "../../inc/CsvTable.hpp"

#define HEADER_INDEX	0

void processCsv(const char csv[], 
				const char selectedColumns[], 
				const char rowFilterDefinitions[])
{
	try
	{
		CsvTable table(csv);

		const std::string subTable = table.subTable(selectedColumns, 
												    rowFilterDefinitions);

		std::cout << subTable << std::endl;
	}	
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void processCsvFile(const char csvFilePath[], 
					const char selectedColumns[], 
					const char rowFilterDefinitions[])
{	
	return processCsv(csvFilePath, selectedColumns, rowFilterDefinitions);
}
