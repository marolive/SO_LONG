/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:40:43 by marolive          #+#    #+#             */
/*   Updated: 2022/10/21 01:00:37 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_arq(int c, char *arg)
{
	char	*valid;

	if (c != 2)
		print_error("Wrong number of arguments!\n");
	valid = ft_strrchr(arg, '.');
	if (!valid)
		print_error("Only .ber files!\n");
	if (ft_strncmp(valid, ".ber", 4) != 0 || ft_strlen(valid) != 4)
		print_error("Only .ber files!\n");
}
