#include <stdbool.h>
#include <math.h>
/*
* parray:需要排序的总数组
* size: 需要排序的子数组中数据的个数
* dist: 子数组中每个数据在原始数组中的间隔
*/

void sort_insert_dist(int *parray,int size,int dist)
{
	int i = 0; 
	int j = 0;
	int value = 0;
	for(i = 1; i < size ; i++)
	{
		value = parray[i*dist];
		for(j = i-1; j >= 0; j--)
		{
			if(value < parray[j*dist])
			{
				parray[(j+1)*dist] = parray[j*dist];
			}
			else
			{
				break;
			}
		}
		parray[(j+1)*dist] = value;
	}
	return;

}
void sort_shell(int *parray,int size)
{
	int dist = size / 2;
	int i = 0;
	while(dist >= 1)
	{
		for( i = 0; i < dist ; i++)
		{
			sort_insert_dist(parray+i,size/dist,dist);	
		}
		//dist /= 2; //希尔增量
		dist /= 2;
	}
}
	
void sort_shell1(int *parray,int size)
{
	if(size < 2)
	{
		return ;
	}
	int dist = size/2; //希尔排序的增量
	int i = 0; // 外层循环变量
	int j = 0; // 内层循环变量
	int k = 0;
	int tempval = 0;
	while(dist >= 1)
	{
		for(i = 0 ; i < dist; i++ )
		{
			int newsize = size/dist;
			for(j = 1 ; j < newsize ; j++)
			{
				tempval = parray[newsize*dist];
				k = j-1;
				while(parray[k*dist] > tempval)
				{
					parray[k*dist+1] = parray[k*dist];
					k--;
				}
				parray[k*dist] = tempval;
			}
		}
		dist /= 2;	
	}
}
