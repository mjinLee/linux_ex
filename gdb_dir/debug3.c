#include <stdio.h>

int array[10];
int sum_all(int c);

int main(void)
{
	int i;

	for(i=0; i<5; i++)
	{
		printf("Input integer ==> ");
		scanf("%d", &(array[i]));
	}

	printf("Sum is %d\n", sum_all(0));
	return 0;
}

int sum_all(int c)
{
	int sum;

	if(c >= 5)
		return 0;
	else
	{
		sum = array[c] + sum_all(c++);
		return sum;
	}
}
