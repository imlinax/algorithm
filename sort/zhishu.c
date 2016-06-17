#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool zhishu(int val)
{
	int i = 2;
	while(i < sqrt(val))
	{
		if(val % i == 0)
		{
			return false;
		}
		i++;
	}
	return true;
}
int get_max_zhishu(int n)
{
	if(n < 2)
	{
		return 1;
	}
	
	int m = n;
	while(m--)
	{
		if(zhishu(m))
		{
			return m;
		}
	}
}

int main(int argc,int **argv)
{
	int N = 1000*1000*20;
	
	printf("max  = %d\n",get_max_zhishu(N));
	return 0;
}
