/*
Author: Danil Patrakov
Group: СБС-002-О-01 / 2
Task: 1.13
Description: вычислить значение выражения: A * X^4 + B * X^3 + C * X^2 + (D * X) div E.
*/

#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "Данная программа вычисляет значение выражения: A * X^4 + B * X^3 + C * X^2 + (D * X) div E.\n";

	int a, b, c, d, e, x;

	std::cout << "Введите число A: ";
	std::cin >> a;
	std::cout << "Введите число B: ";
	std::cin >> b;
	std::cout << "Введите число C: ";
	std::cin >> c;
	std::cout << "Введите число D: ";
	std::cin >> d;
	std::cout << "Введите число E: ";
	std::cin >> e;
	std::cout << "Введите число X: ";
	std::cin >> x;

	int cpp_ans = a * x * x * x * x + b * x * x * x + c * x * x + (d * x) / e;

	int asm_ans = 0;

	_asm {
		mov eax, a
		cdq
		imul x
		imul x
		imul x
		imul x
		mov ebx, eax
		mov eax, b
		cdq
		imul x
		imul x
		imul x
		add ebx, eax
		mov eax, c
		cdq
		imul x
		imul x
		add ebx, eax
		mov eax, d
		cdq
		imul x
		div e
		add ebx, eax
		mov asm_ans, ebx
	}

	std::cout << "Результат вычислений на ассемблере: " << asm_ans << std::endl;
	std::cout << "Результат вычислений на C++: " << cpp_ans << std::endl;

	system("pause");
	return 0;
}

