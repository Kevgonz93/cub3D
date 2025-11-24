/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonza <kegonzal@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:23:58 by kegonza           #+#    #+#             */
/*   Updated: 2025/11/23 17:10:56 by kegonza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/src.h"

int	error(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen((char *)msg));
	write(2, "\n", 1);
	return (1);
}

int	error_sys(char *context)
{
	char	*sys_msg;

	sys_msg = strerror(errno);
	write(2, "Error\n", 6);
	write(2, context, ft_strlen(context));
	write(2, ": ", 2);
	write(2, sys_msg, ft_strlen(sys_msg));
	write(2, "\n", 1);
	return (1);
}
