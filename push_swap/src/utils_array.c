/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:22:54 by haryu             #+#    #+#             */
/*   Updated: 2022/04/18 21:01:52 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	find_minimun(int *array, int max_len, int *index)
{
	int	ret;
	int	i;

	i = 0;
	*index = i;
	ret = array[i];
	while (++i < max_len)
	{
		if (array[i] < ret)
		{
			ret = array[i];
			*index = i;
		}
	}
	return (ret);
}

int	*array_malloc_to_zero(int length)
{
	int	*ret;
	int	i;

	ret = malloc(sizeof(int) * length);
	if (!ret)
		put_error();
	i = 0;
	while (i < length)
		ret[i++] = 0;
	return (ret);
}

void	align_stack_a(t_pushlist **push, int min_value, int min_pos)
{
	if (min_pos < (*push)->max_len / 2)
	{
		while ((*push)->stack_a)
		{
			if ((*push)->stack_a->data == min_value)
				return ;
			ra(push, 0);
		}
	}
	else
	{
		while ((*push)->stack_a->data)
		{
			if ((*push)->stack_a->data == min_value)
				return ;
		}
		rra(push, 0);
	}
}

void	make_new_array(t_pushlist **push, int pivot)
{
	int	i;
	int	j;
	int	*tmp_arr;

	i = -1;
	j = 0;
	tmp_arr = (int *)malloc(sizeof(int) * (*push)->max_len);
	if (!tmp_arr)
		put_error ();
	while (++i < (*push)->max_len)
	{
		if ((*push)->array[i] == pivot)
		{
			while (j < (*push)->max_len)
			{
				tmp_arr[j++] = (*push)->array[i++];
				if (i == (*push)->max_len)
					i = 0;
			}
		}
		if (j == (*push)->max_len)
			break ;
	}
	free((*push)->array);
	(*push)->array = tmp_arr;
}
