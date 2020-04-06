bool Find(int *matrix, int rows, int columns, int number)
{
	bool found = false;
	if(matrix != NULL && rows > 0 && columns > 0)
	{
		int row = 0;
		int col = columns - 1;
		while(row < rows && col >= 0)
		{
			if(number == matrix[row * columns + col])
			{
				found = true;
				break;
			}
			else if(number < matrix[row * columns + col])
			{
				--col;
			}
			else
			{
				++row;
			}
		}
	}
	return found;
}