#ifndef UTILITY_HPP
# define UTILITY_HPP

# include <vector>
# include <regex>
# include <algorithm>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <set>

#define CSV_REGEX_PATTERN	R"(^.*\.csv$)"

typedef std::set<std::string> TokSet;

typedef std::vector<std::string> TokVec;

/**
 * Split a string content by a separator.
 *
 * @param rawContent The content to split.
 * @param separator The separator pattern.
 *
 * @return TokSet: set of tokens.
 */
TokSet tokenizerSet(const std::string &rawContent, 
					const std::string &separator);

/**
 * Split a string content by a separator.
 *
 * @param rawContent The content to split.
 * @param separator The separator pattern.
 *
 * @return TokVec: vector of tokens.
 */
TokVec tokenizerVec(const std::string &rawContent, 
					const std::string &separator);

/**
 * Extract entire content of a file.
 *
 * @param path The path of the file to extract.
 *
 * @return std::string: file content.
 */
std::string extractFile(const std::string path);

/**
 * Remove all empty strings of a vector.
 *
 * @param rawData The vector of strings.
 *
 * @return void
 */
void cleanEmptyStrings(TokVec& rawData);

/**
 * Verify if a string is path of a .csv file.
 *
 * @param rawData The string content.
 *
 * @return bool: true if the string is a .csv file.
 */
bool isCsvFilePath(const std::string& filePath);

#endif // UTILITY_HPP