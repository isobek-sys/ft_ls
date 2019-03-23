/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:10:02 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/23 17:47:26 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					main(int argc, char **argv)
{
	t_ft_ls_data	*data;

	--argc;
	++argv;
	if((data = ft_read_args(argc, argv)))
		ft_printf("Read OK.\n");
	else
		print_usage();
	return (0);
}
