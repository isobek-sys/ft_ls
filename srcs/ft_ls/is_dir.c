/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:51:49 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/23 11:58:52 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		is_dir(char *dirname)
{
	DIR	*dir;

	if ((dir = ft_open_dir(dirname)) && !closedir(dir))
			return (1);
	return (0);
}