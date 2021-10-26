#include <cstdio>
#include "testing.h"
#include "solve_functions.h"

int main()
{
#ifdef TEST
	TestFunction();
#else
	double A = 0, B = 0, C = 0, root1 = 0, root2 = 0;

	printf("Input A B C:\n");
	int input_count = scanf("%lf %lf %lf", &A, &B, &C);
	if (input_count != 3)
		return INVALID_INPUT;

	int root_count = solveSquare(A, B, C, &root1, &root2);

	switch (root_count)
	{
		case NO_ROOTS:    printf ("Your equation has no roots\n");                                              break;
		case ONE_ROOT:    printf ("Your equation has 1 root X;\nX = %.3lf\n", root1);                           break;
		case TWO_ROOTS:   printf ("Your equation has 2 roots X1, X2;\nX1 = %.3lf, X2 = %.3lf\n", root1, root2); break;
		case INF_ROOTS:   printf ("Your equation has infinite number of roots\n");                              break;
		case ERROR_OCCUR: printf ("An internal error has occured\n");                                           break;
		default:          return INCORRECT_ROOTS;
	}

#endif

	return 0;
}

