/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:41:01 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/22 18:21:40 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' \
			|| c == '\r' || c == '\f' || c == '\v');
}

int			ft_atoi(const char *str)
{
	const	char			*p;
	unsigned long long int	number;

	while (ft_isspace(*str))
		str++;
	p = str;
	if (*str == '+' || *str == '-')
		p++;
	number = 0;
	while (*p && *p <= '9' && *p >= '0' && number <= 9223372036854775807)
	{
		number += (number < 9223372036854775807) ? *p - '0' : '0';
		if (*(p + 1) <= '9' && *(p + 1) >= '0')
			number *= (number < 9223372036854775807) ? 10 : 1;
		p++;
	}
	if (*str == '-')
		return (number > 9223372036854775807) ? (0) : (-(int)(number));
	if (number > 9223372036854775807)
		return (-1);
	return (number);
}
