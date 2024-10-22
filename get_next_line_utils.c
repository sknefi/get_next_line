/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <filip.karika1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:12:12 by fkarika           #+#    #+#             */
/*   Updated: 2024/10/15 14:47:31 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	if (count && (count * size) / count != size)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		*((unsigned char *)(ptr + i)) = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(
			sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
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
