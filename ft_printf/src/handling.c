/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:41:07 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/15 22:05:30 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*handle_flags(char *descriptor);

char		*convert_to_string(va_list arg_pointer);

char		*handle_plus(char *descriptor, char *current_str);

char		*handle_padding(char *descriptor, char *current_str);

char		*handle_descriptor(char *descriptor, va_list arg_pointer)
{
	void	*c;
	char	*final_string;

	c = arg_pointer;
	if (ft_strcmp(descriptor, "%") == 0)
		return ("%");
	final_string = arg_to_string(descriptor, arg_pointer);
	final_string = handle_plus(descriptor, final_string);
	final_string = handle_padding(descriptor, final_string);
	return (final_string);
}

char		*handle_padding(char *descriptor, char *current_str)
{
	char	fill;
	int		i;
	int		max;
	char	*padded;
	int		len;

	i = 0;
	if (descriptor[i] == '0')
		fill = '0';
	else
		fill = ' ';
	max = ft_atoi(&descriptor[i]);
	len = ft_strlen(current_str);
	if (max > len)
	{
		padded = malloc(sizeof(char) * max);
		max -= len;
		while (i < max)
		{
			padded[i] = fill;
			i++;
		}
		i = 0;
		while (i < max + len)
		{
			padded[max + i] = current_str[i];
			i++;
		}
		return (padded);
	}
	return (current_str);
}

char		*handle_plus(char *descriptor, char *current_str)
{
	char *str;

	if (ft_strchr(descriptor, '+'))
	{
		if (ft_strchr(current_str, '-'))
		{
			return (current_str);
		}
		else
		{
			str = ft_strjoin("+", current_str);
			free(current_str);
		}
		return (str);
	}
	return (current_str);
}

char		*handle_precision(char *descriptor, char *current_str)
{
	int		precision;
	char	*dot_location;
	int		i;
	int		j;
	int		len;

	if ((dot_location = ft_strchr(descriptor, '.')) != NULL)
	{
		dot_location++;
		precision = ft_atoi(dot_location);
		len = ft_strlen(current_str);
		if (len < precision)
		{
			if (ft_strchr(current_str, '-') || ft_strchr(current_str, '+'))
				precision++;
			dot_location = ft_strnew(precision);
			ft_strncpy(&dot_location[precision - len], current_str, len);
			free(current_str);
			current_str = dot_location;
		}
		j = ft_strlen(current_str) - 1;
		i = 0;
		while (current_str[i] < '0' && current_str[i] > '9')
			i++;
		// preencher tudo antes dos numeros com 0s
		// fazer nada caso a len de numeros seja maior que a precisao
	}
	return (current_str);
}
