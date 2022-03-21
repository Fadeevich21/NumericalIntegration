#include "test.hpp"
#include "NumericalIntegration.hpp"

// Тест для проверки метода центральных прямоугольникав
template <class Function>
void test_MethodMediumRectangles(const Function& function, const Fraction &a, const Fraction &b, const int &n)
{
	try
	{
		Fraction res = MethodMediumRectangles(function, Fraction(a), Fraction(b), n);

		cout << "res = " << res << endl;
		cout << "double = " << (long double)res.numerator() / res.denominator() << endl;
		cout << endl;

		cout << "Status: Ok" << endl << endl;
	}
	catch (const char *msg)
	{
		cout << "Status: Failed" << endl << endl;
	}
}

void test_MethodMediumRectangles_01()
{
	cout << "Test name: test_MethodMediumRectangles_01" << endl;
	Fraction a = 1, b = 5;
	long long n = 8;

	auto function = [](const Fraction &x)
	{
		return x * x - 2 * x + 3;
	};

	test_MethodMediumRectangles(function, a, b, n);
}

void test_MethodMediumRectangles_02()
{
	cout << "Test name: test_MethodMediumRectangles_02" << endl;
	Fraction a = 1, b = 5;
	long long n = 10;

	auto function = [](const Fraction &x)
	{
		return x * x - 2 * x + 3;
	};

	test_MethodMediumRectangles(function, a, b, n);
}


// Тест для проверки метода трапеций
template <class Function>
void test_MethodTrapezoids(const Function &function, const Fraction &a, const Fraction &b, const int &n)
{
	try
	{
		Fraction res = MethodTrapezoids(function, Fraction(a), Fraction(b), n);

		cout << "res = " << res << endl;
		cout << "double = " << (long double)res.numerator() / res.denominator() << endl;
		cout << endl;

		cout << "Status: Ok" << endl << endl;
	}
	catch (const char *msg)
	{
		cout << "Status: Failed" << endl << endl;
	}
}

void test_MethodTrapezoids_01()
{
	cout << "Test name: test_MethodTrapezoids_01" << endl;
	Fraction a = 1, b = 5;
	long long n = 8;

	auto function = [](const Fraction &x)
	{
		return x * x - 2 * x + 3;
	};

	test_MethodTrapezoids(function, a, b, n);
}

void test_MethodTrapezoids_02()
{
	cout << "Test name: test_MethodTrapezoids_02" << endl;
	Fraction a = 0;
	Fraction b = Fraction(22, 7) / 2; // Число Pi / 2 в виде дроби
	long long n = 8;

	auto function = [](const Fraction &x)
	{
		long double tmp = 3 * cosl((long double)x.numerator() / x.denominator());
		return Fraction((long long)ceill(tmp * 1e8), (long long)1e8);
	};

	test_MethodTrapezoids(function, a, b, n);
}


// Тест для проверки метода трапеций
template <class Function>
void test_MethodParabolas(const Function &function, const Fraction &a, const Fraction &b, const int &n)
{
	try
	{
		Fraction res = MethodParabolas(function, Fraction(a), Fraction(b), n);

		cout << "res = " << res << endl;
		cout << "double = " << (long double)res.numerator() / res.denominator() << endl;
		cout << endl;

		cout << "Status: Ok" << endl << endl;
	}
	catch (const char *msg)
	{
		cout << "Status: Failed" << endl << endl;
	}
}

void test_MethodParabolas_01()
{
	cout << "Test name: test_MethodParabolas_01" << endl;
	Fraction a = 1, b = 5;
	long long n = 8;

	auto function = [](const Fraction &x)
	{
		return x * x - 2 * x + 3;
	};

	test_MethodParabolas(function, a, b, n);
}

void test_MethodParabolas_02()
{
	cout << "Test name: test_MethodParabolas_02" << endl;
	Fraction a = 0;
	Fraction b = 2;
	long long n = 8;

	auto function = [](const Fraction &x)
	{
		long double tmp = powl(2, (long double) x.numerator() / x.denominator());
		return Fraction((long long)ceill(tmp * 1e8), (long long)1e8) + Fraction(2721, 1001);
	};

	test_MethodParabolas(function, a, b, n);
}



