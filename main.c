/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:11:47 by ekiriche          #+#    #+#             */
/*   Updated: 2018/01/31 21:01:15 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	short int lul = -42;
	long long int g = 99999999999;
	printf("%-05o\n", 40);
	ft_printf("%-05o\n", 40);
}
