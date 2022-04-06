/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:19:12 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/06 12:02:52 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

t_key	*init_key(t_vars *data)
{
	t_key	*key;

	key = malloc(sizeof(t_key));
	key->arrowleftflag = false;
	key->arrowrightflag = false;
	key->upflag = false;
	key->downflag = false;
	key->rightflag = false;
	key->leftflag = false;
	data->key = key;
	return (key);
}

t_tex	*init_texture(t_vars *data)
{
	t_tex	*tex;
	int		i;

	tex = ft_calloc(sizeof(t_tex), 1);
	if (tex == NULL)
		return (NULL);
	tex->texture = (int **)malloc(sizeof(int *) * 5);
	if (tex->texture == NULL)
		return (NULL);
	tex->texture[5] = NULL;
	i = 0;
	while (i < 4)
	{
		tex->texture[i] = (int *)ft_calloc(sizeof(int) * (64 * 64), 1);
		if (tex->texture[i] == NULL)
			return (NULL);
		i++;
	}
	data->tex = tex;
	return (tex);
}

void	init_minimap(t_vars *data)
{
	t_minimap	*minimap;

	minimap = malloc(sizeof(t_minimap));
	minimap->a = 0;
	minimap->b = 0;
	minimap->pa = 0;
	minimap->pb = 0;
	minimap->o = 0;
	minimap->u = 0;
	data->minimap = minimap;
}
