#include <stdio.h>

int sum(int i);

int main(void)
{
	int s;

	s = sum(10);
	printf("%d \n",s);
}

int sum(int i)
{
	if(i <=0)
		return 0;
	else
		return i+sum(i-1);
}
