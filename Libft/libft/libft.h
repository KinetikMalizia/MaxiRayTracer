/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:25:48 by nnemeth           #+#    #+#             */
/*   Updated: 2022/11/29 14:33:00 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h> 
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;	
}					t_list;

int				ft_atoi(const char *str);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isalnum(int x);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int x);
char			*ft_strchr(char *str, int c);
size_t			ft_strlen(char *str);
char			*ft_strrchr(char *str, int c);
int				ft_strncmp(const char *s1, const char *s2, int n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_isupper(int c);
int				ft_islower(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, unsigned char c, int len);
size_t			ft_strlcat(char *dst, char *src, size_t dstsize);
char			*ft_strnstr(char *big, char *small, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(char *s1);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strtrim(char *s1, char *set);
char			*ft_strmapi(char *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_itoa(int n);
char			**ft_split(char *s, char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list	*lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
int				ft_printf(const char *flag, ...);
int				ft_flag(va_list args, const char flag);
int				ft_print_char(int c);
void			ft_putstr(char *str);
int				ft_print_int(int c);
int				ft_printstr(char *str);
int				ft_print_hex(unsigned int n, const char flag);
unsigned int	ft_print_unsignedint(unsigned int c);
int				ft_print_ptr(unsigned long long ptr);
void			ft_put_ptr(unsigned long long ptr);

#endif
