/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:54 by dpentlan          #+#    #+#             */
/*   Updated: 2023/11/23 13:42:26 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "libft.h"

/*
 *	***** ft_arg_parse *****
 *
 *	DESCRIPTION:
 *		Performs checks on the input argument.
 *
 *		First number of arguments must be 2 ["./cub3D", "filename.cub"]
 *		Second filename must be 5 or greater (smallest is a.cub, b.cub, etc)
 *		Third check for ".cub" and make sure it's at the end of the string.
 *	RETURN:
 *		Bool returns 0 on success and 1 on error.
 */

bool	ft_arg_parse(int argc, char **argv)
{
	size_t	arg_len;

	if (argc != 2)
		return (ft_putstr_fd("Error\nIncorrect number of arguments.\n", 2), 1);
	arg_len = ft_strlen(argv[1]);
	if (arg_len < 5)
		return (ft_putstr_fd("Error\nMap file type incorrect.\n", 2), 1);
	if (ft_strnstr(argv[1], ".cub", arg_len) != argv[1] + (arg_len - 4))
		return (ft_putstr_fd("Error\nMap file type incorrect.\n", 2), 1);
	return (0);
}
