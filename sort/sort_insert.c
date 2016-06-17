
void sort_insert(int *parray,int size)
{
	if(size < 2)
	{
		return ;
	}
	int i = 0; 
	int j = 0;
	int value = 0;
	for(i = 1; i < size ; i++)
	{
		value = parray[i];
		for(j = i-1; j >= 0; j--)
		{
			if(value < parray[j])
			{
				parray[j+1] = parray[j];
			}
			else
			{
				break;
			}
		}
		parray[j+1] = value;
	}
	return;
}
