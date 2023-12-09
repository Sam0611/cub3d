/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:11:52 by smalloir          #+#    #+#             */
/*   Updated: 2022/12/16 17:42:30 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
int		ft_findchar(char c, char *set);
int		ft_atoi(const char *nptr);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long long n);
int		ft_slen(char *str);
int		ft_nblen(long long nb);
int		ft_nblenbase(long long nb, int base);
int		ft_putnbr_base(unsigned long long nbr, char *base);
void	mdt(char c, va_list ap, int *count);
int		bonus1(char *fmt, va_list ap, int *count, int i);
int		b1size(char *fmt, va_list ap, int *count, int i);
int		b1_wp(char *fmt, va_list ap, int *count, int i);
void	b1_wp_s(char *fmt, va_list ap, int *count, int *tab);
void	b1_wp_p(char *fmt, va_list ap, int *count, int *tab);
int		b1flags(char *fmt, va_list ap, int *count, int i);
int		b1dz_di(char *fmt, va_list ap, int *count, int i);
int		b1d_p(char *fmt, va_list ap, int *count, int i);
int		b1z_p(char *fmt, va_list ap, int *count, int i);
int		b1dz_ux(char *fmt, va_list ap, int *count, int i);
int		calculate_len(char *fmt, va_list ap, int i);
void	bonus2(char *fmt, va_list ap, int *count, int i);

#endif
