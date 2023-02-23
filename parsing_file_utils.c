/*

#include "MiniRT.h"

char *ft_realloc(char *org, int n_size)
{
	char *new;

	new = malloc(n_size);
	if (!new)
		return (NULL);
	ft_strcpy(new, org, n_size);
	if (org)
		free(org);
	return (new);
}

char *ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return dest;
}

char *ft_strcpy(char *dest, char *src, size_t dest_size)
{
	size_t i;
	size_t src_len;

	if (!dest || !src)
		return NULL;

	src_len = ft_strlen(src);
	if (src_len >= dest_size)
		return NULL;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return dest;
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	if(tab == NULL)
		return ;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], 1);
		printf("\n");
		++i;
	}
}

int ft_stoi(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		else
			return 0;	
	++i;
	}
	return (sign * result);
}

float ft_strtof(const char* str)
{
    float result = 0.0f;
    int is_negative = 0;
    float decimal_multiplier = 0.1f;

    while (ft_isspace(*str))
        str++;
    if (*str == '-')
	{
        is_negative = 1;
        str++;
    } 
	else if (*str == '+')
        str++;
    while (ft_isdigit(*str)) 
	{
        result = result * 10.0f + (*str - '0');
        str++;
    }
    if (*str == '.') 
	{
        str++;
        while (ft_isdigit(*str)) 
		{
            result += decimal_multiplier * (*str - '0');
            decimal_multiplier *= 0.1f;
            str++;
        }
    }
    if (is_negative)
        result = -result;
    while (ft_isspace(*str))
        str++;
    if (*str != '\0') 
	{
        printf("Error: invalid input string\n");
        return 0.0f;
    }
    return result;
}

int ft_strinstr(const char *str, const char *substr)
{
	int i;
	int j;
	int k;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == substr[0])
		{
			j = 1;
			k = i + 1;
			while (substr[j] != '\0')
			{
				if (str[k] != substr[j])
					break;
				j++;
				k++;
			}
			if (substr[j] == '\0')
				return 1;
		}
		i++;
	}
	return (0);
}



*/