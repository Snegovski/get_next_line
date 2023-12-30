/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ral-bakr <ral-bakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:55:12 by ral-bakr          #+#    #+#             */
/*   Updated: 2023/12/30 16:21:01 by ral-bakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)

{
	int		c;
	int		v;
	char	*str;

	if (!s1)
		s1 = ft_strdup("");
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	c = 0;
	while (s1[c] != '\0')
	{
		str[c] = s1[c];
		c++;
	}
	v = 0;
	while (s2[v] != '\0')
	{
		str[c + v] = s2[v];
		v++;
	}
	str[c + v] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)

{
	char	*str;

	str = (char *)s;
	if (!s)
		return (NULL);
	while (*str != '\0' && *str != (unsigned char) c)
		str++;
	if (*str == '\0' && ((unsigned char) c) != '\0')
		return (NULL);
	return (str);
}

size_t	ft_strlen(char const *str)
{
	size_t	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strdup(char *str)

{
	int		c;
	char	*v;

	c = 0;
	while (str[c] != '\0')
		c++;
	v = malloc(sizeof(char) * (c + 1));
	if (!v)
		return (NULL);
	c = 0;
	while (str[c] != '\0')
	{
		v[c] = str[c];
		c++;
	}
	v[c] = '\0';
	return (v);
}
