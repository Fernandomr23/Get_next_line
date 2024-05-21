/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmorenil <fmorenil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:07:33 by fmorenil          #+#    #+#             */
/*   Updated: 2024/05/21 12:12:34 by fmorenil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("hello.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo");
		return (1);
	}
	line = get_next_line(fd);
	i = 1;
	while (line != NULL)
	{
		printf("La linea %i es: %s", i++, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("\n");
	return (0);
}
