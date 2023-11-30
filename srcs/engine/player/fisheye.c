/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fisheye.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:31:34 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/30 15:42:55 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "math.h"

/*
 *	***** ft_fix_fisheye *****
 *
 *	DESCRIPTION:
 *		Uses cosine to adjust the distance value according the offset of the
 *		ray's angle from the player's angle.
 *	RETURN:
 *		Returns the new distance as a double.
 */

double	ft_fix_fisheye(double player_angle, double ray_angle, double dist)
{
	double	camera_angle;

	camera_angle = player_angle - ray_angle;
	if (camera_angle < 0)
		camera_angle += (2 * PI);
	if (camera_angle > (2 * PI))
		camera_angle -= (2 * PI);
	return (dist * cos(camera_angle));
}
