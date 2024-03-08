/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erramos <erramos@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:02:33 by erramos           #+#    #+#             */
/*   Updated: 2023/11/12 18:19:31 by erramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnb(int nb)
{
	char	*nu;
	int		len;

	nu = ft_itoa(nb);
	len = ft_putstr(nu);
	free(nu);
	return (len);
}
