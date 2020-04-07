#include<stdio.h>
#include<malloc.h>
#include<memory.h>

void PrintNumber(char *number){
	bool isbeginning0 = true;
	int nLength = strlen(number);
	
	for(int i = 0; i < nLength; ++i){
		if(isbeginning0 && number[i] != '0')
			isbeginning0 = false;
		if(!isbeginning0)
			printf("%c", number[i]);
	}
	printf("\n");
}

void Print1ToMaxOfNDigitsRescursively(char *number, int nLength, int index){
	if(index == nLength){
		PrintNumber(number);
		return;
	}
	
	for(int i = 0; i < 10; ++i){
		number[index] = i + '0';
		Print1ToMaxOfNDigitsRescursively(number, nLength, index + 1);
	}
}

void Print1ToMaxOfNDigits(int n){
	if(n <= 0){
		printf("Invalid Input!\n");
		return;
	}
	char *number = (char *)malloc((n + 1) *sizeof(char));
	memset(number, '0', n);
	number[n] = '\0';
	
	Print1ToMaxOfNDigitsRescursively(number, n, 0);
	
	free(number);
}

int main()
{
	int n;
	scanf("%d", &n);
	Print1ToMaxOfNDigits(n);
	return 0;
}

