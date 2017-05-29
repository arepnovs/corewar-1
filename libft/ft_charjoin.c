
#include "libft.h"

char        *ft_charjoin(const char *s1, const char s2)
{
	size_t    i;
	char    *res;

	i = 0;
	if (s1 && s2)
	{
		res = (char *)malloc((ft_strlen(s1) + 2) * sizeof(char));
		if (!res)
			return (NULL);
		while (s1[i] != '\0')
		{
			res[i] = s1[i];
			i++;
		}
		res[i] = s2;
		i++;
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}