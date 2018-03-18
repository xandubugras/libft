/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 10:18:42 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/18 12:14:08 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*sizetoa_2(char *descriptor, va_list arg_pointer, int base);

char	*usizetoa_2(char *descriptor, va_list arg_pointer, int base);

char	*sizetoa(char *descriptor, va_list arg_pointer, int base)
{
	char		char_case;
	short		short_case;
	long		long_case;

	if (ft_strstr(descriptor, "hh"))
	{
		char_case = (char)va_arg(arg_pointer, int);
		return (ft_itoa_base((int)char_case, base));
	}
	else if (ft_strchr(descriptor, 'h'))
	{
		short_case = (short)va_arg(arg_pointer, int);
		return (ft_itoa_base((int)short_case, base));
	}
	else if (ft_strchr(descriptor, 'l'))
	{
		long_case = va_arg(arg_pointer, long);
		return (ft_ltoa_base((long long)long_case, base));
	}
	return (sizetoa_2(descriptor, arg_pointer, base));
}

char	*sizetoa_2(char *descriptor, va_list arg_pointer, int base)
{
	
	uintmax_t		uint_case;
	size_t			sizet_case;
	long long		ll_case;

	if (ft_strstr(descriptor, "j"))
	{
		uint_case = va_arg(arg_pointer, uintmax_t);
		return (ft_ultoa_base((long long)uint_case, base));
	}
	else if (ft_strchr(descriptor, 'z'))
	{
		sizet_case = va_arg(arg_pointer, size_t);
		return (ft_ultoa_base((long long)sizet_case, base));
	}
	else if (ft_strstr(descriptor, "ll"))
	{
		ll_case = va_arg(arg_pointer, long);
		return (ft_ltoa_base(ll_case, base));
	}
	else 
		return (ft_itoa_base(va_arg(arg_pointer, int), base));
}


char	*usizetoa(char *descriptor, va_list arg_pointer, int base)
{
	unsigned char		char_case;
	unsigned short		short_case;
	unsigned long		long_case;

	if (ft_strstr(descriptor, "hh"))
	{
		char_case = (char)va_arg(arg_pointer, int);
		return (ft_itoa_base((int)char_case, base));
	}
	else if (ft_strchr(descriptor, 'h'))
	{
		short_case = (short)va_arg(arg_pointer, int);
		return (ft_itoa_base((int)short_case, base));
	}
	else if (ft_strchr(descriptor, 'l'))
	{
		long_case = va_arg(arg_pointer, long);
		return (ft_ultoa_base((unsigned long long)long_case, base));
	}
	return (usizetoa_2(descriptor, arg_pointer, base));
}

char	*usizetoa_2(char *descriptor, va_list arg_pointer, int base)
{
	
	uintmax_t		uint_case;
	size_t			sizet_case;
	unsigned long long		ll_case;

	if (ft_strstr(descriptor, "j"))
	{
		uint_case = va_arg(arg_pointer, uintmax_t);
		return (ft_ultoa_base((long long)uint_case, base));
	}
	else if (ft_strchr(descriptor, 'z'))
	{
		sizet_case = va_arg(arg_pointer, size_t);
		return (ft_ultoa_base((long long)sizet_case, base));
	}
	else if (ft_strstr(descriptor, "ll"))
	{
		ll_case = va_arg(arg_pointer, long);
		return (ft_ultoa_base(ll_case, base));
	}
	else 
		return (ft_itoa_base(va_arg(arg_pointer, int), base));
}
