/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:19:40 by epolkhov          #+#    #+#             */
/*   Updated: 2023/12/21 18:43:01 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (ft_free(&s1), ft_free(&s2));
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && (char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*check_string(char *s)
{
	if (!s)
	{
		s = (char *)malloc(sizeof(char) * 1);
		if (!s)
			return (0);
		*s = 0;
	}
	return (s);
}

char	*ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}
