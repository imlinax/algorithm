void adjArray(int *parray,int left,int right)
{
	int value = parray[left];
	int i = left;
	int j = right;
	if(left >= right)
	{
		return;
	}
	while(i < j)
	{
		while(j > i && parray[j] >= value)
		{
			j--;
		}
		if(i < j)
		{
			parray[i] = parray[j];
			i++;
		}
		while(i < j && parray[i] < value)
		{
			i++;
		}
		if(i < j)
		{
			parray[j] = parray[i];
			j--;
		}
	}
	parray[i] = value;
	adjArray(parray,left,i-1);
	adjArray(parray,i+1,right);
	return;
}
	
void sort_quick(int *parray,int size)
{
	if(size < 2)
	{
		return;
	}
	adjArray(parray,0,size-1);
	return ;
}
