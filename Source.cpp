#include "functionHoffman.h"
int main()
{
	Hoffman hof;
	std::string text_m;
	std::vector<std::pair<char, int>> p_m;
	hof.setText();
	text_m = hof.getText();
	p_m = hof.countSymbol(text_m);
	hof.bynarVector(p_m,p_m.size());
	hof.show();
}
