/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <filip.karika1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:12:12 by fkarika           #+#    #+#             */
/*   Updated: 2024/10/23 14:33:36 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_ft_strchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		if (*(char *)(s + i) == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (*(char *)(s + i) == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

void	*gnl_ft_calloc(size_t count, size_t size, int *err)
{
	void	*ptr;
	size_t	i;

	if (count && (count * size) / count != size)
		return (*err = -1, NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (*err = -1, NULL);
	i = 0;
	while (i < count * size)
	{
		*((unsigned char *)(ptr + i)) = '\0';
		i++;
	}
	return (ptr);
}

char	*gnl_ft_strjoin(char *s1, char *s2, int *err)
{
	char	*str;

	if (s1 == NULL)
	{
		s1 = (char *)gnl_ft_calloc(1, sizeof(char), err);
		if (!s1 || *err < 0)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	str = (char *)gnl_ft_calloc(
			(gnl_ft_strlen(s1) + gnl_ft_strlen(s2) + 1), sizeof(char), err);
	if (!str || *err < 0)
		return (free(s1), NULL);
	gnl_ft_strlcpy(str, s1, gnl_ft_strlen(s1) + 1);
	gnl_ft_strlcpy(str + gnl_ft_strlen(s1), s2, gnl_ft_strlen(s2) + 1);
	free(s1);
	return (str);
}

size_t	gnl_ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	gnl_ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
