#include <gtest/gtest.h>
#include "../inc/libcsv.h"

TEST(Bonus, Arbitrary_header_select_order)
{
	const char examplePath[] = "test/csvSource/example.csv";
	
	std::string expected("header1,header2,header3\n1,2,3\n4,5,6\n7,8,9\n\n");

	const char select[] = "header2,header3,header1";

	testing::internal::CaptureStdout();
	
	processCsvFile(examplePath, select, "");
	
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_EQ(output, expected);
}
