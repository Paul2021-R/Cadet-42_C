/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_call.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.co.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:51:34 by haryu             #+#    #+#             */
/*   Updated: 2022/03/23 18:01:27 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void element_put(t_mlx *vars, t_img *img, int x, int y)
{
	printf("check pointer\nmlx pointer : %p player :  %p\n", vars, img);
	printf("position : x =  %d y = %d\n", x, y);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img->img, x, y);
}

int	elements_call(t_module *init)
{
	player_load(init);
	printf("tell me the pointer ! %p\n", init->player.sprite);
	//coin_load(init);
	return (0);
}
// enemy 숫자 맞춰서 호출 해야함
