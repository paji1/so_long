/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 03:03:02 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/10 11:07:20 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free(t_mapline **lst)
{
	t_mapline	*temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		(*lst) = (*lst)->next;
		free(temp->line);
		free(temp);
	}	
}
