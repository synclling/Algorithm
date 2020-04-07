#include<stdio.h>


/*****nlogn*****/
int BinarySearch(int *b, int len, int key){
	int low = 0;
	int high = len - 1;
	int mid;
	while(low <= high){
		mid = (low + high) / 2;
		if(b[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low;
}

int LIS_nlogn(int *a, int len){
	int i, j = 0;
	int b[len];
	b[j] = a[0];
	for(i = 1; i < len; ++i){
		if(a[i] > a[i - 1])
			b[++j] = a[i];
		else if(a[i] < a[i - 1]){
			int index = BinarySearch(b, j + 1, a[i]);
			b[index] = a[i];
		}
	}
	for(i = 0; i <= j; ++i)
		printf("%d ", b[i]);
	printf("\n");
	return j + 1;
}

/*****n^2*****/
int LIS_n2(int *a, int n){
	if(a == NULL || n <= 0)
		return -1;
	int d[n];
	int len = 1;
	for(int i = 0; i < n; ++i){
		d[i] = 1;
		for(int j = 0; j < i; ++j){
			if(a[j] <= a[i] && d[j] + 1 > d[i])
				d[i] = d[j] + 1;
		if(d[i] > len) len = d[i];
		}
	}
	return len;
} 

int main()
{
	int a[] = {2, 1, 5, 3, 6, 4, 8, 9, 7};
	printf("%d\n", LIS_n2(a, 9));
	return 0;
}





