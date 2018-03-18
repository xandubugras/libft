/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:25:12 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/17 20:14:22 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*handle_hashtag(char *descriptor, char *current_str)
{
	char *new_str;

	new_str = 0;
	if (descriptor[0] == '#')
	{
		if (ft_strchr(descriptor, 'x'))
		{
			new_str = ft_strnew(ft_strlen(current_str) + 2);
			new_str[0] = '0';
			new_str[1] = 'x';
			ft_strncpy(&new_str[2], current_str, ft_strlen(current_str));
		}
		if (ft_strchr(descriptor, 'X'))
		{
			new_str = ft_strnew(ft_strlen(current_str) + 2);
			new_str[0] = '0';
			new_str[1] = 'X';
			ft_strncpy(&new_str[2], current_str, ft_strlen(current_str));
		}
		if (ft_strchr(descriptor, 'o') && current_str[0] != '0')
		{
			new_str = ft_strnew(ft_strlen(current_str) + 1);
			new_str[0] = '0';
			ft_strncpy(&new_str[1], current_str, ft_strlen(current_str));
		}
		if (new_str != 0)
		{
			free(current_str);
			return (new_str);
		}
		descriptor[0] = ' ';
	}
	return (current_str);
}
