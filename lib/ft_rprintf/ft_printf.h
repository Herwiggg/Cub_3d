/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:47:57 by loculy            #+#    #+#             */
/*   Updated: 2023/01/02 17:19:11 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_plist
{
	void			*content;
	int				size;
	struct s_plist	*next;
}	t_plist;

typedef struct s_mn
{
	int	*error;
	int	*i;
}	t_mn;

typedef struct s_flag
{
	unsigned int	value;
	unsigned int	before;
	unsigned int	after;
	int				justify;
	int				zero;
	int				precision;
	int				prefix;
	int				blank;
	int				positive;
	char			x;
}	t_flag;

typedef struct s_mnf
{
	int		*error;
	t_flag	flag;
}	t_mnf;

typedef struct s_of
{
	char	*s;
	char	*m;
}	t_of;

typedef struct s_fn
{
	unsigned int	*out_sz;
	unsigned int	s_sz;
	unsigned int	i;
}	t_fn;

typedef struct s_stzd
{
	char			*s;
	unsigned int	*out_sz;
	unsigned int	*s_sz;
	unsigned int	*o_sz;
	unsigned int	*neg;
	unsigned int	*x;
}	t_stzd;

char			*ft_finalize(char *s, char *m, t_flag flag, t_fn fn);
t_stzd			ft_flag_ouszd_b(t_stzd stzd, t_flag flag);
t_stzd			ft_flag_ouszd_a(t_stzd stzd, t_flag flag);
void			ft_flag_pref(t_of of, t_flag flag, int i);
char			*ft_fl_init(char *m, unsigned int out_sz);
char			*ft_fl_nj_d(t_of of, unsigned int s_sz,
					unsigned int out_sz, t_flag flag);
char			*ft_fl_nj_s(char *s, char *m, unsigned int s_sz,
					unsigned int out_sz);
char			*ft_fl_j_d(t_of of, unsigned int s_sz, unsigned int i,
					t_flag flag);
char			*ft_fl_j_s(char *s, char *m, unsigned int s_sz);
unsigned int	ft_get_ouszd(char *s, t_flag flag, unsigned int *out_sz);
unsigned int	ft_get_ouszs(char *s, t_flag flag, int nt,
					unsigned int *out_sz);
char			*ft_fl_m_s(char *s, t_flag flag, int nt, unsigned int *out_sz);
char			*ft_fl_m_d(char *s, t_flag flag, unsigned int *out_sz);
unsigned int	ft_flag_size(char *s, int nt);
int				ft_fg_c(char c, t_plist **out, int *error, t_flag flag);
int				ft_fg_s(char *s, t_plist **out, int *error, t_flag flag);
int				ft_fg_p(void *p, t_plist **out, int *error, t_flag flag);
int				ft_fg_d(int a, t_plist **out, int *error, t_flag flag);
int				ft_fg_u(unsigned int a, t_plist **out, int *error, t_flag flag);
int				ft_fg_x(unsigned int a, t_plist **out, int *error, t_flag flag);
int				ft_fg_xx(unsigned int a, t_plist **out, int *error,
					t_flag flag);
t_flag			ft_strflag_init(void);
t_flag			ft_flag_head(char *fmt, t_flag flag, int *i);
t_flag			ft_flag_sub(char *fmt, t_flag flag, int *i);
int				ft_flag_format(va_list	arg, char ff, t_plist **out, t_mnf mnf);
int				ft_flag_start_checker(char ff);
int				ft_flag_checker(char ff);
int				ft_type_checker(char ff);
int				ft_flag_valider(char *fmt);
int				ft_flag(va_list	arg, t_plist **out, char *fmt, t_mn mn);
int				ft_error_return(int *error, int erv);
int				ft_error_return_free(int *error, int erv, char *m);
t_plist			*ft_plstnew(void *content);
void			ft_plstadd_back(t_plist **lst, t_plist *new);
int				ft_phex_sz(unsigned long n);
char			*ft_phex(unsigned long n);
char			*ft_pitoa_loop(unsigned int n, char *m,
					unsigned int size, int neg);
unsigned int	ft_pitoa_size(unsigned int use);
char			*ft_pitoa(unsigned int n);
char			*ft_ithex(unsigned int n, char *ref);
int				ft_w_c(char c, t_plist **out, int *error);
int				ft_w_s(char *s, t_plist **out, int *error);
int				ft_w_p(void *p, t_plist **out, int *error);
int				ft_w_d(int a, t_plist **out, int *error);
int				ft_w_u(unsigned int a, t_plist **out, int *error);
int				ft_w_x(unsigned int a, t_plist **out, int *error);
int				ft_w_xx(unsigned int a, t_plist **out, int *error);
void			ft_lstclean(t_plist **lst);
void			ft_res_read(t_plist *act, char *res);
char			*ft_result(int size, t_plist *out, int *error);
unsigned int	ft_printf_loop(va_list arg, const char *fmt, t_plist **out,
					int *error);
int				ft_parse_format(va_list	arg, char *ff,
					t_plist **out, t_mn mn);
char			*ft_rprintf(const char *fmt, ...);

#endif