#include <math.h>
#include <stdio.h>

/*打印堆，for test,仅仅打印少量时使用*/
void print_heap(int *parray,int size)
{
    int level = log(size)/log(2);
    printf("level = %d\n",level);
    int i = 0;
    int *pdata = parray;
    while(i <= level)
    {
	for(int j=0;j < powl(2,level-i)-1; j++)
	{
	    printf("   ");	
	}
	printf("%3d",*pdata++);
	for(int j = 1;j < powl(2,i) && (pdata < parray+size) ;j++)
	{
	    for(int k = 0; k < powl(2,level-i+1)-1;k++)
	    {
		printf("   ");
	    }
	    printf("%3d",*pdata++);
	}
	printf("\n");
	i++;
    }
}

/*调整堆,假定只有根节点不满足堆的性质*/
void adjust_heap(int *parray,int start,int end)
{
    int parent = start;
    int max_value = parray[start];
    int left = 2*parent + 1;
    int right = 2*parent + 2;
    while(left <= end)
    {
	int max_index = left;
	if(left < end && parray[right] > parray[left])
	{
	    max_index = right;
	  //  max_value = parray[2*i+1];
	}
	if(max_value > parray[max_index])
	{
	    break;
	}
	else
	{
	    parray[parent] = parray[max_index];
	    parray[max_index] = max_value;
	}
	parent = max_index;
	left = 2*parent + 1;
	right = 2*parent + 2;
    }
    return;
}

/*建立堆*/ 
void build_heap(int *parray,int size)
{
    int index = size/2; // 最后一个非叶子节点，也就是最后一个节点的parent
    while(index >=0)
    {
	adjust_heap(parray,index,size-1);
	index--;
    }
    return;
}
/*堆排序*/
void sort_heap(int *parray,int size) {
 //   print_heap(parray,size);
    build_heap(parray,size);
    for(int i = size - 1;i > 0; i--)
    {
	int tmp = parray[i];
	parray[i] = parray[0];
	parray[0] = tmp;
	adjust_heap(parray,0,i-1);
    }
//    print_heap(parray,size);
    return;
}
