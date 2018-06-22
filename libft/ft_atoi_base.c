/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:00:45 by ykaplien          #+#    #+#             */
/*   Updated: 2018/05/31 15:01:34 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int    ft_atoi_base(char *s, int base)
{
    unsigned int    res;
    int             i;

    res = 0;
    i = 0;
    if (!s)
        return (0);
    while (s[i] == ' ' || (s[i] > 8 && s[i] < 14))
        i++;
    while (s[i] && (ft_isdigit(s[i]) || (s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f')))
    {
        res = (res * base) + (s[i] - (s[i] <= 57 ? 48 : s[i] < 97 ? 55 : 87));
        i++;
    }
    return (res);
}
