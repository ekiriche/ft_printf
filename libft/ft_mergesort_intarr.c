/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort_intarr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 09:56:31 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/11/11 10:35:35 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mergesort_intarr(int *arr, int size_of_arr)
{
	int		mid;
	int		*l_arr;
	int		*r_arr;
	int		i;
	int		j;

	if (size_of_arr < 2)
		return ;
	mid = size_of_arr / 2;
	l_arr = (int*)malloc(sizeof(int) * mid);
	r_arr = (int*)malloc(sizeof(int) * (size_of_arr - mid));
	i = -1;
	while (++i < mid)
		l_arr[i] = arr[i];
	j = mid;
	while (j < size_of_arr)
	{
		r_arr[j - mid] = arr[j];
		j++;
	}
	ft_mergesort_intarr(l_arr, mid);
	ft_mergesort_intarr(r_arr, size_of_arr - mid);
	ft_merge(l_arr, r_arr, arr, size_of_arr);
	free(r_arr);
	free(l_arr);
}
