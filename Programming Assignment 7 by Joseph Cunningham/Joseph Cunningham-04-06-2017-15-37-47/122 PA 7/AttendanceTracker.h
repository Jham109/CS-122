#pragma once

#include <ctime>

#include "List.h"

class Menu
{
public:
	Menu();
	~Menu();


	void import();
	void loadList();
	void storeList();
	void markAbsences();
	void generateReport();
	void editAbsences();

private:
	fstream fstr;
	fstream mstr;
	List mList;
};