/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:11:47 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/05 15:56:01 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
int		main(void)
{
	short int lul = 1;
	unsigned long long int g = 2500000000;
	unsigned int k = 1000;
//	printf("them: %o%o%o%o%o\n", 1, 42, 9999, 123456, 999988888);
//	ft_printf("mine: %o%o%o%o%o\n", 1, 42, 9999, 123456, 999988888);
//	printf("them: %o", 999998888);
//	ft_printf("mine: %o", 999998888);
//	printf("them: %D\n", 1000);
//	ft_printf("mine: %D\n", 1000);
//	printf("them: %s\n", NULL);
//	ft_printf("mine: %s\n", NULL);
//	printf("%i", printf("them: %-10x\n", 2500));
//	printf("%i\n", ft_printf("mine: %#10x\n", -25000000));
//	printf("%i\n", printf("them: %#10x\n", -25000000));
//	ft_printf("%#0 +-10.5llo\n", g);
//		printf("%d\n", printf("them: %.p, %.0p", 0, 0));
//		printf("%d\n", ft_printf("mine: %.p, %.0p", 0, 0));
//		printf("%d\n", printf("them{%03c}", 0));
//		printf("%d\n", ft_printf("mine{%03c}", 0));
//	printf("{%03c}", 4);
//	printf("%hhC, %hhC", 0, 97);
//	printf("%d\n", ft_printf("mine: % 015.4d\n", -42));
//	printf("them: %d\n", printf("them: % 05.4c\n", 97));
//	printf("mine: %d\n", ft_printf("them: % 05.4c\n", 97));
	wchar_t ac = 536;
	wchar_t *as = L"Á±≥";
	setlocale(LC_ALL, "");
//	printf("%lc\n", ac);
//	printf("them: %d\n", printf("them: %C\n", L'ÁM-^L´'));
//	printf("mine: %d\n", ft_printf("mine: %C\n", L'ÁM-^L´'));
//	int asd = printf("%C", L'ÁM-^L´');
//	int poin = ft_printf("%C", L'ÁM-^L´');
//	printf("%d\n%d\n", asd, poin);
	printf("them: %d\n", printf("them: %S\n", as));
	printf("mine: %d\n", ft_printf("mine: %S\n", as));
}
