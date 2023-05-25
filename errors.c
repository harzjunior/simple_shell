#include "shell.h"

/**
  _eputs: shows input str
* @str: output str to be shown
*
* Return: Null
*/
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
* _eputchar - Writes the character 'c' to the standard error (stderr).
* @c: Character to be printed
*
* Return: 1 on succcess
* On error, The value of -1 is returned, and the errno variable is set accordingly.
*/
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - Writes the character 'c' to the specified file descriptor (fd).
 * @c: Char to be printed
 * @fd: File descriptor to write to.
 *
 * Return: 1 success
 * On error, The value of -1 is returned, and the errno variable is set accordingly.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - Prints the specified input string.
 * @str: The string to be printed.
 * @fd: File descriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
