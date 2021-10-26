#include <cerrno>
#include <cassert>
#include <math.h>
#include "solve_functions.h"

bool EQUALS(double a, double b, double EPS)
{
	return abs(a - b) <= EPS;
}

int solveLinear(double a, double b, double* root)
{
#ifdef TEST

	if (!root)
	{
		errno = NULL_POINTER;
		return ERROR_OCCUR;
	}
	if (!isfinite(a) || !isfinite(b))
	{
		errno = INVALID_INPUT;
		return ERROR_OCCUR;
	}

#else

	assert(root);
	assert(isfinite(a) && isfinite(b));

#endif

	if (EQUALS(a, 0))
	{
		if (EQUALS(b, 0))
			return INF_ROOTS;
		return NO_ROOTS;
	}

	*root = -b / a;
	return ONE_ROOT;
}

int solveSquare(double a, double b, double c, double* root1, double* root2)
{
#ifdef TEST

	if (!root1 || !root2)
	{
		errno = NULL_POINTER;
		return ERROR_OCCUR;
	}
	if (!isfinite(a) || !isfinite(b) || !isfinite(c))
	{
		errno = INVALID_INPUT;
		return ERROR_OCCUR;
	}

#else

	assert(root1 && root2);
	assert(isfinite(a) && isfinite(b) && isfinite(c));
	
#endif

	if (EQUALS(a, 0))
		return solveLinear(b, c, root1);

	double D = b * b - 4 * a * c;
	if (EQUALS(D, 0))
	{
		*root1 = -b / (a * 2);
		return ONE_ROOT;
	}

	if (D < 0)
		return NO_ROOTS;

	*root1 = (-b - sqrt(D)) / (a * 2);
	*root2 = (-b + sqrt(D)) / (a * 2);

	if (a < 0)
	{
		double temp_val = *root1;
		*root1 = *root2;
		*root2 = temp_val;
	}

	return TWO_ROOTS;
}




