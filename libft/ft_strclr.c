/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:16:43 by rpoetess          #+#    #+#             */
/*   Updated: 2019/01/30 17:16:47 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

void	ft_strclr(char *s)
{
	int i;

	i = 0;
	if (s)
		while (s[i])
		{
			s[i] = (int)('\0');
			i++;
		}
}
