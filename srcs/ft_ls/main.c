/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*  By: blukasho <bodik1w@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:10:02 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/21 18:04:35 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					main(int argc, char **argv)
{
	--argc;
	++argv;
	ft_ls(argc, argv);
	return (0);
}
