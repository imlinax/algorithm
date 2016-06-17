/************************************
 * 测试sort类算法的主函数
 ***********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"
#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

#define CALL_SORT(sort_func,array,size) do {calc_sort_time(array,size,sort_func,#sort_func); \
    print_array(array,size);} while(0)


extern void calc_sort_time(int *parray,int size,	void (*sortfunc)(int *,int),char *funcname);
void print_array(int *parray,int size)
{
    return;
    for(int i = 0;i < size;i++)
    {
	printf("%d ",parray[i]);
    }
    printf("\n");

}
int main(void)
{
    //int array[] = {64,43,37,14,4,32,89,45,3,78,34};
    int size = 20000; 
    int *array = (int*)malloc(size*sizeof(int));
    int *array_backup = (int*)malloc(size*sizeof(int));
    srand(time(0));
    for(int index = 0; index < size; index++)
    {
	array[index] = rand() % 100;
    }
    memcpy(array_backup,array,size*sizeof(int));
    //int array[] = {64,43};
    printf("begin:\r\n");
    // 冒泡排序
    CALL_SORT(sort_maopao,array,size);
    // 选择排序
    memcpy(array,array_backup,size*sizeof(int));
    CALL_SORT(sort_select,array,size);

    // 插入排序
    memcpy(array,array_backup,size*sizeof(int));
    CALL_SORT(sort_insert,array,size);

    // 快速排序
    memcpy(array,array_backup,size*sizeof(int));
    CALL_SORT(sort_quick,array,size);

    // 希尔排序
    memcpy(array,array_backup,size*sizeof(int));
    CALL_SORT(sort_shell,array,size);

    // 归并排序
    memcpy(array,array_backup,size*sizeof(int));
    CALL_SORT(sort_merge,array,size);

    // 堆排序
    memcpy(array,array_backup,size*sizeof(int));
    CALL_SORT(sort_heap,array,size);


    free(array);
    free(array_backup);

    return 0;
}
