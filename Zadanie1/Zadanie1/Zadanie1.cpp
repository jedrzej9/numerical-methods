// Zadanie1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
using namespace std;

template <class T> void wyznacz(int* mantysa, T* epsilon) {
	*epsilon = 1.0;
	*mantysa = 0;
	T a, b, c;
	b = 1.0;
	a = b + *epsilon;
	while (a > 1.0) {
		c = *epsilon;
		*epsilon /= 2.0;
		(*mantysa)++;
		a = *epsilon + b;
	}
	(*mantysa)--;
	*epsilon = c;

}

int main(int argc, char* argv[])
{
	int mantysa_d, mantysa_f;
	double epsilon_d;
	float epsilon_f;
	wyznacz(&mantysa_d, &epsilon_d);
	wyznacz(&mantysa_f, &epsilon_f);

	cout << "Double:" << endl;
	cout << "\tmantysa: " << mantysa_d << "\tepsilon: " << epsilon_d << endl;
	cout << "Float:" << endl;
	cout << "\tmantysa: " << mantysa_f << "\tepsilon: " << epsilon_f << endl;

	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
