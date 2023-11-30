/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguardia <mguardia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:55:30 by mguardia          #+#    #+#             */
/*   Updated: 2023/11/30 09:48:52 by mguardia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define STDERR 2

// LIBFT - OBLIGATORY PART
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

// LIBFT - BONUS
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// PRINTF FUNCTION
int			ft_printf(char const *str, ...);
int			format_printf(char c, va_list ap);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putnbr(int n);
int			ft_putnbrunsigned(unsigned int n);
int			ft_printhexa(unsigned int num, int flag);
int			ft_printhexalong(unsigned long num);
int			ft_printpointer(void *ptr);

// GET NEXT LINE FUNCTION
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_gnl
{
	char			*str_buf;
	struct s_gnl	*next;
}					t_gnl;

char		*get_next_line(int fd);
void		ft_lstclear_gnl(t_gnl **lst, void (*del)(void *));
int			init_list(t_gnl **list, int fd);
int			find_new_line(t_gnl *list);
void		fill_list(t_gnl **list, char *str);
int			count_chars(t_gnl *list);
void		my_strcpy(char *str, t_gnl *list);
void		clean_list(t_gnl **list);
t_gnl		*ft_lstlast_gnl(t_gnl *lst);
void		clear_mem(t_gnl **list, t_gnl *rest_node, char *str);

// OTHER UTIL FUNCTIONS
void		ft_custom_error(char *error);
void		ft_error(void);
void		ft_free_matrix(void **p);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_is_format(char *str, char *format);
int			ft_is_readable(char *file);

// booleans
typedef enum
{
	false,
	true
}	t_bool;

#endif
