#include "classHoffman.h"

std::string Hoffman::getText()
{
	return text;
}
void Hoffman::setText()
{
	std::cout << "Enter please text \n";
	getline(std::cin, text);
}
std::vector<std::pair<char, int>>& Hoffman::countSymbol(std::string text)
{
	for (int i = 0; i < text.size(); ++i)
	{
		for (int k = i - 1; k >= 0; k--)
		{
			if (text[i] == text[k])
			{
				key = false;
			}
		}
		for (int j = i + 1; j < text.size(); ++j)
		{
			if (i)
			{ 
				if (key)
				{
					if (text[i] == text[j])
					{
						count++;
						symbol = text[i];
					}
				}
			}
			else
			{
				if (text[i] == text[j])
				{
					count++;
					symbol = text[i];

				}

			}
		}

		if (count == 1 && key)
		{
			symbol = text[i];
			p.first = symbol;
			p.second = count;
			vec.push_back(p);

		}
		else if (key)
		{
			symbol = text[i];
			p.first = symbol;
			p.second = count;
			vec.push_back(p);
		}
		count = 1;
		key = true;
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = 0; j < vec.size(); ++j)
		{
			if (vec[j].second > vec[i].second)
			{
				std::swap(vec[i], vec[j]);
			}
		}
	}
	return vec;
}
void Hoffman::bynarVector(std::vector<std::pair<char, int>> vec1,int size)
{
	if (key1)
	{
		pBynar.first = vec[0].first;
		for (int i = 0; i < size - 1; ++i) 
		{
			pBynar.second.push_back(0);
		}
		std::cout << std::endl;
		bynar.push_back(pBynar);
		pBynar.second.clear();
		key1 = false;
		bynarVector(vec,size);
	}
	else if(vec.size() >= 0)
	{
		int i = 1;
		while (i < vec.size())
		{ 
			pBynar.second.push_back(1);
			pBynar.first = vec[i].first;
			for (int j = 0; j < size-2; ++j)
			{
				pBynar.second.push_back(0);
			}
			bynar.push_back(pBynar);
			size--;
			i++;
			std::cout << std::endl;
			pBynar.second.clear();
		}
	}
}
void Hoffman::show()
{
	for (int i = 0; i < bynar.size(); ++i)
	{
		std::cout << bynar[i].first << " = ";
		for (int j = 0; j < bynar[i].second.size(); ++j)
		{
			std::cout << bynar[i].second[j];
		}
		std::cout << std::endl;
	}
}
