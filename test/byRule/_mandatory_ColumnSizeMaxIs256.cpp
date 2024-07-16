#include <gtest/gtest.h>
#include "../inc/libcsv.h"

TEST(Mandatory, Column_size_max_is_256)
{
	const char examplePath[] = "test/csvSource/columnSize257.csv";
	
	std::string expected("The CSV file/string has more than 256 columns\n");


	testing::internal::CaptureStderr();
	
	processCsvFile(examplePath, "", "");
	
	std::string output = testing::internal::GetCapturedStderr();

	ASSERT_EQ(output, expected);
}
