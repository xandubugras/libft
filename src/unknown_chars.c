/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknown_chars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:15:25 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/25 11:25:26 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	is_unknown_char(char c)
{
	if (is_format_letter(c))
		return (0);
	if (c == 'j' || c == 'z' || c == 'l' || c == 'h' || c == 'h')
		return (0);
	if (c == ' ' || c == '+' || c == '-' || c == '#' || c == '.')
		return (0);
	if (ft_isdigit(c))
		return (0);
	if (c == '*')
		return (0);
	return (1);
}
