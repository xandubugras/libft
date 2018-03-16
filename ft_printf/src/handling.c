/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:41:07 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/16 15:28:41 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*handle_flags(char *descriptor);

char		*convert_to_string(va_list arg_pointer);

char		*handle_plus(char *descriptor, char *current_str);

char		*handle_padding(char *descriptor, char *current_str);

char		*handle_precision(char *descriptor, char *current_str);

char		*handle_descriptor(char *descriptor, va_list arg_pointer)
{
	void	*c;
	char	*final_string;

	c = arg_pointer;
	if (ft_strcmp(descriptor, "%") == 0)
		return ("%");
	//substitute * doesnt work with more than 9
	final_string = arg_to_string(descriptor, arg_pointer);
	final_string = handle_plus(descriptor, final_string);
	final_string = handle_padding(descriptor, final_string);
	final_string = handle_precision(descriptor, final_string);
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
	int		j;
	int		i;
	int		len;
	int		sign;

	if ((dot_location = ft_strchr(descriptor, '.')) != NULL)
	{
		dot_location++; //next one after dot
		precision = ft_atoi(dot_location); // gets size of precision
		i = 0;
		while (!ft_isdigit_sign(current_str[i])) // checking if the precision is equal or smaller than the number
			i++;
		i = ft_strlen(&current_str[i]);
		if (i > precision)
			return (current_str);
		sign = '0';
		if (ft_strchr(current_str, '-') || ft_strchr(current_str, '+')) //checking if there is need for '-' or '+'
		{
			precision++;
			sign = ft_strchr(current_str, '-') ? '-' : '+';
		}
		len = ft_strlen(current_str);
		if (len < precision) // if the current lenght is smaller, allocate more mem
		{
			dot_location = ft_strnew(precision);
			ft_strncpy(&dot_location[precision - len], current_str, len);
			i = 0;
			while (!ft_isdigit_sign(dot_location[i]))
				dot_location[i++] = ' ';
			free(current_str);
			current_str = dot_location;
		}
		j = ft_strlen(current_str) - 1;
		while (precision > 0) //setting to 0 everything that is not a number
		{
			if (!ft_isdigit(current_str[j]))
				current_str[j] = '0';
			j--;
			precision--;
		}
		current_str[j + 1] = sign; // putting sign at the right position
	}
	return (current_str);
}



















