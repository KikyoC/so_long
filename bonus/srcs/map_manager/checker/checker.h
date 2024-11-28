/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:24:50 by togauthi          #+#    #+#             */
/*   Updated: 2024/11/28 11:01:54 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <so_long.h>

int	full(t_row *row);
int	check_border(t_map *map);
int	is_rect(t_map *map);
int	check_elements(t_map *map);

#endif