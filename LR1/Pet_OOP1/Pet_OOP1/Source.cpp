#include "Header.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <clocale>
#include <cstdlib>
#include <Windows.h>
using namespace std;

int sum = 0;
int const col = 3;
int row = 1;
string** matrix = new string * [row];
int n = 20;
int l = 1;

class BazaData
{
public:
	string name;
	int quant;
	int cost;

};
void printmenu()
{
	cout << "Название товара" << setw(6) <<"Цена" << setw(12)<< "Kоличество" << setw(13)<< "Общая сумма" << endl;

}

void fillProduct()
{
	for (; l <= row; l++)
	{
		matrix[l] = new string[col];
		
	}
	


	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < col; )
		{
			BazaData BDname;
			cout << "Введите название товара\n";
			cin >> BDname.name;
			matrix[row][j] = BDname.name;
			n = n - BDname.name.length();
			j++;

			BazaData BDcost;
			cout << "Введите цену товара\n";
			cin >> BDcost.cost;
			string strCost = to_string(BDcost.cost);
			matrix[row][j] = strCost;
			j++;

			BazaData BDquant;
			cout << "Введите количество товара\n";
			cin >> BDquant.quant;
			string strQuant = to_string(BDquant.quant);
			matrix[row][j] = strQuant;
			j++;
			
		}

	}
	row++;
	cout << endl;
}

void variantMenu()
{
	cout << "Добавить новый элемент" <<setw(17) << ".....1\n";
	cout << "Распечатать базу данных" <<setw(9) <<".....2\n";
	cout << "Выход из программы"<<setw(14) << ".....3\n";
}

void printBazaData()
{
	
	for (int i = 1; i < row; i++)
	{
		for (int j = 0; j < col; )
		{
			cout << matrix[i][j] << "\t";;
			j++;
			cout  << matrix[i][j] <<"\t";
			j++;
			cout  << matrix[i][j] << "\t";;
			j++;


		}
		cout << endl;
	}
	cout << "_____________________________________________\n";
	//cout << "Всего товаров на сумму: " << sum << endl;
}

//void delMatrix()
//{
//	for (int i = 1; i < row; i++)
//	{
//		delete[] matrix[i];
//	}
//	delete[] matrix;
//}