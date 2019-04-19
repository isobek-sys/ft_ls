/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:01:04 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/19 17:38:21 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			add_dir(char *file, t_ft_ls_data *data)
{
	data->files = get_t_ft_ls_file(data->files, file);
}

int					ft_read_flags(char *flags, t_ft_ls_data *data)
{
	int				i;

	i = 0;
	if (flags[i] == '-')
	{
		while (flags[++i])
		{
			if (flags[i] == 'l')
				data->l = 1;
			else if(flags[i] == 'a')
				data->a = 1;
			else if (flags[i] == 'r')
				data->r = 1;
			else if (flags[i] == 't')
				data->t = 1;
			else if (flags[i] == 'R')
				data->rr = 1;
			else
				return (error_invalid_flag(flags[i]));
		}
	}
	else
		add_dir(flags, data);
	return (1);
}

t_ft_ls_data		*ft_read_args(int ar, char **av)
{
	t_ft_ls_data	*data;

	data = get_t_ft_ls_data();
	while (--ar >= 0)
		if (!ft_read_flags(av[ar], data))
		{
			clear_t_ft_ls_data(data);
			return (NULL);
		}
	if (!data->files)
		ft_read_flags(".", data);
	return (data);
}
