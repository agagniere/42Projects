/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:50:45 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/06 19:58:28 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>


typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dyna
{
	void			*data;
	size_t			chunck_count;
	size_t			chunck_max;
	size_t			chunck_size;
}					t_dyna;

int		ft_atoi(const char *str);

void	ft_bzero(void *s, size_t n); // SP++

t_dyna	*ft_dyna_alloc(size_t chunck_size);
int		ft_dyna_append(t_dyna *td, void *data, size_t datalen);
void	ft_dyna_dataclear(t_dyna *t);
void	ft_dyna_dataclearf(t_dyna *t, void (*del)(void *));
int		ft_dyna_datadouble(t_dyna *td, size_t factor);
int		ft_dyna_datainit(t_dyna *td);
void	ft_dyna_del(t_dyna *td);
void	ft_dyna_free(t_dyna **tda);
t_dyna	ft_dyna_new(size_t chunck_size);
int		ft_dyna_trim(t_dyna *td);

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isblank(int c);
int		ft_iscntrl(int c);
int		ft_isdigit(int c);
int		ft_isgraph(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_ispunct(int c);
int		ft_isspace(int c);
int		ft_isupper(int c);
int		ft_isxdigit(int c);

char	*ft_itoa_base(int n, int base);
char	*ft_itoa(int n);

void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel_rec(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem));
t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstpush(t_list **alst, t_list *new);
void	ft_lstpush_rec(t_list **alst, t_list *new);

void	*ft_memalloc(size_t size);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n); //withit OK
void	*ft_memchr(const void *s, int c, size_t n); //withit OK
int		ft_memcmp(const void *s1, const void *s2, size_t n); //withit OK
void	*ft_memcpy(void *dst, const void *src, size_t n); //withit OK
void	ft_memdel(void **ap);
void	*ft_memmove(void *dst, const void *src, size_t len); //withit
void	*ft_memset(void *b, int c, size_t len); //withit

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char const *s);
void	ft_putstr_fd(char const *s, int fd);

char	*ft_strcat(char *s1, const char *s2); //withit
char	*ft_strchr(const char *s, int c); //withit
void	ft_strclr(char *s);
int		ft_strcmp(const char *s1, const char *s2); //withit
char	*ft_strcpy(char *dst, const char *src); //withit
void	ft_strdel(char **as);
char	*ft_strdup(const char *s1); // SP
int		ft_strequ(char const *s1, char const *s2); //withit
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, const char *s2); // SP
size_t	ft_strlcat(char *dst, const char *src, size_t size); //withit
size_t	ft_strlen(char const *str); //withit
char	*ft_strmap(char const *s, char (*f)(char)); // SP
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)); // SP
char	*ft_strncat(char *s1, const char *s2, size_t n); //withit
int		ft_strncmp(const char *s1, const char *s2, size_t n); //withit
char	*ft_strncpy(char *dst, const char *src, size_t n); //withit
int		ft_strnequ(char const *s1, char const *s2, size_t n); //withit
char	*ft_strnew(size_t size);
char	*ft_strnstr(const char *s1, const char *s2, size_t n); //withit
char	*ft_strrchr(const char *s, int c); //withit
char	**ft_strsplit(char const *s, char c);
char	*ft_strstr(const char *s1, const char *s2); //withit
char	*ft_strsub(char const *s, unsigned int start, size_t len); // SP
char	*ft_strtrim(char const *s); // SP

int		ft_tolower(int c);
int		ft_toupper(int c);

# define ABS(v) ((v) < 0 ? -(v) : (v))
# define DYNA_INITIAL_SIZE 64
# define DYNA_FACTOR 2

#endif
