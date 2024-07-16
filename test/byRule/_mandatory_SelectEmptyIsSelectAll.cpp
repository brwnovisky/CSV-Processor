#include <gtest/gtest.h>
#include "../inc/libcsv.h"

TEST(Mandatory, Select_empty_is_select_all)
{
	const char examplePath[] = "test/csvSource/example.csv";
	
	std::string expected("header1,header2,header3\n1,2,3\n4,5,6\n7,8,9\n\n");


	testing::internal::CaptureStdout();
	
	processCsvFile(examplePath, "", "");
	
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_EQ(output, expected);
}
