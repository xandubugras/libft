/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:27:13 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/19 15:23:55 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strinsert(char **src, char *str, int location)
{
	char	*new;
	int		str_len;

	str_len = ft_strlen(str);
	new = ft_strnew(str_len + ft_strlen(*src));
	ft_strncpy(new, *src, location);
	ft_strncpy((new + location), str, str_len);
	ft_strncpy((new + location + str_len), (*src) + location, ft_strlen(*src) - location);
	free(*src);
	*src = new;
	return (new);
}

char	*ft_strinsert_char(char **src, char str, int location)
{
	char	*new;

	new = ft_strnew(1 + ft_strlen(*src));
	ft_strncpy(new, *src, location);
	ft_strncpy((new + location), &str, 1);
	ft_strncpy((new + location + 1), (*src) + location, ft_strlen(*src) - location);
	free(*src);
	*src = new;
	return (new);
}
char	*ft_strremove_char(char **src, int location)
{
	char	*new;

	new = ft_strnew(ft_strlen(*src) - 1);
	ft_strncpy(new, *src, location);
	ft_strncpy((new + location), (*src) + location + 1, ft_strlen(*src) - location);
	free(*src);
	*src = new;
	return (new);
}
