#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <regex>
using namespace std;
class VATParser
{
public:
	VATParser();
	~VATParser();
	void parseVatString();
	int blockNumber()const;
	std::string country()const;
	std::vector<std::string> digits()const;
	friend istream & operator >> (istream &in, VATParser &c);
private:
	std::vector<std::string> m_digits;
	std::string m_country{""};
	std::string m_rawString;
	std::vector<std::string> list;
	int m_blockNumber{ 0 };
	void parse(std::string str);
	bool m_isCountryFound{ false };
};