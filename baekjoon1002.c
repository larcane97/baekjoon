#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
	int i, t, x1, y1, x2, y2, r1, r2;
	double d;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		// 동일한 원
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2)
				printf("%d\n", -1);
			else
				printf("%d\n", 0);
			continue;
		}
		d = sqrt(((double)x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		int maxR = r1 >= r2 ? r1 : r2;
		int minR = r1 >= r2 ? r2 : r1;
		
		if (maxR+minR < d || maxR-minR > d)
			printf("%d\n", 0);
		else if(maxR+minR == d || maxR-minR == d)
			printf("%d\n", 1);
		else if(maxR-minR < d && maxR+minR >d){ 
				printf("%d\n", 2);
		}
	}
}
