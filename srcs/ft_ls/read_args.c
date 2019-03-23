/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:01:04 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/23 17:11:44 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			add_dir(char *dir, t_ft_ls_data *data)
{
	data->dirs = get_t_ft_ls_dir(data->dirs, dir);
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
				data->R = 1;
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
	int				i;
	t_ft_ls_data	*data;

	i = 0;
	data = get_t_ft_ls_data();
	while (i < ar)
		if (!ft_read_flags(av[i++], data))
		{
			clear_t_ft_ls_data(data);
			return (NULL);
		}
	if (!data->dirs)
		ft_read_flags(".", data);
	return (data);
}