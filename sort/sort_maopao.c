extern void swap(int *pa,int *pb);

void sort_maopao(int *parray,int size)
{
	if(size < 2)
	{
		return;
	}
	int i = 0 ;// 外层循环变量
	int j = 0; // 内层循环变量
	for(i = 0; i < size -1;i++)
	{
		for(j = 0; j< size - i - 1; j++) // 适当优化后的冒泡排序
		//for(j = 0; j< size - 1; j++) // 最原始的冒泡排序
		{
			if(parray[j] > parray[j + 1])
			{
				swap(&parray[j],&parray[j+1]);
			}
		}
	}
	return;
}
