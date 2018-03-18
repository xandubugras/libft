/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:42:33 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/18 11:24:39 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*more_arg_to_string(char *descriptor, va_list arg_pointer);

char	*arg_to_string(char *descriptor, va_list arg_pointer)
{
	char				*c;
	char				*aux;

	if (descriptor == 0)
		return (0);
	if (ft_strchr(descriptor, 's'))
		return (va_arg(arg_pointer, char *));
	if ((ft_strchr(descriptor, 'c') || ft_strchr(descriptor, 'C')))
	{
		c = malloc(sizeof(char));
		*c = (char)va_arg(arg_pointer, int);
		return (c);
	}
	if ((ft_strchr(descriptor, 'p')))
	{
		c = ft_ltoa_base((unsigned long long)va_arg(arg_pointer, unsigned long long *), 16);
		aux = ft_strjoin("0x", c);
		free(c);
		return (aux);
	}
	return (more_arg_to_string(descriptor, arg_pointer));
}

char	*more_arg_to_string(char *descriptor, va_list arg_pointer)
{
	char	*aux;

	aux = 0;
	if (ft_strchr(descriptor, 'd') || ft_strchr(descriptor, 'i'))
	{
		aux = sizetoa(descriptor, arg_pointer, 10);
		aux = handle_plus(descriptor, aux);
	}
	if ((ft_strchr(descriptor, 'u')))
	{
		aux = usizetoa(descriptor, arg_pointer, 10);
		aux = handle_plus(descriptor, aux);
	}
	if (ft_strchr(descriptor, 'x'))
		aux = ft_itoa_base(va_arg(arg_pointer, int), 16);
	if (ft_strchr(descriptor, 'X'))
		aux = ft_strupper(sizetoa(descriptor, arg_pointer, 16));
	if (ft_strchr(descriptor, 'o'))
		aux = sizetoa(descriptor, arg_pointer, 8);
	if (ft_strchr(descriptor, 'O'))
		aux = ft_strupper(sizetoa(descriptor, arg_pointer, 8));
	if (aux != 0)
	{
		aux = handle_precision(descriptor, aux);
		aux = handle_hashtag(descriptor, aux);
		aux = handle_padding(descriptor, aux);
		return (aux);
	}
	return (0);
}

