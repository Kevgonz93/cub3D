#include "../../includes/src.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	substr_len;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		substr_len = 0;
	else if (ft_strlen(s) - start < len)
		substr_len = ft_strlen(s) - start;
	else
		substr_len = len;
	ptr = malloc((sizeof(char) * (substr_len + 1)));
	if (ptr == NULL)
		return (NULL);
	else
	{
		if (start >= ft_strlen(s))
			ft_strlcpy(ptr, "", substr_len + 1);
		else
			ft_strlcpy(ptr, s + start, substr_len + 1);
		return (ptr);
	}
}
