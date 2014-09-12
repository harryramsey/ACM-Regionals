#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int first(int x, int arr[], int N)
{
	int lo = 0;
	int hi = N-1;
	int mid;
	while (lo <= hi){
		mid = (hi+lo)/2;
		if (arr[mid] < x){
			lo = mid+1;
		}
		else if (arr[mid] > x){
			hi = mid-1;
		}
		else if (lo != mid){
			hi = mid;
		}
		else return mid;
	}
}

int binsearch(int x, int arr[], int N)
{
	int lo = 0;
	int hi = N-1;
	int mid;
	while (lo <= hi){
		mid = (hi+lo)/2;
		if (arr[mid] < x){
			lo = mid+1;
		}
		else if (arr[mid] > x){
			hi = mid-1;
		}
		else return mid;
	}
	return -1;
}


int last(int x, int arr[], int N)
{
	int lo = 0;
	int hi = N-1;
	int mid;
	while (lo <= hi){
		mid = (hi+lo)/2;
		if (arr[mid] < x){
			lo = mid+1;
		}
		else if (arr[mid] > x){
			hi = mid-1;
		}
		else if (hi != mid){
			lo = mid+1;
		}
		else return mid;
	}
}

int main()
{
	int nodes[1100], parent[1100], grandparent[1100];
	int n,k,i,j,num,a,b,c,d,pos;

	while (scanf("%d%d",&n,&k) == 2){
		if (n== 0 && k == 0) break;
		for (i = 0; i < n; i++){
			scanf("%d",&num);
			nodes[i] = num;
		}
		parent[0] = -1;
		i = -1, j = 1;
		while (j < n){
			if (nodes[j] == nodes[j-1]+1){
				parent[j] = i;
				j++;
			}
			else {
				i++;
				parent[j] = i;
				j++;
			}
		}
		i = -1; j = 0;
		while (j < n){
			if (parent[j] == -1 || parent[j] == 0){
				grandparent[j] = i;
				j++;
			}
			else if (parent[parent[j]] == parent[parent[j-1]]){
				grandparent[j] = i;
				j++;
			}
			else{
				i++;
				grandparent[j] = i;
				j++;
			}
		}
		pos = binsearch(k,nodes,n);
		if (parent[pos] == -1 || parent[pos] == 0){
			printf("%d\n",0);
		}
		else{
			a = first(grandparent[pos],grandparent,n);
			b = last(grandparent[pos],grandparent,n);
			c = first(parent[pos],parent,n);
			d = last(parent[pos], parent,n);
			printf("%d\n",(b-a+1)-(d-c+1));
		}
	}
	return 0;
}

