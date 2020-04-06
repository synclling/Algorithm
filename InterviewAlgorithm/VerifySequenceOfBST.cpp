bool VerifySequenceOfBST(int *sequence, int length)
{
	if(sequence == NULL || length <= 0)
	{
		return false;
	}
	
	int root = sequence[length - 1];
	
	int i, j;
	for(i = 0; i < length - 1; ++i)
	{
		if(sequence[i] > root)
			break;
	}
	
	for(j = i; j < length - 1; ++j)
	{
		if(sequence[j] < root)
			return false;
	}
	
	bool bLeft = true;
	if(i > 0)
	{
		bLeft = VerifySquenceOfBST(sequence, i);
	}
	
	bool bRight = true;
	if(i < length - 1)
	{
		bRight = VerifySquenceOfBST(sequence + i; length - i - 1)
	}
	
	return (bLeft && bRight);
}
