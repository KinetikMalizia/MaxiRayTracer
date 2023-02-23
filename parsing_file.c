/*

#include "MiniRT.h"


char *readfile(char *filename)
{
	int fd = open(filename, O_RDONLY);
	char buffer[BUFSIZE];
	char *line = NULL;
	size_t line_size = 0;
	ssize_t bytes_read = 0;
	int i;

	i = 0;
	if (fd < 0)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFSIZE)) > 0)
	{
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
			{
				line = ft_realloc(line, line_size + i + 1);
				ft_memcpy(line + line_size, buffer, i);
				line[line_size + i] = '\0';
				line_size += i + 1;
				printf("%s\n", line);
				line_size = 0;
			}
			else
			{
				line = ft_realloc(line, line_size + bytes_read - i);
				ft_memcpy(line + line_size, buffer + i, bytes_read - i);
				line_size += bytes_read - i;
				break;
			}
			i++;
		}
		i = 0;
	}
	if (line_size > 0)
	{
		line = ft_realloc(line, line_size + 1);//need to fix realloc
		ft_memcpy(line + line_size, "\0", 1);
	}
	close(fd);
	return (line);
}

char **split_string(const char *str, char sep)
{
	size_t count = 0;
	size_t i = 0;
	size_t j = 0;
	size_t len = 0;
	char **result;

	while (str[i] != '\0')
	{
		if (str[i] == sep)
			count++;
		i++;
	}
	result = (char **)malloc((count + 2) * sizeof(char *));
	if (!result)
		return NULL;
	i = 0;
	while (str[i] != '\0')
	{
		len = 0;
		while (str[i + len] != sep && str[i + len] != '\0')
			len++;

		result[j] = (char *)malloc((len + 1) * sizeof(char));
		if (!result[j])
		{
			for (i = 0; i < j; i++)
				free(result[i]);
			free(result);
			return NULL;
		}

		ft_strncpy(result[j], str + i, len);
		result[j][len] = '\0';
		i += len;
		if (str[i] == sep)
			i++;
		j++;
	}
	result[j] = NULL;
	return result;
}

char **second_split(char *str)
{
	char **words = NULL;
	int word_count = 0;
	char *word_start = str;
	char *word_end = str;

	while (*word_end != '\0')
	{
		if (ft_isspace(*word_end))
		{
			word_start = word_end + 1;
			word_end = word_start;
			continue;
		}
		word_end++;
		if (ft_isspace(*word_end) || *word_end == '\0')
		{
			words = (char **)ft_realloc(words, (word_count + 1) * sizeof(char *));
			int word_length = word_end - word_start;
			words[word_count] = (char *)malloc((word_length + 1) * sizeof(char));
			strncpy(words[word_count], word_start, word_length);
			words[word_count][word_length] = '\0';
			word_start = word_end + 1;
			word_count++;
		}
	}
	words = (char **)ft_realloc(words, (word_count + 1) * sizeof(char *));
	words[word_count] = NULL;
	//free(word_start);
	//free(word_end);
	return (words);
}

void convert_tab(char **tab, t_data *data)
{
	(void)data;
	int x = 0;
	char **ret;
	char **vector;

	vector = NULL;
	ret = NULL;
	printf("tab is = \n");
	print_tab(tab);
	printf("-------------------\n");
	while (tab[x])
	{
		if (contains_alpha(tab[x]))
		{
			// printf("%d = x, string = %s\n", x, tab[x]);
			if (ft_strinstr(tab[x], "A"))
			{
				ret = second_split(tab[x]);
print_tab(ret);
				data->light.type = *ret[0];
				data->light.ratio = ft_strtof(ret[1]);
				vector = split_string(ret[2], ',');
				data->light.color.col_r = ft_strtof(vector[0]);
				data->light.color.col_g = ft_strtof(vector[1]);
				data->light.color.col_b = ft_strtof(vector[2]);
				free_tab(vector);
				free_tab(ret);
			}
			if (ft_strinstr(tab[x], "C"))
			{
				ret = second_split(tab[x]);
print_tab(ret);
				vector = split_string(ret[1], ',');
				data->camera.coord.x = ft_strtof(vector[0]);
				data->camera.coord.y = ft_strtof(vector[1]);
				data->camera.coord.z = ft_strtof(vector[2]);
				free_tab(vector);
				vector = split_string(ret[2], ',');
				data->camera.orient.x = ft_strtof(vector[0]);
				data->camera.orient.y = ft_strtof(vector[0]);
				data->camera.orient.z = ft_strtof(vector[0]);
				data->camera.fov = ft_stoi(ret[3]);
				free_tab(vector);
				free_tab(ret);
			}
			if (ft_strinstr(tab[x], "L"))
			{
				ret = second_split(tab[x]);
print_tab(ret);
				data->light.type = *ret[0];
				vector = split_string(ret[1], ',');
				data->light.coord.x = ft_strtof(vector[0]);
				data->light.coord.y = ft_strtof(vector[1]);
				data->light.coord.z = ft_strtof(vector[2]);
				free_tab(vector);
				data->light.ratio = ft_strtof(ret[2]);
				vector = split_string(ret[3], ',');
				data->light.color.col_r = ft_strtof(vector[0]);
				data->light.color.col_g = ft_strtof(vector[1]);
				data->light.color.col_b = ft_strtof(vector[2]);
				free_tab(vector);
				free_tab(ret);
			}
			if (ft_strinstr(tab[x], "sp"))
			{
				ret = second_split(tab[x]);
print_tab(ret);
				data->object.type = ret[0];
				vector = split_string(ret[1], ',');
				data->object.coord.x = ft_strtof(vector[0]);
				data->object.coord.y = ft_strtof(vector[1]);
				data->object.coord.z = ft_strtof(vector[2]);
				free_tab(vector);
				data->object.sphere_rad = (ft_strtof(ret[2]) / 2);
				vector = split_string(ret[3], ',');
				data->object.color.col_r = ft_strtof(vector[0]);
				data->object.color.col_g = ft_strtof(vector[1]);
				data->object.color.col_b = ft_strtof(vector[2]);
				free_tab(vector);
				free_tab(ret);
			}
			if (ft_strinstr(tab[x], "pl"))
			{
				ret = second_split(tab[x]);
print_tab(ret);
				data->object.type = ret[0];
				vector = split_string(ret[1], ',');
				data->object.coord.x = ft_strtof(vector[0]);
				data->object.coord.y = ft_strtof(vector[1]);
				data->object.coord.z = ft_strtof(vector[2]);
				free_tab(vector);
				vector = split_string(ret[2], ',');
				data->object.orient.x = ft_strtof(vector[0]);
				data->object.orient.y = ft_strtof(vector[1]);
				data->object.orient.z = ft_strtof(vector[2]);
				free_tab(vector);
				vector = split_string(ret[3], ',');
				data->object.color.col_r = ft_strtof(vector[0]);
				data->object.color.col_g = ft_strtof(vector[1]);
				data->object.color.col_b = ft_strtof(vector[2]);
				free_tab(vector);
				free_tab(ret);
			}
			if (ft_strinstr(tab[x], "cy"))
			{
				ret = second_split(tab[x]);
print_tab(ret);
				data->object.type = ret[0];
				vector = split_string(ret[1], ',');
				data->object.coord.x = ft_strtof(vector[0]);
				data->object.coord.y = ft_strtof(vector[1]);
				data->object.coord.z = ft_strtof(vector[2]);
				free_tab(vector);
				vector = split_string(ret[2], ',');
				data->object.orient.x = ft_strtof(vector[0]);
				data->object.orient.y = ft_strtof(vector[1]);
				data->object.orient.z = ft_strtof(vector[2]);
				free_tab(vector);
				data->object.cyl_dia = ft_strtof(ret[3]);
				data->object.cyl_height = ft_strtof(ret[4]);
				vector = split_string(ret[5], ',');
				data->object.color.col_r = ft_strtof(vector[0]);
				data->object.color.col_g = ft_strtof(vector[1]);
				data->object.color.col_b = ft_strtof(vector[2]);
				free_tab(vector);
				free_tab(ret);
			}
			x++;
		}
	}
	free_tab(tab);
}


*/