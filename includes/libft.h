/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:40:24 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/22 18:47:11 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define GNL_BUFF_SIZE 42

# define _IS_NAN(n) ((n) != (n)) ? 1 : 0
# define _IS_POS_INF(n) ((n) == (1.0 / 0.0) ? 1 : 0)
# define _IS_NEG_INF(n) ((n) == (-1.0 / 0.0) ? 1 : 0)

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_lst
{
	char			*str;
	int				fd;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_int_arr_mult
{
	int		  		*r;
	int		  		a_tmp;
	int		  		b_tmp;
	int		  		r_len;
}			  		t_int_arr_mult;

typedef struct		s_int_arr_subtr
{                   
	int				flag;
	int				find;
	int				count;
	int				r_a_len;
	int				r_b_len;
	int				r_len;
	int				*r;
}					t_int_arr_subtr;

typedef struct		s_sum_two_digits
{                   
	int				i;
	int				r_len;
	int				*r;
}					t_sum_two_digits;

typedef struct		s_pos_exp_of_digit
{
	int				i;
	int				r_len;
	int				*r;
}					t_pos_exp_of_digit;

#define				MAX_PERIOD 100

typedef struct		s_neg_exp_of_digit
{
	int				tmp;
	int				sw;
	int				*r;
	int				r_pos;
	int				r_len;
	int				*div;
	int				div_len;
	int				*per;
	int				per_len;
}					t_neg_exp_of_digit;

typedef struct		s_int_arr_division
{
	int				r_len;
	int				*r;
}					t_int_arr_division;

__int128			ft_len_of_digit(__int128 d);
t_neg_exp_of_digit	*ft_neg_exp_of_digit(int dig, int base);
t_pos_exp_of_digit	*ft_pos_exp_of_digit(int dig, int base);
t_sum_two_digits	*ft_sum_two_digits(int *a, int *b, int  a_len, int b_len);
t_int_arr_subtr		*ft_int_arr_subtr(int *a, int *b, int a_len, int b_len);
t_int_arr_mult		*ft_int_arr_mult(int *a, int *b, int a_len, int b_len);

void				move_int_arr(int *a, int a_len);
void				ft_print_int_arr(int *a, int a_len);
void				ft_lstiter(t_list *lst, void (*f) (t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del) (void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del) (void *, size_t));
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putendl(const char *s);
void				ft_putstr(const char *s);
void				ft_putchar(char c);
void				ft_striteri(char *s, void (*f) (unsigned int, char *));
void				ft_striter(char *s, void (*f) (char *));
void				ft_strclr(char *s);
void				ft_strdel(char **ap);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *stc, size_t n);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strndup(const char *s, size_t n);
char				*ft_itoa(int n);
char				*ft_strtrim(char const *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s1);
char				**ft_get_arr(size_t x, size_t y);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
size_t				ft_strlen_chr(const char *s, const char c);
size_t				ft_count_words(char const *s, char c);
size_t				ft_strlcat(char *dest, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);

int					srch_int_in_arr(int *a, int a_len, int srch);
int					get_next_line(const int fd, char **line);
int					ft_is_space(int i);
int					ft_is_lower(int i);
int					ft_is_upper(int i);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
__int128			ft_atoi(const char *str);
#endif