/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:12:02 by fmorenil          #+#    #+#             */
/*   Updated: 2024/05/21 12:14:11 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		fd2;
	int		i;
	char	*line;
	char	*line2;

	fd = open("hello.txt", O_RDONLY);
	fd2 = open("bye.txt", O_RDONLY);
	if (fd == -1 || fd2 == -1)
	{
		printf("Error al abrir el archivo");
		return (1);
	}
	i = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			printf("La linea %i de fd es: %s", i, line);
			free(line);
		}
		line2 = get_next_line(fd2);
		if (line2 != NULL)
		{
			printf("La linea %i de fd2 es: %s", i, line2);
			free(line2);
		}
		i++;
		if (line == NULL && line2 == NULL)
			break ;
	}
	close(fd);
	close(fd2);
	printf("\n");
	return (0);
}
