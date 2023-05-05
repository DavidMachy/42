/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:55:17 by dmachace          #+#    #+#             */
/*   Updated: 2023/04/04 15:33:32 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join_free(char *res, char *buff)
{
	char	*str;

	str = ft_strjoin(res, buff);
	free(res);
	return (str);
}

char	*del_line(char *buff)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (buff[i] == '\0')
	{
		free(buff);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buff) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buff[i] != '\0')
		line[j++] = buff[i++];
	free(buff);
	return (line);
}

char	*find_line(char *buff)
{
	char	*line;
	int		i;

	i = 0;
	if (!buff[i])
		return (0);
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*text_read(int fd, char *res)
{
	int		i;
	char	*buff;

	if (!res)
		res = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buff == NULL)
		return (NULL);
	i = 1;
	while (i > 0 && !ft_strchr(buff, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		res = join_free(res, buff);
	}
	free(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buff[fd] = text_read(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = find_line(buff[fd]);
	buff[fd] = del_line(buff[fd]);
	return (line);
}

/*    #include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	int		fd2;
	int		fd3;
    
	fd = open("nvm.txt", O_RDONLY);
	//bonus
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
    
	i = 0;
	while (i < 10)
	{
		line = get_next_line(fd);
		printf("line %d: %s", i, line);
		free(line);
		//bonuses
		line = get_next_line(fd2);
		printf("line %d: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line %d: %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}  */
