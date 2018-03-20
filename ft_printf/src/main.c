/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 08:11:18 by adubugra          #+#    #+#             */
/*   Updated: 2018/03/19 19:56:47 by adubugra         ###   ########.fr       */
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


	
	printf("%d \n", ft_printf("%8%\n", 1500));
	printf("%d\n", printf("%8%\n",    1500));
	/*printf("u: %050u\n", 65);
	printf("x: %050x\n", 65);
	printf("o: %050o\n", 65);
	printf("c: %050c\n", 65);
	printf("s: %050s\n", "hello");
	printf("p: %050p\n", p);
*/
// precision makes sure to keep precision, but only allocates new memory if if needs to
// 0s don't care about changing 0s
	return (0);
}

// precision reigns over 0
// precision doesn't work with %c
// 0 in the beginning fills it with 0s
// space in the beginning puts a space
// space only works with %d
// + adds the sign to the number. can't be after 0
// + and space don't go together
// + only works with d
// + and - signs are added before numbers
// - switches tabulation
// - and 0 don't go together
// # on x and X keeps 
// more than one '.' is error
// 0 is always in position 0 or 1
// x, X and o ar all unsigned
// add n as well, returns how many characters have been written
// 
// precision: d, o, x, u
//
//
// plus:
// - works with: d
//
// zero: 
// -works with: d
// - ignored with - and .
//
// hashtag:
// -works with: o, x
// 
// minus:
// - works with all types
// - doesn't go with 0
