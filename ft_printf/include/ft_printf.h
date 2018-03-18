/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 18:11:40 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/18 11:08:04 by adubugra         ###   ########.fr       */
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

int		ft_printf(char *format, ...);

int		is_format_letter(char c);

char	*handle_descriptor(char *descriptor, va_list arg_pointer);

char	*handle_plus(char *descriptor, char *current_str);

char	*handle_hashtag(char *descriptor, char *current_str);

char	*handle_padding(char *descriptor, char *current_str);

char	*handle_precision(char *descriptor, char *current_str);

char	*sizetoa(char *descriptor, va_list arg_pointer, int base);

char	*usizetoa(char *descriptor, va_list arg_pointer, int base);

char	*arg_to_string(char *descriptor, va_list arg_pointer);

#endif
