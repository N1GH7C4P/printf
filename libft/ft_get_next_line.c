/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolojar <kpolojar@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:39:48 by kpolojar          #+#    #+#             */
/*   Updated: 2021/12/14 15:44:36 by kpolojar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	append_last_line(char **storage, char **line)
{
	char	*temp;

	if (*storage)
	{
		if (!*line)
			*line = ft_strdup(*storage);
		else
		{
			temp = ft_strdup(*line);
			if (!temp)
				return (-1);
			ft_strdel(line);
			*line = ft_strcat(temp, *storage);
			ft_strdel(&temp);
		}
		ft_strdel(storage);
		if (!*line || *storage)
			return (-1);
		return (1);
	}
	return (0);
}

static int	append_line(char **storage, char **line, char *next_newline)
{
	int		dist_to_newline;
	char	*new_storage;

	if (!next_newline)
		return (append_last_line(storage, line));
	else if (*storage)
	{
		dist_to_newline = next_newline - *storage;
		if (!*line)
			*line = ft_strndup(*storage, dist_to_newline);
		else
			ft_strncat(*line, *storage, dist_to_newline);
		new_storage = ft_strdup(*storage + dist_to_newline + 1);
		if (!new_storage)
			return (-1);
		ft_strdel(storage);
		*storage = new_storage;
		if (!*line || !*storage)
			return (-1);
		return (1);
	}
	return (0);
}

int	append_storage(char **storage, char *buf)
{
	char	*temp;

	if (!*storage && !buf)
		return (-1);
	if (!*storage)
		*storage = ft_strdup(buf);
	else
	{
		temp = ft_strdup(*storage);
		if (!temp)
			return (-1);
		ft_strdel(storage);
		*storage = ft_strjoin(temp, buf);
		ft_strdel(&temp);
	}
	return (1);
}

static int	read_from_buffer(int fd, char **storage)
{
	char	*buf;
	int		read_status;

	buf = ft_strnew(BUFF_SIZE);
	if (!buf)
		return (-1);
	read_status = read(fd, buf, BUFF_SIZE);
	while (read_status > 0)
	{
		buf[read_status] = '\0';
		if (append_storage(storage, buf) < 1)
			read_status = -1;
		if (ft_strchr(*storage, '\n') || read_status <= 0)
			break ;
		read_status = read(fd, buf, BUFF_SIZE);
	}
	free(buf);
	if (read_status >= 0 && *storage)
		return (1);
	if (!storage[fd])
		read_status = -1;
	return (read_status);
}

int	ft_get_next_line(const int fd, char **line)
{
	static char	*storage[FD_MAX];
	int			return_value;
	char		*next_newline;

	if (!line || fd < 0 || BUFF_SIZE < 1 || fd > FD_MAX - 1)
		return (-1);
	*line = NULL;
	if (!(storage[fd] && ft_strchr(storage[fd], '\n')))
		return_value = read_from_buffer(fd, &storage[fd]);
	else
		return_value = 1;
	if (return_value == 1)
	{
		if (!storage[fd][0])
			return (0);
		next_newline = ft_strchr(storage[fd], '\n');
		return_value = append_line(&storage[fd], line, next_newline);
	}
	return (return_value);
}
