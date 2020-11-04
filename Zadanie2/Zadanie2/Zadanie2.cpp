// Zadanie2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>

using namespace std;

double funkcja(double x) {
	double f = (1 - exp(-x)) / x;
	return f;
}

double blad_wzgl(double x, double fx) {
	double f = exp(x);
	return abs((fx - f) / f);
}


int main(int argc, char** argv)
{
	/*
	for (double i = pow(10, -30); i <= pow(10, 9); i *= 1.05)
	{
		cout<< i << "   " << funkcja(i) << endl;
	}
	return 0;*/

	float a = 1.0 / 3.0;
	float b = 1.0 / 3.0;
	float c = 1.0 / 3.0;
	float d = a + b + c;

	float e = 1.0 / 10.0;
	float f = 2.0 / 10.0;

	float g = e + f;
	cout << g <<endl <<endl;
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
