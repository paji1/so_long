/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 04:09:30 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/06/10 10:09:32 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}
