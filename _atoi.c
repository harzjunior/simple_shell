#include "shell.h"

/**
* interactive - checks if the shell is in interactive mode
* @info: struct addr
* Return: 1 if the shell is in interactive mode, 0 otherwise
*/
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim - this checks if char is a delimeter
* @c: checks char
* @delim: delimeter string
* Return: 1 if the character is a delimiter, 0 otherwise
*/
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
* _isalpha - checks for alphabetic character
* @c: The character to input
* Return: 1 if c is alphabetic, 0 otherwise
*/

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
* _atoi - this converts string to integer
* @s: the converted string to be
* Return: 0 If there are no nums in the string, return 0. Otherwise converted num
*/

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

