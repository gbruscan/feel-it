/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndauteui <ndauteui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 13:26:42 by ndauteui          #+#    #+#             */
/*   Updated: 2013/12/25 13:30:42 by ndauteui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		i;
	int		number;
	int		positive;

	i = 0;
	number = 0;
	positive = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	else if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		positive = 0;
		i++;
	}
	else if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	number = ((positive == 0) ? 0 - number : 0 + number);
	return (number);
}
