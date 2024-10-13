#pragma once
#ifndef POLINOM_H
#define POLINOM_H
#include "massiv.h"
#include "number.h"
#include <vector>
using namespace std;
class polinom
{
private:
	massiv root;
	massiv coef;
	number coef_main;
	void find_coef();
public:
	polinom();
	polinom(number, int);
	void print_pol_1();
	void print_pol_2();
	number calculate_polinom(number);
	void input();
	void change_root(int, number);
	void change_root_size(int);
	void change_coef(number);
};

#endif // POLINOM_H