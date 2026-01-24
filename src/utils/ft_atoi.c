/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akwadran <akwadran@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:00:55 by akwadran          #+#    #+#             */
/*   Updated: 2026/01/24 16:00:56 by akwadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
