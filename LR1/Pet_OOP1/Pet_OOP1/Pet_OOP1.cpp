#include <iostream>
#include <string>
#include <clocale>
#include <cstdlib>
#include <Windows.h>
#include "Header.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int variant;
	variantMenu();
	cin >> variant;
	while (1)
	{
		if (variant == 1)
		{
			cout<< endl;
			fillProduct();
		}

		else if (variant == 2)
		{
			cout << endl;
			printmenu();
			printBazaData();
			cout<< endl;
		}

		else if (variant == 3)
		{
			//delMatrix();
			break;
		}
		else
		{
			cout<< "Выберите нужную опцию!\n";
		}

		variantMenu();
		cin >> variant;

	}



}


