/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:52:27 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/08 18:53:43 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_swap(int *p1, int *p2)
{
	int tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
