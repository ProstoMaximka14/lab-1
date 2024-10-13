#include <iostream>
#include "massiv.h"
#include "number.h"
using namespace std;

void massiv:: completion(int m)
{
	
	for (int i = 0; i < m; i++)
	{
		cin >> elements[i];
	}
}

void massiv::change_element()
{
	cout << "¬ведите позицию элемента который хотите изменить ";
	int b;
	cin >> b;
	number a;
	cout << "¬ведите новое значение элемента ";
	cin >> a;
	elements[b] = a;
}

void massiv::print()
{
	for (int i = 0; i < elements.size(); i++)
	{
		cout << '[' << elements[i] << "] ";
	}
}

void massiv::sort()
{
	int size = elements.size();
	cout << "¬ведите 0 дл€ сортировки по возрастанию или 1 дл€ сортировки по убыванию ";
	int a;
	cin >> a;

	for (int i = 0; i < size / 2; i++)
	{
		for (int c = i; c < size - i - 1; c++)
		{
			if (elements[c] > elements[c + 1])
			{
				swap(elements[c], elements[c + 1]);
			}
		}
		for (int c = size - 2 - i; c >= i; c--)
		{
			if (elements[c] > elements[c + 1])
			{
				swap(elements[c], elements[c + 1]);
			}
		}

	}
	if (a == 1)
	{
		reverse(elements.begin(), elements.end());
	}
}

void massiv::change_cize(int num)
{
	elements.resize(num);
}

void massiv::sko()
{
	int size = elements.size();
	number summ = 0;
	for (int i = 0; i < elements.size(); i++)
	{
		summ = summ + elements[i];
	}
	number firstStep = 1.0 / size;
	number secondStep = firstStep * summ;
	cout << "—реднее значение элементов массива:\t" << secondStep;
	int sizeN = size - 1;
	number thirdtStep = 1.0 / sizeN;
	number free = 0;
	for (int i = 0; i < elements.size(); i++)
	{
		number space = elements[i] - secondStep;
		number space2 = space * space;
		free = free + space2;
	}

	number forthStep = thirdtStep * free;
	number fifthStep = sqrt(forthStep);
	cout << "\n—реднеквадротическое отклонение:\t" << fifthStep;
}
