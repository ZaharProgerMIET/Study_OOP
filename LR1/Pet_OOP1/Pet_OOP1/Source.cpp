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
	cout << "�������� ������" << setw(6) <<"����" << setw(12)<< "K���������" << setw(13)<< "����� �����" << endl;

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
			cout << "������� �������� ������\n";
			cin >> BDname.name;
			matrix[row][j] = BDname.name;
			n = n - BDname.name.length();
			j++;

			BazaData BDcost;
			cout << "������� ���� ������\n";
			cin >> BDcost.cost;
			string strCost = to_string(BDcost.cost);
			matrix[row][j] = strCost;
			j++;

			BazaData BDquant;
			cout << "������� ���������� ������\n";
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
	cout << "�������� ����� �������" <<setw(17) << ".....1\n";
	cout << "����������� ���� ������" <<setw(9) <<".....2\n";
	cout << "����� �� ���������"<<setw(14) << ".....3\n";
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
	//cout << "����� ������� �� �����: " << sum << endl;
}

//void delMatrix()
//{
//	for (int i = 1; i < row; i++)
//	{
//		delete[] matrix[i];
//	}
//	delete[] matrix;
//}