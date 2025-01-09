#include "main.h"
/**
 * signal_handler - Handles ctrl + c
 * @signal: The input signal
 */
void signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n#cisfun$ ");
	}
}
