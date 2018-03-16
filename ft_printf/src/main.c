/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 08:11:18 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/16 15:30:19 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int main()
{
	system("clear");
	long *p;
	long number;

	number = 150000;
	p = &number;
		/*
	number = 1234;
    printf("%-10d \n%-d\n", number, number);
    printf("+10: %+010d \n", number);
    printf("010: %010d \n", number);
    printf("-#10x: %-#10x \n", number);
    printf("#x: %#x \n", number);
*/
	ft_printf("%*.*p\n",12, 9, "asfd");
	printf("%*.*p\n","asdf");
	ft_printf("%12.9d\n",-12345);
	printf("%12.9d\n", -12345);
	//ft_printf("%*s. peep1. %c. %%  peep2. %d.\n", 1, "200", 'a', 300);
	//printf("%*s. peep1. %c. %%  peep2. %d.\n",1, "200", 'a', 300);


	return (0);
}

// 0 in the beginning fills it with 0s
// + adds the sign to the number. can't be after 0
// -
