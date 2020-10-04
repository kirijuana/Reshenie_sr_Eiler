
#include "pch.h"
#include <iostream>
#include <list>
#include <math.h>


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int a = 0, n = 0, b = 0;
	cout << "a = b mod(n)" << "\n";
	cout << "Введите 3 числа: a, b и n: " << "\n";

	cin >> a >> b >> n;
	// замена на вычеты
	a = a % n;
	b = b % n;

	// вычисление НОД'а (Алгоритм Евклида)
	int a_1 = a, b_1 = n, k = 0, ost_1 = 1, ost = 1, NOD = 0;
	if (a > n)
	{
		a_1 = a;
		b_1 = n;
	}
	else
	{
		a_1 = n;
		b_1 = a;
	}
	if (a_1 % b_1 == 0)
	{
		ost_1 = b_1;
	}
	else
	{
		do
		{
			ost_1 = ost;
			k = a_1 / b_1;
			ost = a_1 - b_1 * k;
			a_1 = b_1;
			b_1 = ost;


		} while (ost != 0);
	}
	NOD = ost_1;

	cout << "НОД введенных чисел равен: " << NOD << "\n";
	
	a = a / NOD;
	b = b / NOD;
	n = n / NOD; 
	

	// Разложение числа на простые множители
	list<int> prime_numb;

	
	int N = n;	
	

	int div = 2;
	while (N > 1)
	{
		while (N % div == 0)
		{
			prime_numb.push_back(div);
			N = N / div;
		}
		div++;
	}

	float fi_ = 1;
	int check = 1;
	cout << "n = " << n << " = 1";
	// Нахождение функции Эйлера
	for (auto iter = prime_numb.begin(); iter != prime_numb.end(); iter++)
	{
		if (check != *iter)
		{
			fi_ = fi_ * (1.0 - (1.0 / *iter));
			cout << " * " << *iter;
			check = *iter;
		}
	}
	fi_ = fi_ * n;
	cout << "\n" << "Значение функции Эйлера от " << n << " равно: " << fi_ << "\n";
	
	int fi = (int)fi_ - 1;

	// Перевод числителя в бинарный вид и нахождение x_0
	list<int> bin_val;
	int x2 = 0;
	while (fi > 0)
	{
		x2 = fi % 2;
		if (fi == 0)
			break;
		bin_val.push_back(x2);
		fi /= 2;
	}

	// Возведение в степень
	int m = 1, s = a;
	for (auto iter = bin_val.begin(); iter != bin_val.end(); iter++)
	{
		if (*iter == 1)
		{
			m = (m * s) % n;
		}
		s = (s * s) % n;
	}
	int x = (m * b) % n;

	// Нахождение и вывод остальных решений 
	cout << "НОД = " << NOD << "=> решения: " "\n";

	for (int i = 0; i < NOD; i++)
	{
		cout << i + 1 << ". " << x << " + " << i << " * " << n << " = " << x + i * n << "\n";
	}
	return 0;
}