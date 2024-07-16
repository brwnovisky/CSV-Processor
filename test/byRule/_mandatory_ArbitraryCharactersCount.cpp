#include <gtest/gtest.h>
#include "../inc/libcsv.h"

TEST(Mandatory, Arbitrary_characters_count)
{
	const char arbitraryCharactersCountPath[] = "test/csvSource/arbitraryCharactersCount.csv";
	
	std::string expected("headerrrrrrrrrr,header,headerrrrrrrrrrrrrrrrrrrrrrrr\n1111,2222222222222222,33\n44444444,5,6666666666666666666666\n7777777,88888888,999\n\n");

	testing::internal::CaptureStdout();
	
	processCsvFile(arbitraryCharactersCountPath, "", "");
	
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_EQ(output, expected);
}
