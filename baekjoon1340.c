#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	char month[20];
	int m,day, year, hour, minute, t;
	scanf("%s %d%[','] %d %d%[':']%d", month, &day, &t, &year, &hour, &t, &minute);
	if (strcmp(month,"Jan") == 0)
		m = 1;
	else if (strcmp(month, "Feb") == 0)
		m = 2;
	else if (strcmp(month, "Mar") == 0)
		m = 3;
	else if (strcmp(month, "Apr") == 0)
		m = 4;
	else if (strcmp(month, "May") == 0)
		m = 5;
	else if (strcmp(month, "June") == 0)
		m = 6;
	else if (strcmp(month, "July") == 0)
		m = 7;
	else if (strcmp(month, "Aug") == 0)
		m = 8;
	else if (strcmp(month, "Sept") == 0)
		m = 9;
	else if (strcmp(month, "Oct") == 0)
		m = 10;
	else if (strcmp(month, "Nov") == 0)
		m = 11;
	else if (strcmp(month, "Dec") == 0)
		m = 12;
	long long total = 365 * 24;
	long long a = 0;
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		total += 24;
	total *= 60;
	for (int i = 1; i < m; i++) {
		switch (i) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			a += 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			a += 30;
			break;
		case 2:
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
				a += 29;
			else
				a += 28;
			break;
		}
	}

	a += day-1;
	a *= 24;
	a += hour;
	a *= 60;
	a += minute;

	double result = (double)a / total;
	printf("%.15lf\n", result*100);

}