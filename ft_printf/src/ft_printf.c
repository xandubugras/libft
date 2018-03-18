/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 09:02:03 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/17 19:36:59 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int		count_args(char *format);

int				get_arg(va_list arg_pointer, char *arg_descriptor);

char			*separate_descriptor(char **format);

int				ft_printf(char *format, ...)
{
	va_list	arg_pointer;
	int		number_of_args;
	char	*current_descriptor;
	char	*c;
	int		i;

	number_of_args = count_args(format);
    va_start(arg_pointer, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			current_descriptor = separate_descriptor(&format);
			while ((strchr(current_descriptor, '*')) != NULL)
			{
				i = 0;
				while (current_descriptor[i] != '*')
					i++;
				c = ft_itoa(va_arg(arg_pointer, int)); 
				ft_strinsert_sub(&current_descriptor, c, i);
				free (c);
			}
			ft_putstr(handle_descriptor(current_descriptor, arg_pointer));
			format++;
		}
		else
		{
			ft_putchar(*format);
			format++;
		}
	}
	get_arg(arg_pointer, format);
	va_end(arg_pointer);
	return (0);
}

static int		count_args(char *format)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count++;
			if (format[i + 1] == '%')
				i++;
		}
		i++;
	}
	return (count);
}

char			*separate_descriptor(char **format)
{
	int i;
	char *str;

	i = 0;
	(*format)++;
	str = *format;
	while (is_format_letter(str[i]) == 0)
	{
		i++;
	}
	*format += i;
	return (ft_strsub(str, 0, i + 1));	
}

int		is_format_letter(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D')
		return (c);
	if (c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U') 
		return (c);
	if (c == 'x' || c == 'X' || c == 'c' || c == 'C')
		return (c);
	if (c == 'e' || c == 'E' || c == 'f' || c == 'F' || c == 'g' || c == 'G')
		return (c);
	if (c == 'a' || c == 'A' || c ==  'n' || c == '%')
		return (c);
	return (0);
}

int		get_arg(va_list arg_pointer, char *arg_descriptor)
{
	void *returner;
	int d;
	int sum;
	int i;

	sum = 0;
	i = 0;
	d = 0;
	returner = NULL;
	if (ft_strchr(arg_descriptor, 'd'))
	{
		d = va_arg(arg_pointer, int);
		printf("\n\n%d\n\n", d);
		returner = &d;
	}
	//else if (ft_strchr(arg_descriptor
	return (d);
}






















