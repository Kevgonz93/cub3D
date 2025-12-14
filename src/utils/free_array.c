#include "../../includes/src.h"

void	free_array(char **array)
{
	int	i;

        if (!array)
                return ;
	i = 0;
	while (array[i])
        {
		free(array[i]);
                array[i] = NULL;
                i++;
        }
        free(array);
        array = NULL;
}
