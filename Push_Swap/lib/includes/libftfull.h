/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftfull.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 04:20:03 by bfleury           #+#    #+#             */
/*   Updated: 2025/02/16 21:59:05 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTFULL_H
# define LIBFTFULL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/* ******************************** LIBFT *********************************** */

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_lstsize(t_list *lst);
int			ft_atoi(const char *str);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

char		*ft_itoa(int n);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strnstr(const char *big, const char *little, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char		**ft_split(char const *s, char c);

void		ft_bzero(void *s, size_t n);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

void		*ft_memset(void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);

/* ******************************** BONUS *********************************** */

t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

size_t		ft_strlen(const char *str);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

/* ********************************* GNL ************************************ */

char		*get_next_line(int fd);

int			ft_gnl_strlen(char *str);
char		*ft_gnl_strchr(char *str, int c);
char		*ft_gnl_strdup(char *str, int len);
char		*ft_gnl_strjoin(char *str1, char *str2);

/* ******************************** PRINTF ********************************** */

int			ft_printf(const char *input, ...);

int			ft_print_int(int n);
int			ft_print_char(char c);
int			ft_print_string(char *s);
int			ft_print_unsigned(unsigned int nb);
int			ft_print_hex(unsigned int value, int asc);
int			ft_print_pointer(unsigned long value, int asc);
#endif
