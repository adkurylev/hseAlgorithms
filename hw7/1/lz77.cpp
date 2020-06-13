#include <iostream>
#include <fstream>
#include <stdlib.h>

class Triple
{
public:
	int offset;
	int length;
	char ch;

public:
	Triple(int o, int l, char c) : 
		offset(o),
		length(l),
		ch(c) 
	{}
};

int main()
{
	std::fstream fin;
	fin.open("input.txt", std::ios::in);
	std::string str;

	if (!fin.is_open())
		exit (EXIT_FAILURE);
		
	std::getline(fin, str);
	fin.close();

	return 0;
}