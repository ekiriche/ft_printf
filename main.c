/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:11:47 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/12 14:33:01 by ekiriche         ###   ########.fr       */
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
	setlocale(LC_ALL, "en_US.UTF-8");
//	printf("%lc\n", ac);
//	printf("them: %d\n", printf("them: %C\n", L'ÁM-^L´'));
//	printf("mine: %d\n", ft_printf("mine: %C\n", L'ÁM-^L´'));
//	int asd = printf("%C", L'ÁM-^L´');
//	int poin = ft_printf("%C", L'ÁM-^L´');
//	printf("%d\n%d\n", asd, poin);
//	printf("them: %d\n", printf("them: %S\n", as));
//	printf("mine: %d\n", ft_printf("mine: %S\n", as));
//	printf("%.4S\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
//	ft_printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
//	printf("them: %.5p\n", 1);
//	ft_printf("mine: %.5p\n", 1);
//	printf("them: %d\n", printf("%C\n", 976));
//	printf("mine: %d\n", ft_printf("%C\n", 976));
//	printf("t: %d\n", printf("t: {%05.S}", L"42 c est cool"));
//	printf("m: %d\n", ft_printf("m: {%05.S}", L"42 c est cool"));
//	ft_printf("%10.7d\n", 123);
//	printf("t: %d\n", printf("%-12p", &k));
//	printf("m: %d\n", ft_printf("%-12p", &k));
//	printf("%d\n", printf("%03.2ld\n", 42));
//	printf("%d\n", ft_printf("%03.2ld\n", 42));
//	printf("%d\n", printf("%C\n", 2047));
//	printf("%d\n", ft_printf("%C\n", 2047));
//	printf("%.4S\n", L"我是一只猫。");
//	ft_printf("%.4S\n", L"我是一只猫。");
//	printf("{%-15Z}", 123);
//	ft_printf("{%-15Z}", 123);
//	printf("%d\n", printf("t:{%05p}", 1));
//	printf("%d\n", ft_printf("m:{%05p}", 1));
//	ft_printf("%C\n", L'�');
//	ft_printf("%.5s\n", NULL);
//	printf("t:%d\n", printf("{%05.Z}", 123));
//	printf("m:%d\n", ft_printf("{%05.Z}", 123));
//	printf("% 10Zoooo");
//	ft_printf("% Zoooo");
//	ft_printf("%03.2d\n", -1);
//	printf("%C\n", L'ø');
//	ft_printf("%C\n", L'ø');
//	printf("%ll#x\n", 9223372036854775807);
//	ft_printf("%ll#x\n", 9223372036854775807);
//	printf("%0 3.2d\n", 1);
//	ft_printf("%0 3.2d\n", 1);
	printf("%0.6d\n", -12345);
	ft_printf("%0#21o\n", -1372218040);
}
