/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bscussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 14:04:58 by bscussel          #+#    #+#             */
/*   Updated: 2019/11/16 16:17:15 by bscussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void		*ft_memalloc(size_t size)
{
	void	*vptr;

	vptr = malloc(size);
	if (vptr == NULL)
		return (NULL);
	ft_memset(vptr, 0, size);
	return (vptr);
}
