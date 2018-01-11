/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubsort_intarr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 09:47:47 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/11/11 10:09:27 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubsort_intarr(int *arr, int size_of_arr)
{
	int		i;
	int		k;
	int		flag;

	k = 0;
	while (k < size_of_arr - 1)
	{
		flag = 0;
		i = 0;
		while (i < size_of_arr - k - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				ft_swap_i(&arr[i], &arr[i + 1]);
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
			break ;
		k++;
	}
}
