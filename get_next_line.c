/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-bakr <ral-bakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:56:29 by ral-bakr          #+#    #+#             */
/*   Updated: 2023/12/24 15:30:49 by ral-bakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_store_line(char *line, int fd)

{
	int		characters_read;
	char	*buffer_1;

	buffer_1 = malloc((long)BUFFER_SIZE + 1);
	if (buffer_1 == NULL)
		return (NULL);
	characters_read = 1;
	while (ft_strchr(line, '\n') == NULL && characters_read != 0)
	{
		characters_read = read(fd, buffer_1, BUFFER_SIZE);
		if (characters_read < 0)
		{
			free(buffer_1);
			return (NULL);
		}
		buffer_1[characters_read] = '\0';
		line = ft_strjoin(line, buffer_1);
	}
	free(buffer_1);
	return (line);
}

char	*ft_return_number_bytes_read(char *retur)

{
	int		index_1;
	int		index_2;
	char	*storing_2;

	index_1 = 0;
	while (retur[index_1] != '\0' && retur[index_1] != '\n')
		index_1++;
	if (retur[index_1] == '\n')
		index_1++;
	storing_2 = malloc(sizeof(char) * (index_1 + 1));
	if (storing_2 == NULL)
		return (NULL);
	index_2 = -1;
	while (++index_2 < index_1)
		storing_2[index_2] = retur[index_2];
	storing_2[index_2] = '\0';
	return (storing_2);
}

char	*ft_return_line_as_string(char *string_1)

{
	int		index_3;
	int		index_4;
	char	*storing_4;

	index_3 = 0;
	index_4 = 0;
	storing_4 = malloc(sizeof(char) * (
				ft_strlen(ft_strchr(string_1, '\n')) + 1));
	while (string_1[index_3] != '\0')
	{
		if (string_1[index_3] == '\n')
		{
			while (string_1[++index_3] != '\0')
				storing_4[index_4++] = string_1[index_3];
			break ;
		}
		index_3++;
	}
	storing_4[index_4] = '\0';
	free(string_1);
	return (storing_4);
}

char	*get_next_line(int fd)

{
	char		*line_read;
	static char	*storing_3;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > 2147483647)
		return (0);
	storing_3 = ft_store_line(storing_3, fd);
	if (storing_3 == 0 || storing_3[0] == '\0')
	{
		if (storing_3)
			free(storing_3);
		storing_3 = NULL;
		return (NULL);
	}
	line_read = ft_return_number_bytes_read(storing_3);
	if (ft_strchr(storing_3, '\n'))
		storing_3 = ft_return_line_as_string(storing_3);
	else
	{
		free(storing_3);
		storing_3 = NULL;
	}
	return (line_read);
}

// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("41_no_nl", O_RDONLY);
// 	line = get_next_line(fd);
// 	// 	printf("%s", line);
// 	// 	free(line);
// 	// 	line = get_next_line(fd);
// 	// 	printf("%s", line);
// 	// 	free(line);
// 	while (line != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	return (0);
// }
