/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 14:27:13 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/16 15:09:19 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strinsert_sub(char **src, char *str, int location)
{
	char	*new;
	int		str_len;

	str_len = ft_strlen(str);
	new = ft_strnew(str_len + ft_strlen(*src) - 1);
	ft_strncpy(new, *src, location);
	ft_strncpy((new + location), str, str_len);
	ft_strncpy((new + location + str_len), (*src) + location + 1, ft_strlen(*src) - location - 1);
	free(*src);
	*src = new;
	return (new);
}
