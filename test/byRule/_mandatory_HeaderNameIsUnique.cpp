#include <gtest/gtest.h>
#include "../inc/libcsv.h"

TEST(Mandatory, Header_name_is_Unique)
{
	const char examplePath[] = "test/csvSource/headerDuplicate.csv";
	
	std::string expected("The CSV file/string has duplicate headers\n");

	testing::internal::CaptureStderr();
	
	processCsvFile(examplePath, "", "");
	
	std::string output = testing::internal::GetCapturedStderr();

	ASSERT_EQ(output, expected);
}
