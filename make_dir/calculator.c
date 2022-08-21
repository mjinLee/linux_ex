// calculator.c

#include <stdio.h>
#include "addsub.h"
#include "muldiv.h"

int main(void){
	printf("2 + 5 = %d\n",add(2,5));
	printf("2 - 5 = %d\n",sub(2,5));
	printf("2 * 5 = %d\n",mul(2,5));
	printf("2 / 5 = %d\n",div(2,5));

	return 0;
}
