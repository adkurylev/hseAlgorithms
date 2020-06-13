#include <iostream>
#include <fstream>
#include <vector>

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
	int n;
	std::fstream fin;
	fin.open("input.txt", std::ios::in);
	if (fin.is_open())
	{
		fin >> n;
		Triple** triples = new Triple*[n];

		for (int i = 0; i < n; ++i)
		{
			int o, l;
			char ch;

			fin >> o >> l >> ch;

			triples[i] = new Triple(o, l, ch);
		}

		fin.close();

		std::fstream fout;
		fout.open("output.txt", std::ios::out);
		std::vector<char> out;
		int carriage = 0;

		for (int i = 0; i < n; ++i)
		{
			if (triples[i]->offset == 0)
			{
				out.push_back(triples[i]->ch);
				++carriage;
			} 
			else 
			{
				carriage -= triples[i]->offset;
				for (int j = 0; j < triples[i]->length; ++j)
					out.push_back(out[carriage++]);
				out.push_back(triples[i]->ch);
				carriage = out.size();
			}
		}

		for (int i = 0; i < out.size(); ++i)
			fout << out[i];

		fout.close();

		for (int i = 0; i < n; ++i)
			delete triples[i];

		delete[] triples;
	}

	return 0;
}