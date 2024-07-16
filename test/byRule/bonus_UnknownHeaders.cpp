#include <gtest/gtest.h>
#include "../inc/libcsv.h"

TEST(Bonus, Unknown_select_headers)
{
	const char examplePath[] = "test/csvSource/example.csv";
	
	std::string expected("Header 'header99' not found in CSV file/string\n");

	const char select[] = "header99,header3,header1";

	testing::internal::CaptureStderr();
	
	processCsvFile(examplePath, select, "");
	
	std::string output = testing::internal::GetCapturedStderr();

	ASSERT_EQ(output, expected);
}

TEST(Bonus, Unknown_filter_headers)
{
	const char examplePath[] = "test/csvSource/example.csv";
	
	std::string expected("Header 'header99' not found in CSV file/string\n");

	const char filter[] = "header99>1\nheader3>99\nheader1=100";

	testing::internal::CaptureStderr();
	
	processCsvFile(examplePath,"", filter);
	
	std::string output = testing::internal::GetCapturedStderr();

	ASSERT_EQ(output, expected);
}
