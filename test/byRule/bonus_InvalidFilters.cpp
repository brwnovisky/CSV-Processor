#include <gtest/gtest.h>
#include "../inc/libcsv.h"

TEST(Bonus, Invalid_filters)
{
	const char examplePath[] = "test/csvSource/example.csv";
	
	std::string expected("Invalid filter: 'header1#2'\n");

	const char filter[] = "header1#2";

	testing::internal::CaptureStderr();
	
	processCsvFile(examplePath,"", filter);
	
	std::string output = testing::internal::GetCapturedStderr();

	ASSERT_EQ(output, expected);
}
