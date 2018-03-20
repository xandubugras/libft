/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_descriptor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 21:25:04 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/19 19:41:12 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			set_descriptor(char **format, va_list arg_pointer, t_descriptor *descriptor)
{
	descriptor->description = separate_descriptor(format);
	handle_star(&(descriptor->description), arg_pointer);
	descriptor->type = descriptor->description[ft_strlen(descriptor->description) - 1];
	set_base(descriptor);
	set_format_flags(descriptor);
	set_precision(descriptor);
	set_width(descriptor);
	set_length(descriptor);
	set_final(descriptor, arg_pointer);
	if (descriptor->final_content[0] == '-')
	{
		descriptor->negative = 1;
		descriptor->precision++;
		ft_strremove_char(&(descriptor->final_content), 0);
	}
	else
		descriptor->negative = 0;
	return (check_input_errors(descriptor));
}

void			set_format_flags(t_descriptor *descriptor)
{
	char	*dsc;
	char	*zero;

	dsc = descriptor->description;
	if (ft_strchr(dsc, '+'))
		descriptor->plus = 1;
	else
		descriptor->plus = 0;
	if (ft_strchr(dsc, '-'))
		descriptor->minus = 1;
	else
		descriptor->minus = 0;
	if (ft_strchr(dsc, '#'))
		descriptor->hash = 1;
	else
		descriptor->hash = 0;
	if ((zero = ft_strchr(dsc, '0')) && !ft_isdigit(*(zero - 1)) && *(zero - 1) != '.')
		descriptor->zero = 1;
	else
		descriptor->zero = 0;
	if (ft_strchr(dsc, ' '))
		descriptor->space = 1;
	else
		descriptor->space = 0;
}

char			*separate_descriptor(char **format)
{
	int i;
	char *str;

	i = 0;
	(*format)++;
	str = *format;
	while (is_format_letter(str[i]) == 0 && str[i])
		i++;
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

int				check_input_errors(t_descriptor *descriptor)
{
	char	*dsc;
	int		type;

	dsc = descriptor->description;
	type = descriptor->type;
	if (descriptor->hash)
		if (descriptor->plus || (NOT_TYPE_O(type) && NOT_TYPE_X(type)))
			return (1);
	if (descriptor->plus)
		if (NOT_TYPE_D(type))
			return (1);
	if (descriptor->zero)
		if (descriptor->minus || !NOT_TYPE_C(type) || !NOT_TYPE_S(type) || type == 'p')
			return (1);
	if (descriptor->length != 0 && (descriptor->type == 'p' || !NOT_TYPE_C(type) || !NOT_TYPE_S(type)))
		return (1);
	return (0);
}
