#include "../../includes/src.h"

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*ptr;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(sizeof(char) * (len + 1));
	if (s1 == NULL || s2 == NULL || ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] && i < len)
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}
