/*二分查找*/
int find_binary(int *parray,int size,int findval)
{
    int index = size/2; //初始查找位置
    int start = 0;
    int	end = size -1; 
    while(start <= end)
    {
	index = (start + end) / 2;
	if(parray[index] == findval)
	{
	    return index;
	}
	else if(parray[index] < findval)
	{
	    start = index + 1;
	}
	else
	{
	    end = index - 1;
	}
    }

    return -1;
	
}
