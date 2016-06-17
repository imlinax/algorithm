
extern void swap(int *pa,int *pb);

/***********
* 选择排序,每次选择一个最小值，将它放到队首，
*然后从剩下的数组中选择出一个最小值，到到第二的位置
*循环上面的动作，直到排序完成
**/
void sort_select(int *parray,int size)
{
	if(size < 2)
	{
		return ;
	}
	int i = 0;
	int j = 0;
	int min_index = 0;
	int min_value = 0;
	for(i = 0; i < size -1 ; i++)
	{
		min_index = i;
		min_value = parray[i];
		for(j = i; j< size ;j++)
		{
			if(min_value > parray[j])
			{
				min_value = parray[j];
				min_index = j;
			}
			swap(&parray[i],&parray[min_index]);
		}
	}
}
