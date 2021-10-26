#include <cstdio>
#include <cerrno>
#include <cmath>
#include "testing.h"

void TestFunction()
{
	SqTest tests[] = {
		{       1, 3,-4,  2, -4, 1, NO_ERRORS},
		{       1, 2, 1,  1, -1, 0, NO_ERRORS},
		{       4, 5, 6,  0,  0, 0, NO_ERRORS},
		{       0, 1, 0,  1,  0, 0, NO_ERRORS},
		{       0, 0, 1,  0,  0, 0, NO_ERRORS},
		{       0, 0, 0, -1,  0, 0, NO_ERRORS},
		{       1, 0, 0,  1,  0, 0, NO_ERRORS},
		{     NAN, 0, 0,  0,  0, 0, INVALID_INPUT},
		{INFINITY, 0, 0,  0,  0, 0, INVALID_INPUT}
	};
	for (int i = 0; i < 9; i++)
	{
		double pred_root1 = 0, pred_root2 = 0;
		int root_count = solveSquare(tests[i].A, tests[i].B, tests[i].C, &pred_root1, &pred_root2);
		if (errno != tests[i].errCode)
		{
			printf("Incorrect error catch! Equation: %lfx^2 + %lfx + %lf = 0\n", tests[i].A, tests[i].B, tests[i].C);
		}
		else if (errno == 0 && root_count != tests[i].nRoots)
		{
			printf("Invalid number of roots! Equation: %lfx^2 + %lfx + %lf = 0\n", tests[i].A, tests[i].B, tests[i].C);
			printf("Predicted root count: %d. Correct is %d\n", root_count, tests[i].nRoots);
			printf("Equation type: %d\n", tests[i].errCode);
			return;
		}
		else if (root_count >= 1 && !EQUALS(pred_root1, tests[i].root1))
		{
			printf("Invalid 1st root! Equation: %lfx^2 + %lfx + %lf = 0\n", tests[i].A, tests[i].B, tests[i].C);
			printf("Predicted root count: %d. Correct is %d\n", root_count, tests[i].nRoots);
			printf("Predicted 1st root: %d. Correct is %d\n", pred_root1, tests[i].root1);
			printf("Equation type: %d\n", tests[i].errCode);
			return;
		}
		else if (root_count == 2 && !EQUALS(pred_root2, tests[i].root2))
		{
			printf("Invalid 2nd root! Equation: %lfx^2 + %lfx + %lf = 0\n", tests[i].A, tests[i].B, tests[i].C);
			printf("Predicted root count: %d. Correct is %d\n", root_count, tests[i].nRoots);
			printf("Predicted roots: %d, %d. Correct is %d, %d\n", pred_root1, pred_root2, tests[i].root1, tests[i].root2);
			printf("Equation type: %d\n", tests[i].errCode);
			return;
		}
		printf("Test %d passed.\n", i+1);
	}
	printf("Testing: OK!\n");
}
