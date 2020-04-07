#include<stdio.h>

int A[50][50];
int S[50][50];
static int m, n;

void DP_CollectApple(int x, int y){
	S[x][y] = A[x][y];
	int max = 0;
	if(x > 0 && max < S[x - 1][y])
		max = S[x - 1][y];
	if(y > 0 && max < S[x][y - 1])
		max = S[x][y - 1];
	
	S[x][y] += max;
	
	/*for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j)
			printf(" %d ", S[i][j]);
		printf("\n");
	}
	printf("------------------------\n"); */
	if(x < m - 1)	DP_CollectApple(x + 1, y);
	if(y < n - 1)	DP_CollectApple(x, y + 1);
}

void PathRecursively(int x, int y){
	int i, j;
	int max = 0;
	if(x > 0 && max < S[x - 1][y]){
		max = S[x - 1][y];
		i = x - 1;
		j = y;
	}
	if(y > 0 && max < S[x][y - 1]){
		max = S[x][y - 1];
		i = x;
		j = y - 1;
	}
	if(x > 0 || y > 0)	PathRecursively(i, j);
	printf("%d ", S[x][y]);
}


int main()
{
	int i, j;
	scanf("%d %d", &m, &n);
	for(i = 0; i < m; ++i)
		for(j = 0; j < n; ++j)
			scanf("%d", &A[i][j]);
	DP_CollectApple(0, 0);
	for(i = 0; i < m; ++i){
		for(j = 0; j < n; ++j)
			printf("%d ", S[i][j]);
		printf("\n");
	}
	PathRecursively(m - 1, n - 1);
	return 0;
}

