/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:35:11 by nelidris          #+#    #+#             */
/*   Updated: 2022/02/08 14:45:20 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"
# define DECB "0123456789"
# define UHEXB "0123456789ABCDEF"
# define LHEXB "0123456789abcdef"

int		ft_printf(const char *str, ...);
char	*ft_itoa_base(int nbr, char *base);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_print_address(void *str);
int		ft_putnbr_base_unsigned(unsigned int nbr, char *base);
int		ft_putnbr_base(int nbr, char *base);

#endif