// 模拟加法
bool Increment(char *number, int length)
{
	bool isOverflow = false;
	
	int nTakeOver = 0;	// 进位
	for(int i = length - 1; i >= 0; --i)
	{
		int nSum = number[i] - '0' + nTakeOver;
		
		if(i == length - 1)
		{
			++nSum;
		}
		
		if(nSum == 10)
		{
			if(i == 0)
			{
				isOverflow = true;
			}
			else
			{
				nTakeOver = 1;
				nSum -= 10;
				number[i] = nSum + '0';
			}
		}
		else
		{
			number[i] = nSum + '0';
			break;
		}
	}
	
	return isOverflow;
}

void PrintNumber(char *number, int length)
{
	if(number == NULL || length <=  0)
	{
		return;
	}
	
	bool isBeginning0 = true;
	for(int i = 0; i < length; ++i)
	{
		if(isBeginning0 && number[i] != '0')
		{
			isBeginning0 = false;
		}
		
		if(!isBeginning0)
		{
			printf("%c", number[i]);
		}
	}
	
	printf("\n");
}

void Print1ToMaxOfNDigits(int n)
{
	if(n <= 0)
	{
		return;
	}
	
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[i] = '\0';
	
	while(!Increment(number, n))
	{
		PrintNumber(number, n);
	}
	
	delete []number;
}

// 数字排列，递归实现
void Print1ToMaxOfNDigitsRecursively(char *number, int length, int index)
{
	if(index == length)
	{
		PrintNumber(number, length);
		return;
	}
	
	for(int i = 0; i < 10; ++i)
	{
		number[index] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}

void Print1ToMaxOfNDigits(int n)
{
	if(n <= 0)
	{
		return;
	}
	
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	
	Print1ToMaxOfNDigitsRecursively(number, n, 0);
	
	delete []number;
}
