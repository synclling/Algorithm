int AddFrom1ToN_Recursive(int n)
{
	return n <= 0 ? 0 : n + AddFrom1ToN_Recursive(n - 1);
}

long long Fibonacci(unsigned int n)
{
	if(n == 0)
		return 0;
	
	if(n == 1)
		return 1;
	
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

long long Fibonacci(unsigned int n)
{
	if(n == 0)
		return 0;
	
	if(n == 1)
		return 1;
	
	long long fibOne = 0;
	long long fibTwo = 1;
	long long fibN = 0;
	for(unsigned int i = 2; i <= n; ++i)
	{
		fibN = fibOne + fibTwo;
		
		fibOne = fibTwo;
		fibTwo = fibN;
	}
	
	return fibN;
}
