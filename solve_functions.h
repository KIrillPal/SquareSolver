/*!
\file
\brief Заголовочный файл с функциями для решения уравнения

Данный файл содержит в себе их реализацию.
*/
#pragma once

enum SqSolver
{
	NO_ROOTS    = 0,
	ONE_ROOT    = 1,
	TWO_ROOTS   = 2,
	INF_ROOTS   = -1,
	ERROR_OCCUR = -2
};

enum ErrorCodes
{
	NO_ERRORS       = 0,
	NULL_POINTER    = 1,
	INCORRECT_ROOTS = 2,
	INVALID_INPUT   = 3
};

// a = b;

/*!
Возвращает, равен ны ли два вещественных числа друг другу по модулю
\param[in] first,second Вещественные числа
\param[in] EPS Модуль для сравнения, по умолчанию имеет значение 10^-8
\return True, если два числа считаются равными, т.е. |a-b| <= EPS; False иначе.
*/
bool EQUALS(double a, double b, double EPS = 1e-8);

/*!
Решает линейное уравнение вида ax + b = 0.
\param[in] a,b Аргументы функции
\param[out] root Искомый корень
\return Количество корней или специальный код.
\note 0-1 - кол-во корней
\note -1 - бесконечное количество корней
\note -2 - ошибка ввода данных или указателя
*/
int solveLinear(double a, double b, double* root);

/*!
Решает квадратное уравнение вида ax2 + bx + c = 0.
\param[in] a,b,c Аргументы функции
\param[out] root1, root2 Искомые корни
\return Количество корней или специальный код.
\note 0-2 - кол-во корней
\note -1 - бесконечное количество корней
\note -2 - ошибка ввода данных или указателя
*/
int solveSquare(double a, double b, double c, double* root1, double* root2);
