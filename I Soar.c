#include <stdio.h>
#include <math.h>

//the trick is that the input might not be within the highway's range

typedef struct{
	double a,b;
}point;

int cmpfunc (const void * a, const void * b)
{
	point *tempA = a;
	point *tempB = b;
	if (tempA->a == tempB->a){
		return tempA->b - tempB->b;
	}
	return tempA->a - tempB->a;
}

void addup(point arr[], int N, double dist)
{
	double sum = 0.0,tempdist,visible,x,y;
	int i,j;
	i = 0,x = arr[i].a, y = arr[i].b;
	sum += y-x;

	for (i = 1; i < N; i++){
		if (arr[i].a > y){
			sum += arr[i].b -arr[i].a;
			y = arr[i].b;
		}
		else if (arr[i].b > y){
			tempdist = arr[i].b - arr[i].a;
			sum += tempdist-(y-arr[i].a);
			y = arr[i].b;
		}
	}
	visible = dist-sum;
	printf("The total planting length is %.1lf\n",visible);
}
int main()
{
	double x,y,dist;
	point arr[10000];
	int i;

	while (scanf("%lf",&dist) == 1){
		i = 0;
		if (dist < 0){
			break;
		}
		while (scanf("%lf%lf",&x,&y) == 2){
			if (x > y){
				break;
			}
			else{
				if (x > dist){
					x = dist;
				}
				if (y > dist){
					y = dist;
				}
				if (x < 0){
					x = 0;
				}
				if (y < 0){
					y = 0;
				}
				point p = {x,y};
				arr[i++] = p;
			}
		}
		qsort(arr,i,sizeof(point),cmpfunc);
		addup(arr,i,dist);
	}

	return 0;
}

