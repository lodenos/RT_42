/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/11/05 02:50:35 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H
#define BUFF_SIZE 60
#define MAX_FD	255
#define MIN_FD 0
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct      s_list
{
    void            *content;
    size_t          content_size;
    struct s_list   *next;
}                   t_list;

void                free_tab(void **tab);
int                 ft_atoi(char const *s);
void                ft_bzero(void *s, size_t n);
int                 ft_isalnum(int c);
int                 ft_isalpha(int c);
int                 ft_isascii(int c);
int                 ft_isdigit(int c);
int                 ft_isprint(int c);
char                *ft_itoa(int n);
void                ft_lstadd(t_list **alst, t_list *new);
void                ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void                ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void                ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list              *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list              *ft_lstnew(void const *content, size_t content_size);
void                *ft_memalloc(size_t size);
void                *ft_memccpy(void *dest, void const *src, int c, size_t n);
void                *ft_memchr(void const *s, int c, size_t n);
void                *ft_memcpy(void *dest, void const *src, size_t n);
int                 ft_memcmp(void const *s1, void const *s2, size_t n);
void                ft_memdel(void **as);
void                *ft_memmove(void *dest, void const *src, size_t n);
void                *ft_memset(void *s, int c, size_t n);
void                ft_print_tab(char **tab, char *str);
void                ft_putchar(char c);
void                ft_putchar_err(char c);
void                ft_putchar_fd(char c, int fd);
void                ft_putendl(char const *s);
void                ft_putendl_fd(char const *s, int fd);
void                ft_putnbr(int n);
void                ft_putnbr_fd(int n, int fd);
void                ft_putstr(char const *s);
void                ft_putstr_err(const char *str, int quit);
void                ft_putstr_fd(char const *s, int fd);
void                ft_putstr_tab(char **str, char *sep);
void                *ft_realloc(void *ptr, size_t size);
char                *ft_strchr(char const *s, int c);
char                *ft_strcat(char *dest, char const *src);
void                ft_strclr(char *s);
int                 ft_strcmp(char const *s1, char const *s2);
int                 ft_strcmp_case(char const *s1, char const *s2);
char                *ft_strcpy(char *dest, char const *src);
void                ft_strdel(char **as);
char                *ft_strdup(char const *s);
int                 ft_strequ(char const *s1, char const *s2);
void                ft_striter(char *s, void (*f)(char *));
void                ft_striteri(char *s, void (*f)(unsigned int, char *));
char                *ft_strjoin(char const *s1, char const *s2);
size_t              ft_strlcat(char *dest, char const *src, size_t count);
size_t              ft_strlen(char const *s);
int                 ft_strlen_tab(char **tab);
char                *ft_strmap(char const *s, char (*f)(char));
char                *ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t              ft_strnbr_idtchar(char *str, char c);
char                *ft_strncat(char *dest, char const *src, size_t n);
int                 ft_strnequ(char const *s1, char const *s2, size_t n);
char                *ft_strnew(size_t size);
char                *ft_strnstr(char const *s1, char const *s2, size_t len);
int                 ft_strncmp(char const *s1, char const *s2, size_t n);
char                *ft_strncpy(char *dest, char const *src, size_t n);
char                *ft_strrchr(char const *s, int c);
char                **ft_strsplit(char const *s, char c);
char                *ft_strstr(char const *str, char const *to_find);
char                *ft_strsub(char const *s, unsigned int start, size_t len);
char                *ft_strtrim(char const *s);
int                 ft_tolower(int c);
int                 ft_toupper(int c);
int                 get_next_line(int const fd, char **line);
void                **matrix_sqrt(unsigned int x, unsigned int y);
void                matrix_sqrt_free(char **map, size_t n);

#endif
