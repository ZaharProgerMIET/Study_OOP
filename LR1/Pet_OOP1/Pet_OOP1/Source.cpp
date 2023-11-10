#include <iostream>
#include <string>
#include <iomanip>
#include <clocale>
#include <cstdlib>
#include <cmath>
#include <Windows.h>
#include <fstream>
#include "Header.h"

using std::ofstream;
using std::ifstream;
using std::cout;
using std::setw;
using std::string;
using std::right;
using std::to_string;
using std::endl;
using std::getline;
using std::cin;
using std::fixed;
using std::setprecision;

string path = "myFile.txt";
int sum = 0;
int const col = 4;
int row = 1;
string** matrix = new string * [row];
int n = 20;
int l = 1;
int numberOfEntries = 0;

class DataBase
{
public:
	string name;
	double quant;
	double cost;

};

void variantMenu()
{
	cout << "Добавить новый элемент в базу данных" << setw(12) << right << "......1\n";
	cout << "Распечатать базу данных" << setw(11) << right << "......2\n";
	cout << "Поиск товара по названию" << setw(10) << right << "......3\n";
	cout << "Фильтр по цене" << setw(20) << right << "......4\n";
	cout << "Выход из программы" << setw(16) << right << "......5\n";
	cout << ".................................\n";
	cout << "Введите номер функции \n";
}


void fillProduct()
{
	for (; l <= row; l++)
	{
		matrix[l] = new string[col];
		
	}
	


	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < (col-1); )
		{ 
			numberOfEntries++;
			DataBase Product;
			cout << "Введите название товара"<< endl;
			string productName;
			getline(cin, productName);
			Product.name = productName;
			matrix[row][j] = Product.name;
			n = n - Product.name.length();
			j++;

			cout << "Введите цену товара\n";
			cin >> Product.cost;
			string strCost = to_string(Product.cost);
			matrix[row][j] = strCost;
			j++;
			
			cout << "Введите количество товара\n";
			cin >> Product.quant;
			string strQuant = to_string(Product.quant);
			matrix[row][j] = strQuant;
			j++;
			sum += Product.cost * Product.quant;
		}

	}
	row++;
	cout << endl;
}

void printmenu()
{
	cout << "Название" << setw(8) << right << "Цена" << setw(14) << right << "Kоличество" << setw(13) << right << "Общая сумма" << endl;
	cout << "Товара" << setw(10) << right << "(руб)" << setw(10) << right << "(кг)" << setw(13) << right << "(руб)" << endl;
	cout << "_____________________________________________\n\n";
}

void printFromFile()
{
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error open\n";
	}
	else
	{
		
		string str;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			cout << str << endl;
		}
	}
	fin.close();
}

//void printBazaData()
//{
//	
//	for (int i = 1; i < row; i++)
//	{
//		for (int j = 0; j < col; )
//		{
//
//			int n = 12;
//			int lenStr = matrix[i][j].length();
//
//			//NAME
//			cout << matrix[i][j] << setw(n);
//			j++;
//
//			// COST
//			cout << fixed;
//			int i_cost = stoi(matrix[i][j]);
//			double d_cost = stof(matrix[i][j]);
//			if (fmod(i_cost, 1) == 0) 
//			{
//				cout << i_cost << setw(n);
//			}
//			else
//			{
//				
//				cout << setprecision(1) << d_cost << setw(n);
//			}
//			j++;
//
//			//QUANT
//			double d_quant = stof(matrix[i][j]);
//			cout  << setprecision(1) << d_quant << setw(n);
//			j++;
//
//			//SUM
//			cout << setprecision(2)<< d_cost * d_quant << endl;
//			j++;
//		}
//		cout << endl;
//
//	}
//	cout << "_____________________________________________\n";
//	cout << "Всего товаров на сумму: " << sum << endl ;
//	cout << "Всего записей в базе " << numberOfEntries << endl << endl << endl;
//}

//void delMatrix()
//{
//	cout << "Вызывался деструктор";
//	if (matrix != nullptr) {
//		for (int i = 1; i < row; i++)
//		{
//			delete[] matrix[i];
//		}
//		delete[] matrix;
//	}
//}


void searchProduct()
{

}

void writeOnFile_Empty()
{
	char variant = '0';
	bool flag = false;
	while (variant != '3')
	{
		if (flag == false)
		{
			fillProduct();
			flag = true;
		}
		variantMenuFile();
		cin >> variant; cin.ignore(); cout << endl;

		switch (variant)
		{
			case '1':
			{
				fillProduct();
				break;
			}
			case '2':
			{
				saveDatabase_isEmty();
				break;
			}
			case '3':
			{
				
				break;
			}
		}

	}
}

void writeOnFile_NotEmpty()
{
	char variant = '0';

	while (variant != '3')
	{
		

		variantMenuFile();
		cin >> variant; cin.ignore(); cout << endl;

		switch (variant)
		{
		case '1':
		{
			fillProduct();
			break;
		}
		case '2':
		{
			saveDatabase_isNotEmty();
			break;
		}
		case '3':
		{

			break;
		}
		}

	}
}


void variantMenuFile()
{
	cout << "Добавить новый элемент в базу данных" << setw(12) << right << "......1\n";
	cout << "Сохранить базу данных" << setw(11) << right << "......2\n";
	cout << "Выход" << setw(11) << right << "......3\n";
}

void saveDatabase_isNotEmty()
{
	
	ofstream fout;
	fout.open(path,ofstream::app);

	if (!fout.is_open())
	{
		cout << "Error open\n";
	}
	else
	{
		for (int i = 1; i < row; i++)
		{
			for (int j = 0; j < col; )
			{

				int n = 12;
				int lenStr = matrix[i][j].length();

				//NAME
				fout << matrix[i][j] << setw(n);
				j++;

				// COST
				fout << fixed;
				int i_cost = stoi(matrix[i][j]);
				double d_cost = stof(matrix[i][j]);
				if (fmod(i_cost, 1) == 0)
				{
					fout << i_cost << setw(n);
				}
				else
				{

					fout << setprecision(1) << d_cost << setw(n);
				}
				j++;

				//QUANT
				double d_quant = stof(matrix[i][j]);
				fout << setprecision(1) << d_quant << setw(n);
				j++;

				//SUM
				fout << setprecision(2) << d_cost * d_quant << endl;
				j++;
			}
			fout << endl;

		}

	}
	fout.close();
}
void saveDatabase_isEmty()
{
	{

		ofstream fout;
		fout.open(path);

		if (!fout.is_open())
		{
			cout << "Error open\n";
		}
		else
		{
			for (int i = 1; i < row; i++)
			{
				for (int j = 0; j < col; )
				{

					int n = 12;
					int lenStr = matrix[i][j].length();

					//NAME
					fout << matrix[i][j] << setw(n);
					j++;

					// COST
					fout << fixed;
					int i_cost = stoi(matrix[i][j]);
					double d_cost = stof(matrix[i][j]);
					if (fmod(i_cost, 1) == 0)
					{
						fout << i_cost << setw(n);
					}
					else
					{

						fout << setprecision(1) << d_cost << setw(n);
					}
					j++;

					//QUANT
					double d_quant = stof(matrix[i][j]);
					fout << setprecision(1) << d_quant << setw(n);
					j++;

					//SUM
					fout << setprecision(2) << d_cost * d_quant << endl;
					j++;
				}
				fout << endl;

			}

		}
		fout.close();
	}
}