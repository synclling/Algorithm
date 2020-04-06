void ReorderOddEven(int *array, unsigned int length)
{
	if(array == NULL || int length == 0)
	{
		return;
	}
	
	int *pBegin = array;
	int *pEnd = array + length - 1;
	
	while(pBegin < pEnd)
	{
		while(pBegin < pEnd && (*pBegin & 0x1) != 0)
		{
			++pBegin;
		}
		
		while(pBegin < pEnd && (*pEnd & 0x1) != 1)
		{
			--pEnd;
		}
		
		if(pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}