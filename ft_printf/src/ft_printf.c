/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 09:02:03 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/19 19:52:29 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	print_descriptor(t_descriptor *d);

int				ft_printf(char *format, ...)
{
	va_list			arg_pointer;
	t_descriptor	*descriptor;
	int				printed_characters;

    va_start(arg_pointer, format);
	printed_characters = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			descriptor = malloc(sizeof(t_descriptor));
			set_descriptor(&format, arg_pointer, descriptor);
			format_content(descriptor);		
			//print_descriptor(descriptor);
			printed_characters += ft_strlen(descriptor->final_content);
			ft_putstr(descriptor->final_content);
			free(descriptor);
		}
		else
		{
			ft_putchar(*format);
			printed_characters++;
		}
		format++;
	}
	va_end(arg_pointer);
	return (printed_characters);
}

void	print_descriptor(t_descriptor *d)
{
	printf("description: %s\nprinted: %d\nplus: %d\nminus: %d\nhash:%d\nzero: %d\nspace: %d\nwidth: %d\nlength: %d\nprecision: %d\ntype: %d\nargument: %lld\nbase: %d\n%s\n", d->description, d->printed_characters, d->plus, d->minus, d->hash, d->zero, d->space, d->width, d->length, d->precision, d->type, d->arg, d->base, d->final_content);
}	
