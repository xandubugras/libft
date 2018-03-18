/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:41:07 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/17 19:41:57 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*convert_to_string(va_list arg_pointer);

char		*handle_descriptor(char *descriptor, va_list arg_pointer)
{
	void	*c;
	char	*final_string;

	c = arg_pointer;
	if (ft_strcmp(descriptor, "%") == 0)
		return ("%");
	//substitute * doesnt work with more than 9
	final_string = arg_to_string(descriptor, arg_pointer);
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

	if (descriptor[0] == '0')
		fill = '0';
	else
		fill = ' ';
	max = ft_atoi(&descriptor[0]);
	ft_mod(&max);
	len = ft_strlen(current_str);
	if (max > len)
	{
		padded = ft_strnew(max);
		max -= len;
		i = 0;
		if (descriptor[0] == '-')
		{
			while (i < len)
			{
				padded[i] = current_str[i];
				i++;
			}
			i = 0;
			while (i < max)
			{
				padded[len + i] = fill;
				i++;
			}
		}
		else
		{
			while (i < max)
			{
				padded[i] = fill;
				i++;
			}
			i = 0;
			while (i < len)
			{
				padded[max + i] = current_str[i];
				i++;
			}
		}
		free(current_str);
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
			dot_location[precision] = '\0';
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



















