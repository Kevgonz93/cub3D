#include "../includes/src.h"

void	print_config(t_config *config)
{
	printf("NO: %s\n", config->no_tex);
	printf("SO: %s\n", config->so_tex);
	printf("WE: %s\n", config->we_tex);
	printf("EA: %s\n", config->ea_tex);
	printf("F: %X\n", config->floor_color);
	printf("C: %X\n", config->ceil_color);
}

void	print_array(char** array)
{
	int	i;

	if (!array)
		return ;
	printf("Printning array\n\n");
	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}
