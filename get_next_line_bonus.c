/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkarika <filip.karika1@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:32:48 by fkarika           #+#    #+#             */
/*   Updated: 2024/10/23 14:57:35 by fkarika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(char *str, int *err)
{
	int		itr;
	char	*line;

	if (!str || !*str)
		return (NULL);
	itr = 0;
	while (str[itr] && str[itr] != '\n')
		itr++;
	if (str[itr] == '\n')
		itr++;
	line = (char *)ft_calloc((itr + 1), sizeof(char), err);
	if (!line || *err < 0)
		return (*err = -1, NULL);
	ft_strlcpy(line, str, itr + 1);
	return (line);
}

char	*update_static_buffer(char *str, int *err)
{
	int		i;
	char	*new_str;
	size_t	str_len;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	str_len = ft_strlen(str + i);
	if (str_len == 0)
		return (free(str), NULL);
	new_str = (char *)ft_calloc((str_len + 1), sizeof(char), err);
	if (!new_str || *err < 0)
		return (free(str), *err = -1, NULL);
	ft_strlcpy(new_str, str + i, str_len + 1);
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	int				err;
	int				fd_read;
	char			*tmp;
	char			*next_line;
	static char		*str_start[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	err = 0;
	tmp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char), &err);
	if (!tmp)
		return (free(str_start[fd]), str_start[fd] = NULL, NULL);
	fd_read = 42;
	while (!ft_strchr(str_start[fd], '\n') && fd_read != 0)
	{
		fd_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_read < 0)
			return (free(tmp), free(str_start[fd]), str_start[fd] = NULL, NULL);
		tmp[fd_read] = '\0';
		str_start[fd] = ft_strjoin(str_start[fd], tmp, &err);
		if (err < 0)
			return (free(tmp), free(str_start[fd]), str_start[fd] = NULL, NULL);
	}
	free(tmp);
	next_line = read_line(str_start[fd], &err);
	if (err < 0)
		return (free(next_line), free(str_start[fd]), str_start[fd] = NULL, NULL);
	str_start[fd] = update_static_buffer(str_start[fd], &err);
	if (err < 0)
		return (free(next_line), free(str_start[fd]), str_start[fd] = NULL, NULL);
	return (next_line);
}
