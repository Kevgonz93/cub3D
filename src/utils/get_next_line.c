#include "../../includes/src.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

static int	has_new_line(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static char	*read_file(int fd, char *storage)
{
	ssize_t	bytes_read;
	char	*buffer;
	int		n;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	n = 0;
	while (n < BUFFER_SIZE)
		buffer[n++] = 'a';
	bytes_read = 1;
	while (bytes_read > 0 && !has_new_line(buffer))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(storage);
			return (storage = ft_strdup(""), free(buffer), storage);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	return (free(buffer), storage);
}

static char	*fill_line(const char *storage)
{
	char	*line;
	int		i;

	if (storage == NULL)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*move_storage(char *storage)
{
	char	*aux;
	int		index;
	int		len;

	if (storage == NULL)
		return (NULL);
	index = 0;
	len = 0;
	while (storage[index] && storage[index] != '\n')
		index++;
	if (storage[index] == '\n')
		index++;
	while (storage[index + len])
		len++;
	aux = ft_substr(storage, index, len);
	free(storage);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (storage == NULL)
		storage = ft_strdup("");
	storage = read_file(fd, storage);
	line = fill_line(storage);
	storage = move_storage(storage);
	if (line[0] == '\0')
	{
		free(line);
		free(storage);
		line = NULL;
		storage = NULL;
	}
	return (line);
}
