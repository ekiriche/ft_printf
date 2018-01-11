/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 09:55:17 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/11/11 10:35:49 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_merge(int *left_arr, int *right_arr,
		int *original_arr, int size_of_arr)
{
	int		i;
	int		j;
	int		k;
	int		mid;

	i = 0;
	j = 0;
	k = 0;
	mid = size_of_arr / 2;
	while (i < mid && j < size_of_arr - mid)
	{
		if (left_arr[i] <= right_arr[j])
			original_arr[k++] = left_arr[i++];
		else
			original_arr[k++] = right_arr[j++];
	}
	while (i < mid)
		original_arr[k++] = left_arr[i++];
	while (j < size_of_arr - mid)
		original_arr[k++] = right_arr[j++];
}
