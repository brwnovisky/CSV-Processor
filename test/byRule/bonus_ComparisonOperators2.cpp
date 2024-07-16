#include <gtest/gtest.h>
#include "../inc/libcsv.h"

TEST(Bonus, Greater_or_equal_operator)
{
	const char examplePath[] = "test/csvSource/example.csv";
	
	const char greaterEqualFilter[] = "header2>=5";
	
	std::string expected("header1,header2,header3\n4,5,6\n7,8,9\n\n");


	testing::internal::CaptureStdout();
	
	processCsvFile(examplePath, "", greaterEqualFilter);
	
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_EQ(output, expected);
}

TEST(Bonus, Less_or_equal_operator)
{
	const char examplePath[] = "test/csvSource/example.csv";
	
	const char lessOrEqualFilter[] = "header3<=6";
	
	std::string expected("header1,header2,header3\n1,2,3\n4,5,6\n\n");


	testing::internal::CaptureStdout();
	
	processCsvFile(examplePath, "", lessOrEqualFilter);
	
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_EQ(output, expected);
}

TEST(Bonus, Not_equal_operator)
{
	const char examplePath[] = "test/csvSource/example.csv";
	
	const char notEqualFilter[] = "header1!=2";
	
	std::string expected("header1,header2,header3\n1,2,3\n4,5,6\n7,8,9\n\n");


	testing::internal::CaptureStdout();
	
	processCsvFile(examplePath, "", notEqualFilter);
	
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_EQ(output, expected);
}
