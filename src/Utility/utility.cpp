#include "../../inc/utility.hpp"

TokSet tokenizerSet(const std::string &rawContent, 
				    const std::string &separator) 
{
    TokSet tokens;
    std::string::size_type start = 0;
    std::string::size_type end;

	if (rawContent.size() < 1)
	{
		return tokens;
	}

    while ((end = rawContent.find(separator, start)) != std::string::npos) 
	{
        tokens.insert(rawContent.substr(start, end - start));
        start = end + separator.length();
    }

    tokens.insert(rawContent.substr(start));

    return tokens;
}

TokVec tokenizerVec(const std::string &rawContent, 
					const std::string &separator) 
{
    TokVec tokens;
    std::string::size_type start = 0;
    std::string::size_type end;

	if (rawContent.size() < 1)
	{
		return tokens;
	}

    while ((end = rawContent.find(separator, start)) != std::string::npos) 
	{
        tokens.push_back(rawContent.substr(start, end - start));
        start = end + separator.length();
    }

    tokens.push_back(rawContent.substr(start));

    return tokens;
}

std::string extractFile(const std::string path)
{
	std::ifstream		file(path);
  	std::stringstream	buffer;

  	if (!file.is_open()) 
  	{	
		throw std::runtime_error("Error opening file: " + std::string(path));
  	} 
  
	buffer << file.rdbuf();
	file.close();
	
	return buffer.str();
}

void cleanEmptyStrings(TokVec& rawData)
{
    rawData.erase(std::remove_if(rawData.begin(), 
								 rawData.end(), 
								 [](const std::string& s) 
								 { 
									return s.empty(); 
								 }),
        		  rawData.end());
}

bool isCsvFilePath(const std::string& filePath)
{
    const std::regex csvPattern(CSV_REGEX_PATTERN, std::regex::icase);

    return std::regex_match(filePath, csvPattern);
}
