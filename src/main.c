/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:08:42 by wollio            #+#    #+#             */
/*   Updated: 2022/04/06 18:21:16 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	t_vars		*data;

	if (argc != 2)
		error("Error : wrong number of arguments");
	if (check_file_format(argv[1]))
		error("Error : wrong map format");
	data = check_file_content(argv[1]);
	initdatastructure(data);
	ft_mlx_init(data);
	game_start(data);
	ft_free (data);
	return (0);
}
