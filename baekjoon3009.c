#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Point {
	int x;
	int y;
}Point;

int main() {
	Point p1, p2, p3, p4;
	scanf("%d %d", &p1.x, &p1.y);
	scanf("%d %d", &p2.x, &p2.y);
	scanf("%d %d", &p3.x, &p3.y);
	if (p1.y == p2.y) {
		p4.y = p3.y;
		if (p1.x == p3.x)
			p4.x = p2.x;
		else
			p4.x = p1.x;
	}
	else if (p1.y == p3.y) {
		p4.y = p2.y;
		if (p2.x == p1.x)
			p4.x = p3.x;
		else
			p4.x = p1.x;
	}
	else if (p2.y == p3.y) {
		p4.y = p1.y;
		if (p2.x == p1.x)
			p4.x = p3.x;
		else
			p4.x = p2.x;
	}
	printf("%d %d\n", p4.x, p4.y);

}