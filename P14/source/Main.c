#include<stdio.h>
#include<stdlib.h>
#define EXAM 4
#define STUDENT 3
int minimum(const int grade[][EXAM], int pup, int test);
int maximum(const int grade[][EXAM], int pup, int test);
double average(const int setofgrade[], int test);
void printarray(const int grade[][EXAM], int pup, int test);

int main(void)
{
	int student;
	const int studentgrade[STUDENT][EXAM] = 
	{
		{77,68,86,73},
		{96,87,89,78},
		{70,90,86,81}
	};
	printf("The array is:\n");
	printarray(studentgrade, STUDENT, EXAM);

	printf("\n\nLowest grade: %d\nHighest grade: %d\n",
		minimum(studentgrade, STUDENT, EXAM),
		maximum(studentgrade, STUDENT, EXAM));

	for (student = 0; student < STUDENT; student++)
	{
		printf("The average grade for student %d is %.2f\n",
			student, average(studentgrade[student], EXAM));
	}
	system("pause");
	return 0;
}

void printarray(const int grade[][EXAM], int pup, int test)
{
	int i, j;
	printf("                 [0]  [1]  [2]  [3]");
	for (i = 0; i < pup; i++)
	{
		printf("\nstudentGrades[%d] ", i);
		for (j = 0; j < test; j++) printf("%-5d", grade[i][j]);
	}
}

int minimum(const int grade[][EXAM], int pup, int test)
{
	int i, j,lowgrade=100;
	for (i = 0; i < pup; i++)
	{
		for (j = 0; j < test; j++)
		{
			if (grade[i][j] < lowgrade) lowgrade = grade[i][j];
		}
	}
	return lowgrade;
}

int maximum(const int grade[][EXAM], int pup, int test)
{
	int i, j, highgrade = 0;
	for (i = 0; i < pup; i++)
	{
		for (j = 0; j < test; j++)
		{
			if (grade[i][j] > highgrade) highgrade = grade[i][j];
		}
	}
	return highgrade;
}

double average(const int setofgrade[], int test)
{
	int i, total = 0;
	for (i = 0; i < test; i++) total += setofgrade[i];
	return (double)total / test;
}
