#include <iostream>
#include "aplication.h"
#include "massiv.h"
#include "polinom.h"

using namespace std;
int aplication::choice_polinom()
{
	polinom pol;
	int ap;
	bool h = true;
	int p;
	number t;
	number k;
	while (h)
	{
		system("cls");
		ap = menu_polinom();
		switch (ap)
		{
		case 1:
			pol.input();
			break;
		case 2:
			cout << "Введите 1 если хотите изменить An, введите 0 если хотите изменить один из корней";
			cin >> p;
			
			if (p)
			{
				cout << "Введите An ";
				cin >> t;
				pol.change_coef(t);
			}
			else
			{
				int pos;
				cout << "Введите номер корня ";
				cin >> pos;
				cout << "Введите значение нового корня ";
				cin >> t;
				pol.change_root(pos, t);
			}
			break;
		case 3:
			cout << "Введите точку";
			
			cin >> k;
			pol.calculate_polinom(k);
			break;
		case 4:
			cout << "Введите новый размер массива корней";
			cin >> p;
			pol.change_root_size(p);
			break;
		case 5:
			cout << "Введите формат вывода полинома 1 или 2";
			cin >> p;
			if (p == 1)
			{
				pol.print_pol_1();
			}
			else
			{
				pol.print_pol_2();
			}
			break;
		case 6:
			h = false;
			break;
		default:
			cout << "Вы выбрали вариант которого нету";
		}
		cout << '\n';
		system("pause");
	}
	return 5;
}
int aplication::choice()
{
	int n = 0;
	bool h = true;
	int ap;
	cout << "Введите размер массива ";
	cin >> n;
	massiv mass;
	mass.change_cize(n);
	while (h)
	{
		system("cls");
		ap = menu();
		switch (ap)
		{
		case 1:
			mass.completion(n);
			mass.print();
			break;
		case 2:
			mass.sko();
			break;
		case 3:
			mass.sort();
			mass.print();
			break;
		case 4:
			int num;
			cin >> num;
			mass.change_cize(num);
			mass.print();
			break;
		case 5:
			mass.change_element();
			mass.print();
			break;
		case 6:
			mass.print();
			break;
		case 7:
			h = false;
			break;
		default:
			cout << "Вы выбрали вариант которого нету";
		}
		cout << '\n';
		system("pause");
	}
	return ap;
}

int aplication::menu()
{
	int vvod;
	setlocale(LC_ALL, "RU");
	cout << "Выберите действие" << '\n';
	cout << "1) Ввод с консоли значений, задающих объект массива" << '\n';
	cout << "2) Расчет среднего и СКО элентов массива и вывод результатов расчета" << '\n';
	cout << "3) Сортировка элементов массива по возрастанию или убыванию" << '\n';
	cout << "4) Изменение размерности массива" << '\n';
	cout << "5) Изменение значения выбранного элемента массива" << '\n';
	cout << "6) Вывод элементов массива" << '\n';
	cout << "7) Выход" << '\n';
	cout << "Введите номер команды ";
	cin >> vvod;
	return vvod;
}

int aplication::menu_polinom()
{
	int vvod;
	setlocale(LC_ALL, "RU");
	cout << "Выберите действие" << '\n';
	cout << "1) Ввод с консоли значений, задающих объект полином" << '\n';
	cout << "2) Изменение коэффициента an или одного из выбранных по индексу корней" << '\n';
	cout << "3) Вычисления значения полинома в заданной точке" << '\n';
	cout << "4) Изменения размерности массива" << '\n';
	cout << "5) Вывод в консоль текущего объекта полинома в форме 1 или 2" << '\n';
	cout << "6) Выход" << '\n';
	cout << "Введите номер команды ";
	cin >> vvod;
	return vvod;
}