// Тест для проверки метода Рунге
template <class Function>
void test_MethodRunge(Fraction (*method)(const Function &, const Fraction &, const Fraction &, const int &), const int &p, const Function &function, const Fraction &a, const Fraction &b, const int &n, const Fraction &epsilon)
{
	try
	{
		Fraction res = MethodRunge(method, p, function, Fraction(a), Fraction(b), n, epsilon);

		cout << "res = " << res << endl;
		cout << "double = " << (long double)res.numerator() / res.denominator() << endl;
		cout << endl;

		cout << "Status: Ok" << endl << endl;
	}
	catch (const char *msg)
	{
		cout << "Status: Failed" << endl << endl;
	}
}

void test_MethodRunge_MethodMediumRectangles_01()
{
	cout << "Test name: test_MethodRunge_MethodMediumRectangles_01" << endl;
	Fraction a = 1, b = 5;
	long long n = 8;

	auto function = [](const Fraction &x)
	{
		return x * x - 2 * x + 3;

	};
	Fraction epsilon = Fraction(1, 100000);
	int p = 1;

	test_MethodRunge(MethodMediumRectangles, p, function, a, b, n, epsilon);
}

void test_MethodRunge_MethodMediumRectangles_02()
{
	cout << "Test name: test_MethodRunge_MethodMediumRectangles_02" << endl;
	Fraction a = 1, b = 5;
	long long n = 10;

	auto function = [](const Fraction &x)
	{
		return x * x - 2 * x + 3;
	};
	
	Fraction epsilon = Fraction(1, 100000);
	int p = 1;

	test_MethodRunge(MethodMediumRectangles, p, function, a, b, n, epsilon);
}

void test_MethodRunge_MethodTrapezoids_01()
{
	cout << "Test name: test_MethodRunge_MethodTrapezoids_01" << endl;
	Fraction a = 1, b = 5;
	long long n = 10;

	auto function = [](const Fraction &x)
	{
		return x * x - 2 * x + 3;
	};

	Fraction epsilon = Fraction(1, 100000);
	int p = 2;

	test_MethodRunge(MethodTrapezoids, p, function, a, b, n, epsilon);
}

void test_MethodRunge_MethodTrapezoids_02()
{
	cout << "Test name: test_MethodRunge_MethodTrapezoids_02" << endl;
	Fraction a = 0;
	Fraction b = Fraction(22, 7) / 2; // Число Pi / 2 в виде дроби
	long long n = 8;

	auto function = [](const Fraction &x)
	{
		long double tmp = 3 * cosl((long double)x.numerator() / x.denominator());
		return Fraction((long long)ceill(tmp * 1e8), (long long)1e8);
	};

	Fraction epsilon = Fraction(1, 10000000);
	int p = 2;

	test_MethodRunge(MethodTrapezoids, p, function, a, b, n, epsilon);
}

void test_MethodRunge_MethodParabolas_01()
{
	cout << "Test name: test_MethodRunge_MethodParabolas_01" << endl;
	Fraction a = 1, b = 5;
	long long n = 8;

	auto function = [](const Fraction &x)
	{
		return x * x - 2 * x + 3;
	};

	Fraction epsilon = Fraction(1, 10000000);
	int p = 4;

	test_MethodRunge(MethodTrapezoids, p, function, a, b, n, epsilon);
}

void test_MethodRunge_MethodParabolas_02()
{
	cout << "Test name: test_MethodRunge_MethodParabolas_02" << endl;
	Fraction a = 0;
	Fraction b = 2;
	long long n = 8;

	auto function = [](const Fraction &x)
	{
		long double tmp = powl(2, (long double)x.numerator() / x.denominator());
		return Fraction((long long)ceill(tmp * 1e8), (long long)1e8) + Fraction(2721, 1001);
	};

	Fraction epsilon = Fraction(1, 10000000);
	int p = 4;

	test_MethodRunge(MethodTrapezoids, p, function, a, b, n, epsilon);
}



// Тест для проверки метода Гаусса
template <class Function>
void test_MethodGauss(const Function &function, const vector<pair<Fraction, Fraction>> &vecNodesAndWeights, const Fraction &a, const Fraction &b, const int &n)
{
	try
	{
		Fraction res = MethodGauss(function, vecNodesAndWeights, Fraction(a), Fraction(b), n);

		cout << "res = " << res << endl;
		cout << "double = " << (long double)res.numerator() / res.denominator() << endl;
		cout << endl;

		cout << "Status: Ok" << endl << endl;
	}
	catch (const char *msg)
	{
		cout << "Status: Failed" << endl << endl;
	}
}

