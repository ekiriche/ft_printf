/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:37:42 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/03 15:40:08 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	size_t	i;
	size_t	temp;

	i = 0;
	while (i < ft_strlen(str) / 2)
	{
		temp = str[i];
		str[i] = str[ft_strlen(str) - i - 1];
		str[ft_strlen(str) - i - 1] = temp;
		i++;
	}
}
