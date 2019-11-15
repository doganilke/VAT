#include "VATParser.h"

istream & operator >> (istream &in, VATParser &c)
{
	//in >> c.m_rawString;
	std::getline(in, c.m_rawString);
	std::string temp;
	for (std::string::size_type i = 0; i < c.m_rawString.size();)
	{
		while (c.m_rawString[i] != ' ' && i < c.m_rawString.size())
		{
			temp += c.m_rawString[i];
			++i;
		}
		++i;
		c.list.push_back(temp);
		temp.clear();
	}
	
	c.m_blockNumber = c.list.size();
	return in;
}

VATParser::VATParser()
{

}

VATParser::~VATParser()
{

}

void VATParser::parseVatString()
{
	for(auto r : list)
		parse(r);
}

int VATParser::blockNumber()const
{
	return m_blockNumber;
}

std::string VATParser::country()const
{
	return m_country;
}


std::vector<std::string> VATParser::digits()const 
{
	return m_digits;
}

void VATParser::parse(std::string str)
{
	regex m_isDigitRegex("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?");
	regex m_isStringRegex("[a-zA-Z]");

	std::smatch m;
	std::string str2 = str.substr(0,3);
	while (regex_search(str, m, m_isDigitRegex))
	{
			m_digits.push_back(m[1]);
			str = m.suffix().str(); // Proceed to the next match
	}

	if (!m_isCountryFound)
	{
		while (regex_search(str2, m, m_isStringRegex)) {
			m_country += m[0];
			str2 = m.suffix().str(); // Proceed to the next match
			m_isCountryFound = true;
		}
	}
	
}