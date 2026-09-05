/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodehii <jodehii@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 23:58:21 by jodehii           #+#    #+#             */
/*   Updated: 2026/09/06 00:29:56 by jodehii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*extra_apples(char *basket)
{
	char	*extra_apples;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (basket[i] != '\n' && basket[i])
		i++;
	extra_apples = malloc(sizeof(char) * (ft_strlen(basket) - i));
	if (!extra_apples)
	{
		free (basket);
		return (NULL);
	}
	if (basket[i] == '\n')
		i++;
	while (extra_apples[j])
	{
		extra_apples[j] = basket[j + i];
		j++;
	}
	extra_apples[j] = 0;
	free (basket);
	return (extra_apples);
}

char	*get_next_line(int fd)
{
	static char	*basket;
	char		*apples;

	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	if (!basket)
		return (NULL);
	basket = read_basket(fd, basket);
	if (!basket)
		return (NULL);
	apples = get_apples(fd, basket);
	basket = extra_apples(basket);
	return (apples);
}
