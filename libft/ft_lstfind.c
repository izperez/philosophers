/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:15:42 by izperez           #+#    #+#             */
/*   Updated: 2024/04/29 12:26:31 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, int n)
{
	t_list	*current;

	current = lst;
	while (current != NULL)
	{
		if (current->content == n)
			return (current);
		current = current->next;
	}
	return (NULL);
}
