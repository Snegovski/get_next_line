/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-bakr <ral-bakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:56:29 by ral-bakr          #+#    #+#             */
/*   Updated: 2023/12/30 17:09:38 by ral-bakr         ###   ########.fr       */
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

char	*ft_returned_line(char *the_new_stringjoined_line)

{
	int		counting_length;
	int		value_assignment_of_joined_string;
	char	*storing_2;

	counting_length = 0;
	while (the_new_stringjoined_line[counting_length] != '\0'
		&& the_new_stringjoined_line[counting_length] != '\n')
		counting_length++;
	if (the_new_stringjoined_line[counting_length] == '\n')
		counting_length++;
	storing_2 = malloc(sizeof(char) * (counting_length + 1));
	if (storing_2 == NULL)
		return (NULL);
	value_assignment_of_joined_string = -1;
	while (++value_assignment_of_joined_string < counting_length)
		storing_2[value_assignment_of_joined_string]
			= the_new_stringjoined_line[value_assignment_of_joined_string];
	storing_2[value_assignment_of_joined_string] = '\0';
	return (storing_2);
}

char	*ft_save_extra_characters_after_new_line(char *string_1)

{
	int		finding_newline;
	int		assigment_for_storing_4;
	char	*storing_4;

	finding_newline = 0;
	assigment_for_storing_4 = 0;
	storing_4 = malloc(sizeof(char) * (
				ft_strlen(ft_strchr(string_1, '\n')) + 1));
	if (storing_4 == NULL)
		return (NULL);
	while (string_1[finding_newline] != '\0')
	{
		if (string_1[finding_newline] == '\n')
		{
			while (string_1[++finding_newline] != '\0')
				storing_4[assigment_for_storing_4++]
					= string_1[finding_newline];
			break ;
		}
		finding_newline++;
	}
	storing_4[assigment_for_storing_4] = '\0';
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
	if (storing_3 == NULL || storing_3[0] == '\0')
	{
		if (storing_3 != NULL)
			free(storing_3);
		storing_3 = NULL;
		return (NULL);
	}
	line_read = ft_returned_line(storing_3);
	if (ft_strchr(storing_3, '\n'))
		storing_3 = ft_save_extra_characters_after_new_line(storing_3);
	else
	{
		free(storing_3);
		storing_3 = NULL;
	}
	return (line_read);
}
