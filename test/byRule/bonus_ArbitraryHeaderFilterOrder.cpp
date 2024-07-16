#include <gtest/gtest.h>
#include "../inc/libcsv.h"

TEST(Bonus, Arbitrary_header_filter_order)
{
	const char examplePath[] = "test/csvSource/example.csv";
	
	std::string expected("header1,header2,header3\n4,5,6\n\n");

	const char filter[] = "header2>3\nheader1=4";

	testing::internal::CaptureStdout();
	
	processCsvFile(examplePath, "", filter);
	
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_EQ(output, expected);
}
