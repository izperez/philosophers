/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:57:11 by izperez           #+#    #+#             */
/*   Updated: 2024/05/09 10:45:01 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//print num hex|dec
void	pf_putnbr(int i, char *base, int *bytes)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (i < 0)
		pf_isnegative(i, base, bytes);
	else if (i / base_len)
		pf_putnbr(i / base_len, base, bytes);
	pf_putchar(base[i % base_len], bytes);
}
