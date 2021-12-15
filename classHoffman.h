#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Hoffman
{
private:
	bool key = true;
	std::string text;
	std::pair<char, int> p;
	std::vector<std::pair<char, int>> vec;
	std::vector < std::pair<char, std::vector<int>>> bynar;
	std::pair<char, std::vector<int>> pBynar;
	char symbol;
	int count = 1;
	int sum = 0;
	bool  key1 = 1;
public:
	std::string getText();
	void setText();
	std::vector<std::pair<char, int>>& countSymbol(std::string);
	void bynarVector(std::vector<std::pair<char, int>> ,int);
	void show();
};
