/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:14:48 by efleta            #+#    #+#             */
/*   Updated: 2019/09/23 17:10:06 by efleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define HASH_P				31
# define HASH_M				1000000009

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
void			*ft_memset(void *destination, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy (void *destination, const void *source, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove (void *destination, const void *source, size_t n);
int				ft_tolower(int c);
int				ft_toupper(int a);
int				ft_isprint(int a);
int				ft_isascii(int a);
int				ft_isalnum(int a);
int				ft_isdigit(int a);
int				ft_isalpha(int a);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dest, const char *src);
size_t			ft_strlen(const char *s);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strncat(char *dest, const char *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *nptr);
size_t			ft_strlcat(char *d, const char *s, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char **s1, char **s2, int f, int s);
char			*ft_strtrim(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putchar(char c);
void			ft_putendl(char const *s);
void			ft_putstr(char const *s);
void			ft_putnbr(int n);
void			ft_putendl_fd(char const *s, int fd);
char			*ft_itoa(int n);
void			ft_putnbr_fd(int n, int fd);
char			**ft_strsplit(char const *s, char c);
char			*ft_strtrim(char const *s);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char			**ft_strsplit1(char const *s, char c);
char			**ft_strsplit2(char const *s, char *separators);
void			*ft_x_memalloc(size_t size);
int				ft_strhash(const char *str);

#endif
