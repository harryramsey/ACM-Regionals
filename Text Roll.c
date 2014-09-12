#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void rolling(char paragraph[1005][105], int row, int col)
{
	int i = 0, j = 0;
	while (i < row && j < col){
		if (paragraph[i][j] == ' '){
			if (i == row-1) break;
			i++;
		}
		else j++;
	}
	printf("%d\n", j+1);
}

int main()
{
	char paragraph[1005][105];
	int arr[1005];
	int i,j,c,size,pos,temp_length,max_length;

	for (i = 0; i < 1005; i++){
		for (j = 0; j < 105; j++){
			paragraph[i][j] = ' ';
		}
	}

	while(1){
		scanf("%d", &size);
		if (size == 0) break;
		c = getchar();
		max_length = 0;
		for (i = 0; i < size; i++){
			c = getchar();
			pos = 0;
			while (c != '\n'){
				paragraph[i][pos] = c;
				c = getchar();
				pos++;
			}
			if (pos > max_length) max_length = pos;
			arr[i] = pos;
		}
		rolling(paragraph,size,max_length);
		for (i = 0; i < size; i++){
			for (j = 0; j < arr[i]; j++){
				paragraph[i][j] = ' ';
			}
		}
	}
	return 0;
}
