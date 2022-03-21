#pragma once

#include <vector>
#include "..\..\..\Fraction_realizate\Fraction_realizate\fraction.hpp"

// Оценка погрешности квадратурных формул по принципу Рунге
template <class Function>
Fraction MethodRunge(Fraction(*method)(const Function &, const Fraction &, const Fraction &, const int &), const int &p, const Function &f, const Fraction &a, const Fraction &b, const int &countSpittingSegments, const Fraction &epsilon)
{
	int n = countSpittingSegments;
	Fraction resFirst;
	Fraction resSecond = method(f, a, b, n);
	do
	{
		resFirst = resSecond;
		n *= 2;
		resSecond = method(f, a, b, n);
	}
	while ((abs(resFirst - resSecond) / ((2 << (p - 1)) - 1)) > epsilon);

	return resSecond;
}

// Метод центральных прямоугольников
template <class Function>
Fraction MethodMediumRectangles(const Function &f, const Fraction &a, const Fraction &b, const int &countSpittingSegments)
{
	Fraction h = (b - a) / countSpittingSegments;
	Fraction sum = Fraction();
	for (int i = 0; i < countSpittingSegments; i++)
		sum += f(a + (i + Fraction(1, 2)) * h);

	return h * sum;
}

// Метод трапеций
template <class Function>
Fraction MethodTrapezoids(const Function &f, const Fraction &a, const Fraction &b, const int &countSpittingSegments)
{
	Fraction h = (b - a) / countSpittingSegments;
	Fraction sum = Fraction((f(a) + f(b)) / 2);
	for (int i = 1; i < countSpittingSegments; i++)
		sum += f(a + i * h);

	return h * sum;
}

// Метод парабол (Симпсона)	
template <class Function>
Fraction MethodParabolas(const Function &f, const Fraction &a, const Fraction &b, const int &countSpittingSegments)
{
	Fraction h = (b - a) / countSpittingSegments;
	Fraction sumElOddIndex = Fraction();
	for (int i = 1; i < countSpittingSegments; i += 2)
		sumElOddIndex += f(a + i * h);

	Fraction sumElEvenIndex = Fraction();
	for (int i = 2; i < countSpittingSegments; i += 2)
		sumElEvenIndex += f(a + i * h);

	return h / 3 * (f(a) + f(b) + 4 * sumElOddIndex + 2 * sumElEvenIndex);
}

// Метод Гаусса
template <class Function>
Fraction MethodGauss(const Function &f, const vector<pair<Fraction, Fraction>> &vecNodesAndWeights, const Fraction &a, const Fraction &b, const int &countSpittingSegments)
{
	Fraction halfSubstraction = (b - a) / 2;
	Fraction halfAddition = (a + b) / 2;

	Fraction sum = Fraction();
	for (int i = 0; i < countSpittingSegments; i++)
		sum += vecNodesAndWeights[i].first * f(halfAddition + halfSubstraction * vecNodesAndWeights[i].second);

	return halfSubstraction * sum;
}