template <class Function>
void test_MethodGauss_oneNode(const Function &function, const Fraction &a, const Fraction &b, const int &n)
{
	vector<pair<Fraction, Fraction>> vecNodesAndWeights =
	{
		{{2}, {0}}
	};

	test_MethodGauss(function, vecNodesAndWeights, a, b, n);	
}

template <class Function>
void test_MethodGauss_twoNodes(const Function &function, const Fraction &a, const Fraction &b, const int &n)
{
	vector<pair<Fraction, Fraction>> vecNodesAndWeights =
	{
		{{1}, {-1351, 2340}},
		{{1}, {1351, 2340}}
	};

	test_MethodGauss(function, vecNodesAndWeights, a, b, n);
}

template <class Function>
void test_MethodGauss_threeNodes(const Function &function, const Fraction &a, const Fraction &b, const int &n)
{
	vector<pair<Fraction, Fraction>> vecNodesAndWeights =
	{
		{{5, 9}, {-15617, 20160}},
		{{8, 9}, {0}},
		{{5, 9}, {15617, 20160}}
	};

	test_MethodGauss(function, vecNodesAndWeights, a, b, n);
}

template <class Function>
void test_MethodGauss_fourNodes(const Function &function, const Fraction &a, const Fraction &b, const int &n)
{
	vector<pair<Fraction, Fraction>> vecNodesAndWeights =
	{
		{{8, 23}, {-459, 533}},
		{{12319, 18890}, {-17, 50}},
		{{12319, 18890}, {17, 50}},
		{{8, 23}, {459, 533}}
	};

	test_MethodGauss(function, vecNodesAndWeights, a, b, n);
}

void test_MethodGauss_01()
{
	cout << "Test name: test_MethodGauss_01" << endl;
	Fraction a = 1, b = 5;
	long long n = 1;

	auto function = [](const Fraction &x)
	{
		return x * x - 2 * x + 3;
	};

	test_MethodGauss_oneNode(function, a, b, n);
}

void test_MethodGauss_02()
{
	cout << "Test name: test_MethodGauss_02" << endl;
	Fraction a = 1, b = 5;
	long long n = 2;

	auto function = [](const Fraction &x)
	{
		return x * x - 2 * x + 3;
	};

	test_MethodGauss_twoNodes(function, a, b, n);
}

void test_MethodGauss_03()
{
	cout << "Test name: test_MethodGauss_03" << endl;
	Fraction a = 1, b = 5;
	long long n = 3;

	auto function = [](const Fraction &x)
	{
		return x * x - 2 * x + 3;
	};

	test_MethodGauss_threeNodes(function, a, b, n);
}

void test_MethodGauss_04()
{
	cout << "Test name: test_MethodGauss_04" << endl;
	Fraction a = 1, b = 5;
	long long n = 4;

	auto function = [](const Fraction &x)
	{
		return x * x - 2 * x + 3;
	};

	test_MethodGauss_fourNodes(function, a, b, n);
}

void test_MethodGauss_05()
{
	cout << "Test name: test_MethodGauss_05" << endl;
	Fraction a = 1, b = 5;
	long long n = 1;

	auto function = [](const Fraction &x)
	{
		return x * x + 2 * x + 1;
	};

	test_MethodGauss_oneNode(function, a, b, n);
}

void test_MethodGauss_06()
{
	cout << "Test name: test_MethodGauss_06" << endl;
	Fraction a = 1, b = 5;
	long long n = 2;

	auto function = [](const Fraction &x)
	{
		return x * x + 2 * x + 1;
	};

	test_MethodGauss_twoNodes(function, a, b, n);
}

void test_MethodGauss_07()
{
	cout << "Test name: test_MethodGauss_07" << endl;
	Fraction a = 1, b = 5;
	long long n = 3;

	auto function = [](const Fraction &x)
	{
		return x * x + 2 * x + 1;
	};

	test_MethodGauss_threeNodes(function, a, b, n);
}

void test_MethodGauss_08()
{
	cout << "Test name: test_MethodGauss_08" << endl;
	Fraction a = 1, b = 5;
	long long n = 4;

	auto function = [](const Fraction &x)
	{
		return x * x + 2 * x + 1;
	};

	test_MethodGauss_fourNodes(function, a, b, n);
}