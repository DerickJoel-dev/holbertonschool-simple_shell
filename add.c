#include "main.h"

int main(void)
{
	int a = 3;
	int b = 5;
	int sum = a + b;
	
	pid_t pid;

	pid = getpid();

		printf("sum is %i\n", sum);
		printf("pid is %i\n", pid);

	return 0;
}
