/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:11:40 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/15 15:11:06 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"

typedef	struct s_pointers
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
}				t_pointers;

int		addingNumbers(char *format, ...);

int		ft_printf(char *format, ...);

int		is_format_letter(char c);

char	*handle_descriptor(char *descriptor, va_list arg_pointer);

char	*arg_to_string(char *descriptor, va_list arg_pointer);

#endif
