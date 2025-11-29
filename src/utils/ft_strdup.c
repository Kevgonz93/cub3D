#include "../../includes/src.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*ptr;

        if (!s)
                return (NULL);
	len = ft_strlen(s) + 1;
	ptr = malloc(sizeof(char) * len);
	if (ptr == NULL)
		return (ptr);
	ft_strlcpy(ptr, s, sizeof(char) * len);
	return (ptr);
}