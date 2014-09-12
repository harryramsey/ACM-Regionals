#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	double a,b,c;
}point;

int cmpfunc (const void * a, const void * b)
{
	point *tempA = a;
	point *tempB = b;
	return tempA->a - tempB->a;
}

void bf_search(point points[], int n, int k)
{
	int i,j,count = 0;
	double a,b,c,d;
	for (i = 0; i < n; i++){
		j = i+1;
		while (abs(points[i].a - points[j].a) <= k && j < n){
			a = points[i].a - points[j].a;
			b = points[i].b - points[j].b;
			c = points[i].c - points[j].c;
			d = a*a + b*b + c*c;
			if (sqrt(d) < k){
				count++;
			}
			j++;
		}
	}
	printf("%d\n",count);
}
int main()
{
	int n,k,i;
	double a,b,c;
	point points[101000];
	while (1){
		scanf("%d%d",&n,&k);
		if (n == 0 && k == 0) break;
		for (i = 0; i < n; i++){
			scanf("%lf%lf%lf",&a,&b,&c);
			point p = {a,b,c};
			points[i] = p;
		}
		qsort(points,n,sizeof(point),cmpfunc);
		bf_search(points,n,k);
	}
	return 0;
}
