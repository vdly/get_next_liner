/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodehii <jodehii@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 23:58:21 by jodehii           #+#    #+#             */
/*   Updated: 2026/09/03 19:46:08 by jodehii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_basket(int fd, char *basket)
{
	char	*spare_basket;
	char	*temp_basket;
	int		apples_read;

	apples_read = 1;
	spare_basket = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!spare_basket)
		return (NULL);
	while (!ft_strchr(basket, '\n') && apples_read > 0)
	{
		apples_read = read(fd, spare_basket, BUFFER_SIZE);
		if (apples_read <= 0)
		{
			free(spare_basket);
			free(basket);
			return (NULL);
		}
		spare_basket[apples_read] = '\0';
		temp_basket = ft_strjoin(basket, spare_basket);
		free(basket);
		basket = temp_basket;
		free (spare_basket);
	}
	return (basket);
}

char	*read_basket(int fd, char *basket)
{
	char	*spare_basket;
	int		apples_read;

	spare_basket = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!spare_basket)
		return (NULL);
	while (!ft_strchr(basket, '\n'))
	{
		apples_read = read(fd, spare_basket, BUFFER_SIZE);
		if (apples_read <= 0)
			break ;
		spare_basket[apples_read] = '\0';
		basket = ft_strjoin(basket, spare_basket);
		free(spare_basket);
	}
	return (basket);
}

char	*read_basket(int fd, char *basket)
{
	char	*spare_basket;
	int		apples_read;
	char	*temp;

	spare_basket = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!spare_basket)
		return (NULL);
	while (!ft_strchr(basket, '\n'))
	{
		apples_read = read(fd, spare_basket, BUFFER_SIZE);
		if (apples_read <= 0)
			break ;
		spare_basket[apples_read] = '\0';
		temp = ft_strjoin(basket, spare_basket);
		if (!temp)
		{
			free(basket);
			return (NULL);
		}
		free(basket);
		basket = temp;
	}
	free (spare_basket);
	if (apples_read < 0)
	{
		free(basket);
		return (NULL);
	}
	return (basket);
}

char	*get_apples(int fd, char *basket)
{
	char	*temp_basket;

	temp_basket = basket;
}

// char	*sort_apples(int fd, char *basket)
// {
// 	if (!ft_strchr(basket, '\n'))
// 	{
// 	}
// }

char	*get_next_line(int fd)
{
	static char	*basket;
	char		*apples;

	return (apples);
}
