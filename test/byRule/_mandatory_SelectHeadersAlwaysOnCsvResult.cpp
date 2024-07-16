#include <gtest/gtest.h>
#include "../inc/libcsv.h"

TEST(Mandatory, Select_headers_always_on_csv_result)
{
	const char examplePath[] = "test/csvSource/example.csv";
	
	const char normalSelect[] = "header1,header3";

	std::string expected("header1,header3\n1,3\n4,6\n7,9\n\n");


	testing::internal::CaptureStdout();
	
	processCsvFile(examplePath, normalSelect, "");
	
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_EQ(output, expected);
}
