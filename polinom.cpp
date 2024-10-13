#include <iostream>
//#include "massiv.h"
#include "number.h"
#include "polinom.h"
using namespace std;

polinom::polinom()
{
	coef_main = 1;
	root;
}

polinom::polinom(number coef_m, int len)
{
	coef_main = coef_m;
	root.change_cize(len);
	find_coef();
}

void polinom::find_coef()
{
	int n = root.elements.size();
	coef.change_cize(n + 1);
	coef.elements[1] = 1;
	coef.elements[0] = root.elements[0]*(-1);
	for (int k = 2; k <= n; k++)
	{
		coef.elements[k] = coef.elements[k - 1];
		for (int i = k - 1; i > 0; i--)
		{
			coef.elements[i] = coef.elements[i - 1] - coef.elements[i] * root.elements[k - 1];
		}
		coef.elements[0] = coef.elements[0] * root.elements[k - 1];
	}
	for (int i = 0; i < n; i++)
	{
		coef.elements[i] = coef.elements[i] * coef_main;
	}
}

void polinom::print_pol_2()
{
	cout << '(' << coef_main << ')';
	int m = root.elements.size();
	for (int i = m-1; i >= 0; i--)
	{
		cout << "(x - (" << root.elements[i] << " ))";
	}
}

void polinom::print_pol_1()
{
	int m = coef.elements.size()-1;
	for (int i = m; i >= 0; i--)
	{
		if (coef.elements[i] != 0)
		{
			if (i != m)
			{
				if (coef.elements[i] > 0)
					cout << "+";
			}
			cout << '(' << coef.elements[i] << ')';
			if (i > 0)
				cout << "*x^" << i;
		}
	}
}

number polinom::calculate_polinom(number x)
{
	number m=coef_main;
	int n = root.elements.size();
	for (int i = n; i >= 0; i--)
	{
		m = m * (x-root.elements[i]);
	}
	return m;
}

void polinom::input()
{
	cout << "Введите коэффициент Аn ";
	cin >> coef_main;
	cout << '\n' << "Введите степень полинома ";
	int n;
	cin >> n;
	root.change_cize(n);
	for (int i = 0; i < n; i++)
	{
		number r;
		cin >> r;
		root.elements[i] = r;
	}
	find_coef();
}

void polinom::change_root(int n, number m)
{
	root.elements[n] = m;
}

void polinom::change_root_size(int len)
{
	root.change_cize(len);
}

void polinom::change_coef(number c)
{
	coef_main = c;
}