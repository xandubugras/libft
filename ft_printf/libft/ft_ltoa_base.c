/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 11:26:29 by exam              #+#    #+#             */
/*   Updated: 2018/03/15 20:02:00 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#define MIN_INT -2147483648

static char	*minint(int base);
char	*ft_ltoa_base(long value, int base);

static char	equiv(int n)
{
	if (n >=0 && n <= 9)
		return (n + 48);
	else if (n >= 10 && n <= 15)
		return (n + 87);
	else
		return (40);
}

static int size(long n, int base)
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

static char	*minint(int base)
{
	char *str;
	long len;

	if (base == 2)
		return "10000000000000000000000000000000\0";
	if (base == 4)
		return "2000000000000000\0";
	if (base == 8)
		return "20000000000\0";
	if (base == 16)
		return "80000000";

	else
	{
		str = ft_ltoa_base(MIN_INT + 1, base);
		len = size(MIN_INT + 1, base) + 1;
		str[len] = '\0';
		if (str[len - 1] != '9')
			str[len - 1] = (str[len-1]) + 1;
		else
			str[len - 1] = 'A';
		return str;
	}
	return "0\0";
}

char	*ft_ltoa_base(long value, int base)
{
	char *itoa;
	int len;
	int i;

	if (value == MIN_INT)
		return (minint(base));
	len = size(value, base);
	if (value < 0 && base == 10)
		len++;
	itoa = (char *)malloc(sizeof(char) * len + 1);
	if (value < 0)
	{
		if (base == 10)
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
