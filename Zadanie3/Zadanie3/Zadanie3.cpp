﻿// Zadanie3.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*	Napisz program w języku „C/C++”, realizujący metody:
(a) Picarda
(b) bisekcji
(c) Newtona
(d) siecznych
rozwiązywania pojedynczych algebraicznych równań nieliniowych. Zastosuj program do
przykładów z zadania 1. Zastosuj trzy niezależne kryteria zakończenia iteracji. Zadbaj o to, aby
wyprowadzać na konsolę wyniki pośrednie obliczeń dla każdej iteracji, tak aby możliwe było
obserwowanie zbieżności kolejnych przybliżeń pierwiastków i porównanie liczby iteracji
niezbędnych do uzyskania rozwiązania o zadanej dokładności przez każdą z metod. W szczególności
oblicz jak zmienia się estymator błędu rozwiązania oraz residuum równania w trakcie iteracji.

1) f1(x) = sin^2(x/4) - x
2) f2(x) = tan(2*x) - x - 1
*/

#include<iostream>
#include<cmath>
#include<windows.h>
#include<conio.h>

#include "NonLinearEquationSolving.h"

double f1(double);
double f2(double);
double df1(double);
double df2(double);

void displayTable(Result&, std::vector<Result>&);
HANDLE  hConsole;

int main(int argc, char** argv) {

	using namespace std;

	vector<Result> app;
	Result r;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Accuracy of caculations:
	NLES::setEpsilon(0.000000000000001);
	NLES::setDelta(0.000000000000001);
	NLES::setMax(50);

	cout << endl << "Function f1(x) = 0" << endl;
	cout << "_________________________________________________________________________________" << endl << endl;

	// Function f1:
	NLES::setFunction(f1);
	NLES::setDerivative(df1);

	// Caculating with bisection:
	NLES::setRange(0., 2.); // [0, 2]
	r = NLES::bisection();
	app = NLES::getApproximations();

	cout << endl;
	cout << "Bisection method" << endl;
	displayTable(r, app);

	// Calculating with Picard:
	r = NLES::picard();
	app = NLES::getApproximations();

	cout << endl;
	cout << "Picard's method" << endl;
	displayTable(r, app);

	// Calculating with Newton:
	r = NLES::newton();
	app = NLES::getApproximations();

	cout << endl;
	cout << "Newton's method" << endl;
	displayTable(r, app);

	// Calculating with secant:
	r = NLES::secant(1.9, 2.);
	app = NLES::getApproximations();

	cout << endl;
	cout << "Secant method" << endl;
	displayTable(r, app);



	cout << endl << endl << "Function f2(x) = 0" << endl;
	cout << "_________________________________________________________________________________" << endl << endl;

	// Function f2:
	NLES::setFunction(f2);
	NLES::setDerivative(df2);

	// Caculating with bisection:
	NLES::setRange(-1., 3.); // [-1, 3]
	r = NLES::bisection();
	app = NLES::getApproximations();

	cout << endl;
	cout << "Bisection method" << endl;
	displayTable(r, app);

	// Calculating with Picard:
	r = NLES::picard();
	app = NLES::getApproximations();

	cout << endl;
	cout << "Picard's method" << endl;
	displayTable(r, app);

	// Calculating with Newton:
	r = NLES::newton();
	app = NLES::getApproximations();

	cout << endl;
	cout << "Newton's method" << endl;
	displayTable(r, app);

	// Calculating with secant:
	r = NLES::secant(2.9, 3.);
	app = NLES::getApproximations();

	cout << endl;
	cout << "Secant method" << endl;
	displayTable(r, app);

	_getch();
	return EXIT_SUCCESS;
}// end main

double f1(double x) {
	double tmp = cos(x / 4.);
	return (tmp * tmp - x);
}// end f1

double f2(double x) {
	return (exp(x) - exp(-x) + x - 1.);
}// end f1

double df1(double x) {
	return (-0.5 * sin(x / 4.) * cos(x / 4.) - 1.);
}// end df1

double df2(double x) {
	return (exp(x) + exp(-x) + 1.);
}// end f1

void displayTable(Result& r, std::vector<Result>& app) {
	using namespace std;

	cout << "---------------------------------------------------------------------------------" << endl;
	cout.width(5);
	cout << "n";
	cout.width(25);
	cout << setprecision(15) << "x";
	cout.width(25);
	cout << setprecision(15) << "est";
	cout.width(25);
	cout << setprecision(15) << "f(x)";
	cout << endl;
	cout << "---------------------------------------------------------------------------------" << endl;

	if (r.end_condition & BAD_INPUT) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << endl << "No itaration done, bad input data: function, derivative or range." << endl << endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	else {
		vector<Result>::iterator b = app.begin();
		vector<Result>::const_iterator e = app.end();
		while (b != e) {
			cout << *b << endl;
			++b;
		}
	}

	cout << "---------------------------------------------------------------------------------" << endl;

	if (r.end_condition & BAD_INPUT) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "No results..." << endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	else {
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		cout << r << endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}

	cout << "---------------------------------------------------------------------------------" << endl;
	cout << "End condition: ";
	if (r.end_condition & BAD_INPUT) {
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "BAD INPUT DATA" << endl;
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	else if (r.end_condition == 0)
		cout << "NONE" << endl;
	else {
		if (r.end_condition & ITER_REACHED)
			cout << "MAX AMOUT OF ITERATION, ";
		if (r.end_condition & EPSILON_REACHED)
			cout << "EPSILON, ";
		if (r.end_condition & DELTA_REACHED)
			cout << "DELTA";
		cout << endl;
	}
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
