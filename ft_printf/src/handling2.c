/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:25:12 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/19 19:56:10 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void			handle_hashtag_precision(t_descriptor *descriptor)
{
	char	*fill;
	int		i;

		fill = descriptor->type == 'x' ? "0x" : "0X";
		i = 0;
		while (!ft_isdigit(descriptor->final_content[i]))
			i++;
		if (descriptor->type == 'o')
		{
			if (descriptor->final_content[i] == '0')
				return ;
			else if (i > 0 && descriptor->final_content[i - 1] == ' ')
				descriptor->final_content[i - 1] = '0';
			else
				ft_strinsert(&(descriptor->final_content), "0", i);
		}
		else if (i == 0)
			ft_strinsert(&(descriptor->final_content), fill, i);
		else if (i == 1 && fill[1] != '\0')
		{
			descriptor->final_content[0] = fill[1];
			ft_strinsert_char(&(descriptor->final_content), fill[0], 0);
		}
		else if (i >= 2)
			ft_strncpy(&(descriptor->final_content[i - 2]), fill, 2);
}

void			handle_hashtag_zero(t_descriptor *descriptor)
{
	char	*fill;

	if (descriptor->hash)
	{
		fill = descriptor->type == 'x' ? "0x" : "0X";
		if (descriptor->type == 'o')
			fill = "0";
		if (descriptor->final_content[0] == '0')
		{
			if (descriptor->type == 'o')
				return ;
			else if (descriptor->final_content[1] == '0')
				ft_strncpy(descriptor->final_content, fill, 2);
			else
				ft_strinsert_sub(&(descriptor->final_content), fill, 0);
		}
		else if (ft_isdigit(descriptor->final_content[0]))
			ft_strinsert(&(descriptor->final_content), fill, 0);
	}
}

void			handle_minus(t_descriptor *descriptor)
{
	int		i;
	char	*dsc;
	char	*new;
	int		len;

	if (descriptor->minus)
	{
		dsc = descriptor->final_content; 
		new = ft_strnew(ft_strlen(dsc));
		i = 0;
		while (dsc[i] == ' ')
			i++;
		if (i == 0)
			return ;
		len = ft_strlen(&(dsc[i]));
		ft_strncpy(new, &(dsc[i]), len);
		i = len;
		while (i < ft_strlen(dsc))
			new[i++] = ' ';
		free(dsc);
		descriptor->final_content = new;
	}
}

char			*handle_star(char **description, va_list arg_pointer)
{
	int		i;
	char	*c;

	while ((strchr(*description, '*')) != NULL)
	{
		i = 0;
		while ((*description)[i] != '*')
			i++;
		c = ft_itoa(va_arg(arg_pointer, int));
		ft_strinsert_sub(description, c, i);
		free (c);
	}
	return (*description);
}
