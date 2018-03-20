/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:41:07 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/19 19:45:37 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		format_content(t_descriptor *descriptor)
{
	if (descriptor->type == '%')
	{
		handle_padding(descriptor);
		handle_minus(descriptor);
		return ;
	}
	handle_precision(descriptor);
	handle_padding(descriptor);
	handle_plus_space(descriptor);
	if (descriptor->hash)
	{
		if (descriptor->precision)
			handle_hashtag_precision(descriptor);
		else
			handle_hashtag_zero(descriptor);
	}
	handle_minus(descriptor);
}

void		handle_precision(t_descriptor *descriptor)
{
	char	*new_str;
	char	*aux;
	int		i;
	int		len;

	if (descriptor->precision)
	{
		aux = descriptor->final_content;
		if (descriptor->negative)
			aux++;
		len = ft_strlen(aux);
		if (len < descriptor->precision)
		{
			new_str = ft_strnew(descriptor->precision);
			i = 0;
			while (i < (descriptor->precision - len))
				new_str[i++] = '0';
			ft_strncpy(&new_str[i], aux, len);
			descriptor->final_content = new_str;
		}
		else if (!NOT_TYPE_S(descriptor->type) && len > descriptor->precision)
		{
			new_str = ft_strnew(descriptor->precision);
			ft_strncpy(new_str, descriptor->final_content, descriptor->precision);
			descriptor->final_content = new_str;
		}
	}
}

void		handle_padding(t_descriptor *descriptor)
{
	char	fill;
	int		i;
	char	*new_str;
	int		len;

	len = ft_strlen(descriptor->final_content);
	fill = ' ';
	if (descriptor->zero)
		fill = '0';
	if (descriptor->width > len)
	{
		new_str = ft_strnew(descriptor->width);
		i = 0;
		while (i < (descriptor->width - len))
			new_str[i++] = fill;
		ft_strncpy(&new_str[i], descriptor->final_content, len);
		descriptor->final_content = new_str;
	}
}

void		handle_plus_space(t_descriptor *descriptor)
{
	char	*str;
	char	fill;
	int		i;

	fill = descriptor->negative ? '-' : '+';
	if (descriptor->space && fill == '+')
		fill = ' ';
	if (descriptor->negative || descriptor->plus || descriptor->space)
	{
		str = descriptor->final_content;
		i = 0;
		while (!ft_isdigit(str[i]))
			i++;
		if (str[i] == '0' && descriptor->zero)
			str[i] = fill;
		else if (i > 0 && str[i - 1] == ' ')
			str[i - 1] = fill;
		else if (str[i] == '0' && descriptor->precision)
			descriptor->final_content = ft_strinsert_char(&(descriptor->final_content), fill, i);
		else
		{
			descriptor->final_content = ft_strinsert_char(&(descriptor->final_content), fill, 0);
		}
	}
}
