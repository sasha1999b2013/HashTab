// ConsoleApplication17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Header.h"
#include "Header1.h"
#include "HashTab.cpp"
#include <ctime>
#include <string>
#include <string.h>
#include <Windows.h>

using namespace std;
void MainMenu();
void menu()
{
	cout << "1: Добавить элемент в хеш - таблицу" << endl;
	cout << "2: Удалить элемент из хеш - таблицы" << endl;
	cout << "3: Поиск в хеш-таблице" << endl;
	cout << "4: Вычисление числа элементов в хеш - таблице" << endl;
	cout << "5: Печать хеш - таблицы" << endl;
	cout << "6: Вернуться к выбору типа элементов" << endl;
	cout << "0: Выход " << endl;
	cout << "--> ";
}
int RealMenu()
{
	int i = 0;
	HashTab<double, double> x;
	do
	{
		menu();
		cin >> i;
		cout << endl;
		switch (i)
		{
		case 1:
		{
			double m;
			x.print();
			cout << "Введите элемент, который хотите добавить" << endl;
			cin >> m;
			x.AddElem(m);
		}

		break;
		case 2:
		{
			double m;
			x.print();
			cout << "Введите ключ элемента, который хотите удалить" << endl;
			cin >> m;
			x.DelElem(m);
		}
		break;
		case 3:
		{
			double m, n = 0;
			x.print();
			cout << "Введите ключ элемента, который хотите найти" << endl;
			cin >> m;
			x.Search(m, n);
		}
		break;
		case 4:
		{
			cout << "количество элементов = " << x.count() << "\n" << endl;
		}
		break;
		case 5:
		{
			x.print();
		}
		break;
		case 6:
		{
			MainMenu();
		}
		break;
		case 0: break;
		default: cout << "Такого пункта нет\n" << endl;
			break;
		}
	} while (i != 0);
	return i;
}
int StringMenu()
{
	int i = 0;
	HashTab<string, string> x;
	do
	{
		menu();
		cin >> i;
		cout << endl;
		switch (i)
		{
		case 1:
		{
			string m;
			x.print();
			cout << "Введите элемент, который хотите добавить" << endl;
			cin >> m;
			x.AddElem(m);
		}

		break;
		case 2:
		{
			string m;
			x.print();
			cout << "Введите ключ элемента, который хотите удалить" << endl;
			cin >> m;
			x.DelElem(m);
		}
		break;
		case 3:
		{
			string m, n;
			x.print();
			cout << "Введите ключ элемента, который хотите найти" << endl;
			cin >> m;
			x.Search(m, n);
		}
		break;
		case 4:
		{
			cout << "количество элементов = " << x.count() << endl;
		}
		break;
		case 5:
		{
			x.print();
		}
		break;
		case 6:
		{
			MainMenu();
		}
		break;
		case 0: break;
		default: cout << "Такого пункта нет\n" << endl;
			break;
		}
	} while (i != 0);
	return i;
}
int PointMenu()
{
	int i = 0;
	HashTab<TPoint, TPoint> x;
	do
	{
		menu();
		cin >> i;
		cout << endl;
		switch (i)
		{
		case 1:
		{
			TPoint m;
			x.print();
			cout << "Введите элемент, который хотите добавить" << endl;
			cin >> m;
			x.AddElem(m);
		}

		break;
		case 2:
		{
			TPoint m;
			x.print();
			cout << "Введите ключ элемента, который хотите удалить" << endl;
			cin >> m;
			x.DelElem(m);
		}
		break;
		case 3:
		{
			TPoint m, n;
			n.x = 0;
			n.y = 0;
			x.print();
			cout << "Введите ключ элемента, который хотите найти" << endl;
			cin >> m;
			x.Search(m, n);
		}
		break;
		case 4:
		{
			cout << "количество элементов = " << x.count() << endl;
		}
		break;
		case 5:
		{
			x.print();
		}
		break;
		case 6:
		{
			MainMenu();
		}
		break;
		case 0: break;
		default: cout << "Такого пункта нет\n" << endl;
			break;
		}
	} while (i != 0);
	return i;
}
void MainMenu()
{
	int i = 0;
	do
	{
		cout << "Выберите тип элементов " << endl;
		cout << "1: Числовой тип " << endl;
		cout << "2: Строковый тип " << endl;
		cout << "3: Структура точка" << endl;
		cout << "0: Выход " << endl;
		cout << "--> ";
		cin >> i;
		cout << endl;
		switch (i)
		{
		case 1:
			i = RealMenu();
			break;
		case 2:
			i = StringMenu();
			break;
		case 3:
			i = PointMenu();
			break;
		case 0:
			break;
		default: cout << "Такого пункта нет\n" << endl;
			break;
		}
	} while (i != 0);
}
int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	MainMenu();
	system("pause");
	return 0;
} // конец main 



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
