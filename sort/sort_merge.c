#include <stdlib.h>
void merge_array(int *leftarray,int leftsize,int *rightarray,int rightsize,int *totalarray)
{
	int *pleft = leftarray;
	int *pright = rightarray; 
	int *ptotal = totalarray;
	int i = 0;
	int j = 0;
	while(i < leftsize && j < rightsize)
	{
		if(*pleft <= *pright)
		{
			*ptotal++ = *pleft++;
			i++;
		}
		else
		{
			*ptotal++ = *pright++;
			j++;
		}
	}
	while(i< leftsize)
	{
		*ptotal++ = *pleft++;
		i++;
	}
	while(j < rightsize)
	{
		*ptotal++ = *pright++;
		j++;
	}
}
void mergesort(int *array,int size,int *ptemparray)
{
	if(size == 0)
	{
		return;
	}
	if(size > 1)
	{
		int mid = size/2;
		int *pleft = (int *)malloc(mid*sizeof(int));
		int *pright = (int *)malloc((size-mid)*sizeof(int));
		
		// 合并左侧，得到leftarray
		mergesort(array,mid,pleft);	
		// 合并右侧，得到rightarray
		mergesort(array+mid,size-mid,pright);	

		//合并leftarray rightarray
		merge_array(pleft,mid,pright,size-mid,ptemparray);
		free(pleft);
		free(pright);
	}
	else
	{
		ptemparray[0]=array[0];
	}

}
void sort_merge(int *array,int size)
{	
	int *ptemparray =(int*)malloc(size*sizeof(int));
	mergesort(array,size,ptemparray);
	for(int i = 0; i < size;i++)
	{
		array[i] = ptemparray[i];
	}
	free(ptemparray);
	ptemparray = NULL;
}
