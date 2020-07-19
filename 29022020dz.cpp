/*
Домашнее задание № 10
Курс «Язык программирования C»
Встреча №19
Тема : Многомерные массивы
Домашнее задание
Задание 1 : Напишите программу, которая создает двухмерный массив и заполняет его по следующему принципу : пользователь вводит число(например, 3) первый элемент массива принимает значение этого числа, последующий элемент массива принимает значение этого числа умноженного на 2 (т.е. 6 для нашего примера), третий элемент массива предыдущий элемент умноженный на 2 (т.е. 6 * 2 = 12 для нашего примера).Созданный массив вывести на экран.
*/
/*
#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleOutputCP(1251);
	const int sizeROW = 100, sizeCOL = 100;
	int arr[sizeROW][sizeCOL];
	cout << "Введите число: ";
	int num;
	cin >> num;
	do
	{
		for (int i = 0; i < sizeROW; i++)
		{
			for (int j = 0; j < sizeCOL; j++)
			{
				arr[i][j] = num;
				num *= 2;
			}
		}
	} while (num);
	for (int j = 0; j < 3; j++)
	{
		cout << arr[0][j] << '\t';
	}
}
*/
/*
Задание 2: Напишите программу, которая создает двухмерный массив и заполняет его по следующему принципу : пользователь вводит число(например, 3) первый элемент массива принимает значение этого числа, последующий элемент массива принимает значение этого числа + 1 (т.е. 4 для нашего примера), третий элемент массива предыдущий элемент + 1 (т.е. 5 для нашего примера).Созданный массив вывести на экран.
#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleOutputCP(1251);
	const int sizeROW = 100, sizeCOL = 100;
	int arr[sizeROW][sizeCOL];
	cout << "Введите число: ";
	int num;
	cin >> num;
	for (int i = 0; i < sizeROW; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = num;
			num += 1;
		}
	}
	for (int j = 0; j < 3; j++)
	{
		cout << arr[0][j] << '\t';
	}
}
*/
/*
Задание 3: Создайте двухмерный массив.Заполните его случайными числами и покажите на экран.Пользователь выбирает количество сдвигов и положение(влево, вправо, вверх, вниз).Выполнить сдвиг массива и показать на экран полученный результат.Сдвиг циклический.
Например, если мы имеем следующий массив
1 2 0 4 5 3
4 5 3 9 0 1
и пользователь выбрал сдвиг на 2 разряда вправо, то мы получим
5 3 1 2 0 4
0 1 4 5 3 9
#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;
const int sizeROW = 100, sizeCOL = 100;
void PrintArray(int arr[][sizeCOL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endl;
	}
}
void FillArray(int arr[][sizeCOL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void RightShift(int number_of_shifts, int arr[][sizeCOL], int row, int col)
{
	double temp;
	for (int p = 1; p <= number_of_shifts; p++)
	{
		for (int i = 0; i < row; i++)
		{
			temp = arr[i][col - 1];
			for (int j = col - 1; j > 0; j--)
				arr[i][j] = arr[i][j - 1];
			arr[i][0] = temp;
		}
	}
}
void LeftShift(int number_of_shifts, int arr[][sizeCOL], int row, int col)
{
	double temp;
	for (int i = 1; i <= number_of_shifts; i++)
	{
		for (int i = 0; i < row; i++)
		{
			temp = arr[i][col - col];
			for (int k = col - col; k < col; k++)
				arr[i][k] = arr[i][k + 1];
			arr[i][col - 1] = temp;
		}
	}
}
void DownShift(int number_of_shifts, int arr[][sizeCOL], int row, int col)
{
	double temp;
	for (int p = 1; p <= number_of_shifts; p++)
	{
		for (int j = 0; j < col; j++)
		{
			temp = arr[row - 1][j];
			for (int i = row - 1; i > 0; i--)
				arr[i][j] = arr[i - 1][j];
			arr[0][j] = temp;
		}
	}
}
void UpShift(int number_of_shifts, int arr[][sizeCOL], int row, int col)
{
	double temp;
	for (int p = 1; p <= number_of_shifts; p++)
	{
		for (int j = 0; j < col; j++)
		{
			temp = arr[row - row][j];
			for (int i = 0; i < row; i++)
				arr[i][j] = arr[i + 1][j];
			arr[row - 1][j] = temp;
		}
	}
}
int main()
{
	SetConsoleOutputCP(1251);
	srand(time(0));
	int a[sizeROW][sizeCOL];
	int n = 4, m = 6;
	cout << "Исходный массив: " << endl;
	FillArray(a, n, m);
	PrintArray(a, n, m);
	cout << "Введите количество элементов на сдвиг: ";
	int number_of_shifts;
	cin >> number_of_shifts;
	cout << endl;
	cout << "Ввыберите положение (1-влево, 2-вправо, 3-вверх, 4-вниз): ";
	int position;
	cin >> position;
	switch (position)
	{
	case 1:
	{
		LeftShift(number_of_shifts, a, n, m);
		PrintArray(a, n, m);
	}
	break;
	case 2:
	{
		RightShift(number_of_shifts, a, n, m);
		PrintArray(a, n, m);
	}
	break;
	case 3:
	{
		UpShift(number_of_shifts, a, n, m);
		PrintArray(a, n, m);
	}
	break;
	case 4:
	{
		DownShift(number_of_shifts, a, n, m);
		PrintArray(a, n, m);
	}
	break;
	default: cout << "Позиций всего 4!";
	}
}
*/

