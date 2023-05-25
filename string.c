#include "shell.h"

/**
* _strlen - returns the len of str.
* @s: the str. len to check
* Return: int len. of str.
*/
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
* _strcmp - works with lexicogarphic compare of 2 str.
* @s1: 1rst strang
* @s2: 2nd strang
* Return: -ve if s1 < s2, +ve if s1 > s2, 0 if s1 == s2
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
* starts_with - checks wether the needle commence with haystack
* @haystack: str. to search
* @needle: substring to be looked at
* Return: addr. of nxt char of haystack or NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
* _strcat - concat 2 str.
* @dest: dest. buf
* @src: src buf
* Return: ptr to dest. buf.
*/
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
