#include "../../includes/src.h"

static int	get_n_lines(char *file)
{
	int		fd;
	int		n_lines;
	char	tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error("Map can´t be opened"), -1);
	n_lines = 0;
	while (read(fd, &tmp, sizeof(char)) > 0)
	{
		if (tmp == '\n')
			n_lines++;
	}
	close(fd);
	return (++n_lines);
}

static char	*rm_trailing_newline(char *line)
{
	char	*new;

	if (line[ft_strlen(line) - 1] == '\n')
	{
		new = (char *)malloc(sizeof(char) * ft_strlen(line));
		ft_strlcpy(new, line, ft_strlen(line));
	}
	else
		new = ft_strdup(line);
	return (new);
}

static void	fill_out_buffer(char **buffer, int fd)
{
	int	i;
	char	*tmp;

	if (!buffer)
		return ;
	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		buffer[i] = rm_trailing_newline(tmp);
		free(tmp);
		//printf("%s", buffer[i]); // QUITAR
		i++;
	}
}

char	**get_lines(char *file)
{
	int		fd;
	char	**buffer;
	int		buffer_size;

	buffer_size = get_n_lines(file);
	if (buffer_size == -1)
		return (NULL);
	buffer = (char **)malloc(sizeof(char *) * (buffer_size + 1));
	if (!buffer)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		error("Map can´t be opened");
		free_array(buffer);
		return (NULL);
	}
	fill_out_buffer(buffer, fd);
	close(fd);
	return (buffer);
}
