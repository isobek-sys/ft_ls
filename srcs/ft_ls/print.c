/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 21:40:37 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/12 13:26:23 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	start_print_result(t_ft_ls_data *data, char *dir)
{
	if (data->rr)
		ft_printf("Print recursively.\n");
	else
		ft_standart_output(data, dir);
}

void	print_files(t_ft_ls_file *files)
{
	while (files)
	{
//		ft_printf("%ld ", files->inode);
		ft_printf("%c", files->filetype);
		ft_printf("%s ", files->permissions);
		ft_printf("%ld ", files->hardlinks);
		ft_printf("%s ", files->username);
		ft_printf("%s ", files->groupname);
		ft_printf("%lld ", files->filesize);
		ft_printf("%.24s ", files->lastmod);
		ft_printf("%s ", files->filename);
		if (files->filetype == 'l')
			ft_printf("-> %s", files->link_file);
		ft_printf("\n");
		files = files->next;
	}
}
