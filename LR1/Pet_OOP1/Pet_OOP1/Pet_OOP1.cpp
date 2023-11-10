#include <iostream>
#include <string>
#include <clocale>
#include <cstdlib>
#include <Windows.h>
#include <stdlib.h>
#include <fstream>
#include "Header.h"

using std::ofstream;
using std::ifstream;
using std::cout;

using std::string;
using std::right;
using std::to_string;
using std::endl;
using std::getline;
using std::cin;
using std::fixed;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char variant;
	ifstream fin;
	string path = "myFile.txt";
	fin.open(path);
	bool flag = false;

	while (1)
	{
		variantMenu();
		cin >> variant; cin.ignore();
	    
		cout << endl;

		switch (variant)
		{
		  case '1':
		{
			  if (!fin.is_open())
			  {
				  cout << "Error open\n";
			  }
			  else
			  {
				  char ch;
				  if (!fin.get(ch))
				  {
					  if (flag == false)
					  {
						  cout << "База данных пустая. Введите базу данных\n";
						  writeOnFile_Empty();
						  flag = true;
					  }
					  else
					  {
						  writeOnFile_NotEmpty();
					  }
				  }
				  else
				  {
					  writeOnFile_NotEmpty();
				  }
			  }
			
			break;
		}
		  case '2':
		{
			printmenu();
			printFromFile();
			break;
		}
		  case '3':
		{
			searchProduct();
			break;
		}
		  case '4':
		{

			break;
		}
		  case '5':
		{
			//delMatrix();
			return 0;
			break;
		}
		  default:
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "!! Выберите правильную опцию !!" << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
			break;



		}




	}


	return 0;
}


