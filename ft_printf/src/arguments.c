/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:42:33 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/15 15:21:41 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*arg_to_string(char *descriptor, va_list arg_pointer)
{
	char	*c;
	int		tmp;

	if (ft_strchr(descriptor, 'd'))
	{
		tmp = va_arg(arg_pointer, int);
		if (sizeof(tmp) != sizeof(int))
		{
			ft_printf("argument %d is not int");
			return (0);
		}
		return (ft_itoa(tmp));
	}
	if (ft_strchr(descriptor, 's'))
		return (va_arg(arg_pointer, char *));
	if ((ft_strchr(descriptor, 'c')))
	{
		c = malloc(sizeof(char));
		*c = (char)va_arg(arg_pointer, int);
		return (c);
	}
	return (0);
}
