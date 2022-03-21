#include <iostream>
#include <Windows.h>
#include "NumericalIntegration.hpp"
#include "test.hpp"
#include "..\..\..\Fraction_realizate\Fraction_realizate\fraction.hpp"

using namespace std;

void test();

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Привет, Мир!" << endl;

	test();

	return 0;
}

void test()
{
	//test_MethodMediumRectangles_01();
	//test_MethodMediumRectangles_02();

	//test_MethodTrapezoids_01();
	//test_MethodTrapezoids_02();

	//test_MethodParabolas_01();
	//test_MethodParabolas_02();

	//test_MethodRunge_MethodMediumRectangles_01();
	//test_MethodRunge_MethodMediumRectangles_02();

	//test_MethodRunge_MethodTrapezoids_01();
	//test_MethodRunge_MethodTrapezoids_02();

	//test_MethodRunge_MethodParabolas_01();
	//test_MethodRunge_MethodParabolas_02();

	test_MethodGauss_01();
	test_MethodGauss_02();
	test_MethodGauss_03();
	test_MethodGauss_04();
	test_MethodGauss_05();
	test_MethodGauss_06();
	test_MethodGauss_07();
	test_MethodGauss_08();
}