/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:13:27 by fschmid           #+#    #+#             */
/*   Updated: 2022/11/23 14:29:09 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_count_digit(unsigned long n, int base)
{
	size_t	ans;

	if (n <= 0)
		ans = 1;
	else
		ans = 0;
	while (n)
	{
		ans++;
		n /= base;
	}
	return (ans);
}

char	*ft_strprefix(char *prefix, char *str)
{
	char	*res;

	res = ft_strjoin(prefix, str);
	free(str);
	return (res);
}

char	*ft_ptoa(long n)
{
	char	*d;

	d = ft_itoa_base(n, 1);
	return (ft_strprefix("0x", d));
}

u_int32_t	ft_parse_color(char *str)
{
	size_t		len;
	char		*itoa;
	char		*base;

	if (lower == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	len = ft_count_digit(n, 16);
	itoa = ft_calloc(len + 1, sizeof(char));
	if (!itoa)
		return (NULL);
	if (n == 0)
		itoa[0] = '0';
	if (n < 0)
	{
		itoa[0] = '-';
		n = -n;
	}
	while (len-- && n)
	{
		itoa[len] = base[n % 16];
		n /= 16;
	}
	return (itoa);
}

// u_int32_t	ft_parse_color(char *str)
// {
// 	static const char	*base1 = "0123456789abcdef";
// 	static const char	*base2 = "0123456789ABCDEF";
// 	int					v;

// 	if (str == NULL)
// 		v = ;
// 	else
// 	{
// 		v = 0;
// 		str += 3;
// 		while ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f')
// 			|| (*str >= 'A' && *str <= 'F'))
// 		{
// 			v = v * 16 + (ft_stridx(*str >= 'a' ? base1 : base2, *str));
// 			++str;
// 		}
// 	}
// 	return (v);
// }