/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxlite <linuxlite@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:02:10 by kpolojar          #+#    #+#             */
/*   Updated: 2022/04/01 01:26:54 by linuxlite        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H
# include <stdarg.h>
# include <unistd.h>
    int test_floats();
    int test_integers();
    int test_pointers();
    int test_hexadecimals();
    int test_octals();
    int test_strings();
#endif