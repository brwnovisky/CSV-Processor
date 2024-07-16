#include <gtest/gtest.h>
#include "../inc/libcsv.h"

TEST(Mandatory, First_line_always_be_Headers)
{
	const char headerShufflePath[] = "test/csvSource/headerShuffle.csv";
	
	std::string expected("9,header2,5\n1,2,3\n4,header5,6\n7,8,header9\n\n");

	
	testing::internal::CaptureStdout();
	
	processCsvFile(headerShufflePath, "", "");
	
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_EQ(output, expected);
}
