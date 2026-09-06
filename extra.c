/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodehii <jodehii@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 22:49:09 by jodehii           #+#    #+#             */
/*   Updated: 2026/09/06 19:25:05 by jodehii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*read_basket(int fd, char *basket)
// {
// 	char	*spare_basket;
// 	char	*temp_basket;
// 	int		apples_read;

// 	apples_read = 1;
// 	spare_basket = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!spare_basket)
// 		return (NULL);
// 	while (!ft_strchr(basket, '\n') && apples_read > 0)
// 	{
// 		apples_read = read(fd, spare_basket, BUFFER_SIZE);
// 		if (apples_read <= 0)
// 		{
// 			free(spare_basket);
// 			free(basket);
// 			return (NULL);
// 		}
// 		spare_basket[apples_read] = '\0';
// 		temp_basket = ft_strjoin(basket, spare_basket);
// 		free(basket);
// 		basket = temp_basket;
// 		free (spare_basket);
// 	}
// 	return (basket);
// }

// char	*read_basket(int fd, char *basket)
// {
// 	char	*spare_basket;
// 	int		apples_read;

// 	spare_basket = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!spare_basket)
// 		return (NULL);
// 	while (!ft_strchr(basket, '\n'))
// 	{
// 		apples_read = read(fd, spare_basket, BUFFER_SIZE);
// 		if (apples_read <= 0)
// 			break ;
// 		spare_basket[apples_read] = '\0';
// 		basket = ft_strjoin(basket, spare_basket);
// 		free(spare_basket);
// 	}
// 	return (basket);
// }

// char	*read_basket(int fd, char *basket)
// {
// 	char	*spare_basket;
// 	int		apples_read;
// 	char	*temp;

// 	spare_basket = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!spare_basket)
// 		return (NULL);
// 	while (!ft_strchr(basket, '\n'))
// 	{
// 		apples_read = read(fd, spare_basket, BUFFER_SIZE);
// 		if (apples_read <= 0)
// 			break ;
// 		spare_basket[apples_read] = '\0';
// 		temp = ft_strjoin(basket, spare_basket);
// 		if (!temp)
// 		{
// 			free(basket);
// 			return (NULL);
// 		}
// 		free(basket);
// 		basket = temp;
// 	}
// 	free (spare_basket);
// 	if (apples_read < 0)
// 	{
// 		free(basket);
// 		return (NULL);
// 	}
// 	return (basket);
// }

char	*read_basket(int fd, char *basket)
{
	char	*spare_basket;
	char	*temp_basket;
	int		apples_read;

	spare_basket = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	apples_read = read(fd, spare_basket, BUFFER_SIZE);
	if (!spare_basket)
		return (NULL);
	while (*basket && !ft_strchr(basket, '\n'))
	{
		apples_read = read(fd, spare_basket, BUFFER_SIZE);
		if (apples_read <= 0)
			break ;
		spare_basket[apples_read] = '\0';
		temp_basket = ft_strjoin(basket, spare_basket);
		free(basket);
		basket = temp_basket;
	}
	free (spare_basket);
	if (apples_read < 0)
	{
		free(basket);
		return (NULL);
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
	apples_read = read(fd, spare_basket, BUFFER_SIZE);
	while (*basket && !ft_strchr(basket, '\n'))
	{
		apples_read = read(fd, spare_basket, BUFFER_SIZE);
		if (apples_read <= 0)
			break ;
		spare_basket[apples_read] = '\0';
		spare_basket = ft_strjoin(basket, spare_basket);
		free(basket);
		basket = spare_basket;
	}
	free (spare_basket);
	if (apples_read < 0)
	{
		free(basket);
		return (NULL);
	}
	return (basket);
}


// pls chill this is extra apples implementation

char	*get_apples(int fd, char *basket)
{
	char	*temp_basket;
	char	*apples;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp_basket = basket;
	while (temp_basket[i])
	{
		if (temp_basket[i] == '\n')
		{
			break ;
			i++;
		}
		i++;
	}
	apples = malloc(sizeof(char) * (i + 1));
	if (!apples)
		return (NULL);
	while (j <= i)
	{
		apples[j] = temp_basket[j];
		j++;
	}
	apples[j] = '\0';
	return (apples);
}

char	*get_apples(int fd, char *basket)
{
	char	*temp_basket;
	char	*apples;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp_basket = basket;
	while (temp_basket[i])
	{
		if (temp_basket[i] == '\n')
		{
			break ;
			i++;
		}
		i++;
	}
	apples = malloc(sizeof(char) * (i + 1));
	if (!apples)
		return (NULL);
	while (j <= i)
	{
		apples[j] = temp_basket[j];
		j++;
	}
	apples[j] = '\0';
	return (apples);
}
