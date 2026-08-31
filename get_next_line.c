/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodehii <jodehii@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 23:58:21 by jodehii           #+#    #+#             */
/*   Updated: 2026/08/31 21:03:34 by jodehii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_basket(int fd, char *basket)
{
	char	*spare_basket;
	int		apples_read;

	spare_basket = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!spare_basket)
		return (NULL);
	apples_read = read(fd, spare_basket, BUFFER_SIZE);
	if (apples_read <= 0)
	{
		free(spare_basket);
		return (NULL);
	}
	spare_basket[apples_read] = '\0';
	basket = ft_strdup(spare_basket);
	return (basket);
}

char	*more_apples(int fd, char *basket)
{
	char	*extra_apples;
	char	*temp_basket;
}

char	*sort_apples(int fd, char *basket)
{
	if (!ft_strchr(basket, '\n'))
	{
	}
}

char	*get_next_line(int fd)
{
	static char	*basket;
	char		*apples;

	return (apples);
}
