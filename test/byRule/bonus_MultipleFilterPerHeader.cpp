#include <gtest/gtest.h>
#include "../inc/libcsv.h"

TEST(Bonus, Multiple_filter_per_header)
{
	const char examplePath[] = "test/csvSource/example.csv";
	
	std::string expected("header1,header2,header3\n4,5,6\n\n");

	const char filter[] = "header1=1\nheader1=4\nheader2>3\nheader3>4";

	testing::internal::CaptureStdout();
	
	processCsvFile(examplePath,"", filter);
	
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_EQ(output, expected);
}
