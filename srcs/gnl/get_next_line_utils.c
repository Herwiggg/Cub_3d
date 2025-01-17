#include "get_next_line.h"

int	check_malloc(char *buffer)
{
	if (!buffer)
		return (0);
	return (1);
}

int	ft__strlen(const char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}
