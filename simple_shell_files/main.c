#include "main.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: 0 on success, or -1 on error.
 */
int main(void)
{
	int ex = 0;

	if (!isatty(STDIN_FILENO))
		ex = process_non_interactive();
	else
		ex = process_interactive();

	return (ex);
}
