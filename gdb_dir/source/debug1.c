#include <stdio.h>

int sum(int i);

int main(void){
	printf("%d\n", sum(10));
}

int sum(int i){
	return i + sum(i-1);
}
