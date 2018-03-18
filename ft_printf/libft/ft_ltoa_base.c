/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 11:26:29 by exam              #+#    #+#             */
/*   Updated: 2018/03/18 12:16:40 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#define MIN_INT -2147483648

char	*minint(int base);

static char	equiv(int n)
{
	if (n >=0 && n <= 9)
		return (n + 48);
	else if (n >= 10 && n <= 15)
		return (n + 87);
	else
		return (40);
}

static int size(unsigned long long n, int base)
{
	int counter;

	counter = 0;
	while (n != 0)
	{
		n /= base;
		counter++;
	}
	return counter;
}

char	*ft_ltoa_base(long long value, int base)
{
	char *itoa;
	int len;
	int i;

	len = value < 0 ? size(value, base) + 1 : size(value, base);
	itoa = (char *)malloc(sizeof(char) * len + 1);
	if (value < 0)
	{
		itoa[0] = '-';
		value *= -1;
	}
	itoa[len] = '\0';
	i = 1;
	if (value != 0)
	{
		while (value > 0)
		{
			itoa[len - i] = equiv(value % base);
			value /= base;
			i++;
		}
		return (itoa);
	}
	else
		return "0\0";
}

char	*ft_ultoa_base(unsigned long long value, int base)
{
	char *itoa;
	int len;
	int i;

	len = size(value, base);
	value = value * 1;
	itoa = (char *)malloc(sizeof(char) * len + 1);
	itoa[len] = '\0';
	i = 1;
	if (value != 0)
	{
		while (value > 0)
		{
			itoa[len - i] = equiv(value % base);
			value /= base;
			i++;
		}
		return (itoa);
	}
	else
		return "0\0";
}

