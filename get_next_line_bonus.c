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

char	*read_line(char *str)
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
	line = (char *)malloc((itr + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, str, itr + 1);
	return (line);
}

char	*update_static_buffer(char *str)
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
	{
		free(str);
		return (NULL);
	}
	new_str = (char *)malloc((str_len + 1) * sizeof(char));
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(new_str, str + i, str_len + 1);
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	int				fd_read;
	char			*tmp;
	static char		*str_start[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	fd_read = 42;
	while (!ft_strchr(str_start[fd], '\n') && fd_read != 0)
	{
		fd_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_read < 0)
			return (free(tmp), free(str_start[fd]), str_start[fd] = NULL, NULL);
		tmp[fd_read] = '\0';
		str_start[fd] = ft_strjoin(str_start[fd], tmp);
	}
	free(tmp);
	tmp = read_line(str_start[fd]);
	str_start[fd] = update_static_buffer(str_start[fd]);
	return (tmp);
}
