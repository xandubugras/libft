/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 14:42:33 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/19 19:44:37 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*set_num_final_2(t_descriptor *descriptor, va_list arg_pointer);

static char	*uset_num_final_2(t_descriptor *descriptor, va_list arg_pointer);

void	set_final(t_descriptor *descriptor, va_list arg_pointer)
{
	char				*c;

	if (!NOT_TYPE_S(descriptor->type))
		descriptor->final_content = va_arg(arg_pointer, char *);
	else if (!NOT_TYPE_C(descriptor->type) || descriptor->type == '%')
	{
		descriptor->final_content = malloc(sizeof(char));
		*(descriptor->final_content) = descriptor->type == '%' ? '%' : (char)va_arg(arg_pointer, int);
	}
	else if (descriptor->type == 'p')
	{
		descriptor->arg = (unsigned long long)va_arg(arg_pointer, unsigned long long *);
		descriptor->final_content = ft_ltoa_base(descriptor->arg, 16);
		c = descriptor->final_content;
		descriptor->final_content = ft_strjoin("0x", c);
		free(c);
	}
	else if (descriptor->type == 'u' || descriptor->type == 'U')
		uset_num_final(descriptor, arg_pointer);
	else if (descriptor->type == 'X' || descriptor->type == 'O')
		descriptor->final_content = ft_strupper(uset_num_final(descriptor, arg_pointer));
	else
		set_num_final(descriptor, arg_pointer);
}

char	*set_num_final(t_descriptor *descriptor, va_list arg_pointer)
{
	char		char_case;
	short		short_case;
	long		long_case;
	int			base;

	base = descriptor->base;
	if (descriptor->length == HH)
	{
		char_case = (char)va_arg(arg_pointer, int);
		descriptor->final_content = ft_itoa_base((int)char_case, base);
	}
	else if (descriptor->length == H)
	{
		short_case = (short)va_arg(arg_pointer, int);
		descriptor->final_content = ft_itoa_base((int)short_case, base);
	}
	else if (descriptor->length == L)
	{
		long_case = va_arg(arg_pointer, long);
		descriptor->final_content = ft_ltoa_base((long long)long_case, base);
	}
	else
		return (set_num_final_2(descriptor, arg_pointer));
	return (descriptor->final_content);
}

static char	*set_num_final_2(t_descriptor *descriptor, va_list arg_pointer)
{

	uintmax_t		uint_case;
	size_t			sizet_case;
	long long		ll_case;
	int				base;

	base = descriptor->base;
	if (descriptor->length == J)
	{
		uint_case = va_arg(arg_pointer, uintmax_t);
		descriptor->final_content = ft_ultoa_base((long long)uint_case, base);
	}
	else if (descriptor->length == Z)
	{
		sizet_case = va_arg(arg_pointer, size_t);
		descriptor->final_content = ft_ultoa_base((long long)sizet_case, base);
	}
	else if (descriptor->length == LL)
	{
		ll_case = va_arg(arg_pointer, long long);
		descriptor->final_content = (ft_ltoa_base(ll_case, base));
	}
	else
		descriptor->final_content = ft_itoa_base(va_arg(arg_pointer, int), base);
	return (descriptor->final_content);
}


char	*uset_num_final(t_descriptor *descriptor, va_list arg_pointer)
{
	unsigned char		char_case;
	unsigned short		short_case;
	unsigned long		long_case;
	int					base;

	base = descriptor->base;
	if (descriptor->length == HH)
	{
		char_case = (unsigned char)va_arg(arg_pointer, unsigned int);
		descriptor->final_content = (ft_itoa_base((unsigned int)char_case, base));
	}
	else if (descriptor->length == H)
	{
		short_case = (unsigned short)va_arg(arg_pointer, unsigned int);
		descriptor->final_content = (ft_itoa_base((unsigned int)short_case, base));
	}
	else if (descriptor->length == L)
	{
		long_case = va_arg(arg_pointer, unsigned long);
		descriptor->final_content = (ft_ultoa_base((unsigned long long)long_case, base));
	}
	else
		return (uset_num_final_2(descriptor, arg_pointer));
	return (descriptor->final_content);
}

static char	*uset_num_final_2(t_descriptor *descriptor, va_list arg_pointer)
{

	uintmax_t		uint_case;
	size_t			sizet_case;
	unsigned long long		ll_case;
	int						base;

	base = descriptor->base;
	if (descriptor->length == J)
	{
		uint_case = va_arg(arg_pointer, uintmax_t);
		descriptor->final_content = (ft_ultoa_base((unsigned long long)uint_case, base));
	}
	else if (descriptor->length == Z)
	{
		sizet_case = va_arg(arg_pointer, size_t);
		descriptor->final_content = (ft_ultoa_base((unsigned long long)sizet_case, base));
	}
	else if (descriptor->length == LL)
	{
		ll_case = va_arg(arg_pointer, unsigned long long);
		descriptor->final_content = (ft_ultoa_base(ll_case, base));
	}
	else
		descriptor->final_content = (ft_ultoa_base(va_arg(arg_pointer, unsigned int), base));
	return (descriptor->final_content);
}
