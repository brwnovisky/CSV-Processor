#include <gtest/gtest.h>
#include "../inc/libcsv.h"

TEST(Mandatory, Greater_operator)
{
	const char examplePath[] = "test/csvSource/example.csv";
	
	const char select[] = "header1,header3";

	const char greaterThanfilter[] = "header2>4,header3>2";
	
	std::string expected("header1,header3\n4,6\n7,9\n\n");


	testing::internal::CaptureStdout();
	
	processCsvFile(examplePath, select, greaterThanfilter);
	
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_EQ(output, expected);
}

TEST(Mandatory, Less_operator)
{
	const char examplePath[] = "test/csvSource/example.csv";
	
	const char select[] = "header2,header3";

	const char lessThanfilter[] = "header1<4\nheader3<8";
	
	std::string expected("header2,header3\n2,3\n\n");


	testing::internal::CaptureStdout();
	
	processCsvFile(examplePath, select, lessThanfilter);
	
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_EQ(output, expected);
}

TEST(Mandatory, Equal_operator)
{
	const char examplePath[] = "test/csvSource/example.csv";
	
	const char select[] = "header1,header2";

	const char equalThanfilter[] = "header2=2\nheader3=3";
	
	std::string expected("header1,header2\n1,2\n\n");


	testing::internal::CaptureStdout();
	
	processCsvFile(examplePath, select, equalThanfilter);
	
	std::string output = testing::internal::GetCapturedStdout();

	ASSERT_EQ(output, expected);
}
