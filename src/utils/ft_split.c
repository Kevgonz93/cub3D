#include "../../includes/src.h"

static int	split_strlen(char c, char const *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	split_count(char const *s, char c)
{
	int	count;
	int	new_string;

	new_string = 0;
	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
			new_string = 0;
		else if (*s != c && new_string == 0)
		{
			new_string = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	**init_array(char const *s, int count, char c)
{
	char	**array;
	int		i;

	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s != '\0' && *s == c)
			s++;
		array[i] = (char *)malloc(sizeof(char) * split_strlen(c, s));
		if (array[i] == NULL)
		{
			free_array(array);
			return (NULL);
		}
		while (*s != '\0' && *s != c)
			s++;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**array;
	int		i;

	count = split_count(s, c);
	array = init_array(s, count, c);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (array[i] != NULL)
	{
		while (*s != '\0' && *s == c)
			s++;
		ft_strlcpy(array[i], s, split_strlen(c, s) + 1);
		while (*s != '\0' && *s != c)
			s++;
		i++;
	}
	return (array);
}
