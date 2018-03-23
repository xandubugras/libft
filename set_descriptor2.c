/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_descriptor2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 08:16:57 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/22 19:27:29 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

void	set_length(t_descriptor *descriptor)
{
	if (ft_strstr(descriptor->description, "hh"))
		descriptor->length = HH;
	else if (ft_strchr(descriptor->description, 'h'))
		descriptor->length = H;
	else if (ft_strstr(descriptor->description, "ll"))
		descriptor->length = LL;
	else if (ft_strchr(descriptor->description, 'l'))
		descriptor->length = L;
	else if (ft_strstr(descriptor->description, "j"))
		descriptor->length = J;
	else if (ft_strchr(descriptor->description, 'z'))
		descriptor->length = Z;
	else
		descriptor->length = 0;
}

void	set_width(t_descriptor *descriptor)
{
	char *dsc;

	dsc = descriptor->description;
	while ((!ft_isdigit(*dsc) && *dsc) || *dsc == '0')
		dsc++;
	if (*(dsc - 1) != '.')
		descriptor->width = ft_return_mod(ft_atoi(dsc));
	else
		descriptor->width = 0;
}

void	set_precision(t_descriptor *descriptor)
{
	char *dsc;

	if ((dsc = ft_strchr(descriptor->description, '.')) != 0)
	{
		dsc++;
		descriptor->precision = ft_atoi(dsc);
		descriptor->zero = 0;
	}
	else
		descriptor->precision = 0;
}

void	set_base(t_descriptor *descriptor)
{
	if (descriptor->type == 'x' || descriptor->type == 'X')
		descriptor->base = 16;
	else if (descriptor->type == 'o' || descriptor->type == 'O')
		descriptor->base = 8;
	else if (!N_TYPE_D(descriptor->type) || !N_TYPE_U(descriptor->type))
		descriptor->base = 10;
	else
		descriptor->base = 0;
}
