/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodehii <jodehii@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:29:34 by jodehii           #+#    #+#             */
/*   Updated: 2026/09/06 21:22:27 by jodehii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_basket(int fd, char *basket)
{
	char	*spare_basket;
	char	*temp_basket;
	int		apples_read;

	spare_basket = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!spare_basket)
		return (NULL);
	apples_read = read(fd, spare_basket, BUFFER_SIZE);
	while (apples_read > 0)
	{
		spare_basket[apples_read] = '\0';
		temp_basket = ft_strjoin(basket, spare_basket);
		free(basket);
		basket = temp_basket;
		if (!ft_strchr(basket, '\n'))
			break ;
		apples_read = read(fd, spare_basket, BUFFER_SIZE);
	}
	free (spare_basket);
	if (apples_read < 0)
	{
		free(basket);
		return (NULL);
	}
	return (basket);
}


char	*get_apples(char *basket)
{
	char	*apples;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (basket[i] && basket[i] != '\n')
		i++;
	if (basket[i] == '\n')
		i++;
	apples = malloc(sizeof(char) * (i + 1));
	if (!apples)
		return (NULL);
	while (j < i)
	{
		apples[j] = basket[j];
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
	if (!basket[i])
	{
		free(basket);
		return (NULL);
	}
	i++;
	extra_apples = ft_substr(basket, i, ft_strlen(basket) - i);
	free (basket);
	return (extra_apples);
}

char	*get_next_line(int fd)
{
	static char	*basket;
	char		*apples;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!basket)
	{
		basket = ft_strdup("");
		if (!basket)
			return (NULL);
	}
	basket = read_basket(fd, basket);
	if (!basket)
		return (NULL);
	if (basket[0] == '\0')
	{
		free(basket);
		basket = NULL;
		return (NULL);
	}
	apples = get_apples(basket);
	basket = extra_apples(basket);
	return (apples);
}
