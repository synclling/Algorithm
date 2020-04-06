int FindMin(int *array, int length)
{
	if(array == NULL || length <= 0)
		throw new std::exception("Invalid parameters.");
	
	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	
	while(array[index1] >= array[index2])
	{
		if(index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		else
		{
			indexMid = (index1 + index2) / 2;
			if(array[indexMid] >= array[index1])
				index1 = indexMid;
			else if(array[indexMid] <= array[index2])
				index2 = indexMid;
		}
	}
	
	return array[indexMid];
}