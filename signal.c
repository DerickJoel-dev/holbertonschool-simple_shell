#include "main.h"
/**
 * signal_handler - Handles Ctrl + C
 * @signal: The input signal
 */
void signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		printf("\nsimpleshell$ ");
	}
}
