#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "find.h"
#include "sort.h"
void gen_randomarray(int *parray,int size)
{
    srand(time(0));
    for(int i = 0;i < size; ++i)
    {
	parray[i] = rand() % 10;
    }
}
void print_array(int *parray,int size)
{
    for(int i = 0;i < size ; ++i)
    {
	printf("%d ",parray[i]);
    }
    printf("\r\n");
}
int main()
{
    int arraysize = 10;
    int *parray = (int*)malloc(sizeof(int) * arraysize);
    // 生成随机数组
    gen_randomarray(parray,arraysize);
    // 打印数组  
    //print_array(parray,arraysize);
    //保存需要查找的数据
    int findindex = rand() % arraysize;
    int findval = parray[findindex];
	
    int findedindex = -1;
    findedindex = find_seq(parray,arraysize,findval);
    printf("find_seq    :finedindex:%d,realindex:%d\n",findedindex,findindex);
    // sort array
    sort_shell(parray,arraysize);
    print_array(parray,arraysize);
    findedindex = find_binary(parray,arraysize,findval);
    printf("find_binary :finedindex:%d,realindex:%d\n",findedindex,findindex);

    return 0;
}
