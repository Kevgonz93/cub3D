#include "../../includes/src.h"

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		if (sign == 1 && (num > (INT_MAX - (*nptr - '0')) / 10))
			return (INT_MAX);
		if (sign == -1 && (num > (-(INT_MIN + (*nptr - '0')) / 10)))
			return (INT_MIN);
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (num * sign);
}
