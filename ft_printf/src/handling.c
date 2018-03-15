/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:41:07 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/15 15:11:42 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char		*handle_flags(char *descriptor);

char		*convert_to_string(va_list arg_pointer);

char		*handle_descriptor(char *descriptor, va_list arg_pointer)
{
	void	*c;
	char	*final_string;
	//char	*string_arg;

	c = arg_pointer;
	if (ft_strcmp(descriptor, "%") == 0)
		return ("%");
	final_string = arg_to_string(descriptor, arg_pointer);
	return (final_string);
}


