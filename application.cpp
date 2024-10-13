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
			cout << "������� 1 ���� ������ �������� An, ������� 0 ���� ������ �������� ���� �� ������";
			cin >> p;
			
			if (p)
			{
				cout << "������� An ";
				cin >> t;
				pol.change_coef(t);
			}
			else
			{
				int pos;
				cout << "������� ����� ����� ";
				cin >> pos;
				cout << "������� �������� ������ ����� ";
				cin >> t;
				pol.change_root(pos, t);
			}
			break;
		case 3:
			cout << "������� �����";
			
			cin >> k;
			pol.calculate_polinom(k);
			break;
		case 4:
			cout << "������� ����� ������ ������� ������";
			cin >> p;
			pol.change_root_size(p);
			break;
		case 5:
			cout << "������� ������ ������ �������� 1 ��� 2";
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
			cout << "�� ������� ������� �������� ����";
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
	cout << "������� ������ ������� ";
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
			cout << "�� ������� ������� �������� ����";
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
	cout << "�������� ��������" << '\n';
	cout << "1) ���� � ������� ��������, �������� ������ �������" << '\n';
	cout << "2) ������ �������� � ��� ������� ������� � ����� ����������� �������" << '\n';
	cout << "3) ���������� ��������� ������� �� ����������� ��� ��������" << '\n';
	cout << "4) ��������� ����������� �������" << '\n';
	cout << "5) ��������� �������� ���������� �������� �������" << '\n';
	cout << "6) ����� ��������� �������" << '\n';
	cout << "7) �����" << '\n';
	cout << "������� ����� ������� ";
	cin >> vvod;
	return vvod;
}

int aplication::menu_polinom()
{
	int vvod;
	setlocale(LC_ALL, "RU");
	cout << "�������� ��������" << '\n';
	cout << "1) ���� � ������� ��������, �������� ������ �������" << '\n';
	cout << "2) ��������� ������������ an ��� ������ �� ��������� �� ������� ������" << '\n';
	cout << "3) ���������� �������� �������� � �������� �����" << '\n';
	cout << "4) ��������� ����������� �������" << '\n';
	cout << "5) ����� � ������� �������� ������� �������� � ����� 1 ��� 2" << '\n';
	cout << "6) �����" << '\n';
	cout << "������� ����� ������� ";
	cin >> vvod;
	return vvod;
}