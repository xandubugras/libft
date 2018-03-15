/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 08:11:18 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/15 15:24:39 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int main()
{
/*	int number;

	number = 1234;
	system("clear");
    printf("%-10d \n%-d\n", number, number);
    printf("+10: %+010d \n", number);
    printf("010: %010d \n", number);
    printf("-#10x: %-#10x \n", number);
    printf("#x: %#x \n", number);
*/
	ft_printf("%*s. peep1. %c. %%  peep2. %d.", 1, "200", 'a', 300);
	//printf( "\n 10 + 20 = %d ",           ft_printf( "%d %", 10, 20 )  );
	//printf( "\n 10 + 20 + 30 = %d ",      ft_printf( "%d % %", "10", "20", "30" )  );
	//printf( "\n 10 + 20 + 30 + 40 = %d ", ft_printf( "%d % % %", "10", "20", "30", "40" )  );


	return (0);
}

// 0 in the beginning fills it with 0s
// + adds the sign to the number. can't be after 0
// -
