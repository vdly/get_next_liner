/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodehii <jodehii@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 21:55:13 by jodehii           #+#    #+#             */
/*   Updated: 2026/09/07 14:48:03 by jodehii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*ptr;

	ptr = get_next_line(fd);
	fd = open("text.txt", O_RDWR);
	while (ptr != NULL)
	{
		printf("%s", ptr);
		free(ptr);
		ptr = get_next_line(fd);
	}
}
