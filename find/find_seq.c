/*顺序查找算法
 ** 参数：
 ** parray,待查找的数组
 ** size,待查找数组的大小
 ** findval,待查找的数据
 ** 返回值：
 ** 查找到则返回对应下标，否则返回-1
 */
int find_seq(int *parray,int size,int findval)
{
    for(int i = 0; i < size ; ++i)
    {
	if(parray[i] == findval)
	{
	    return i;
	}
    }
    return -1;
}
