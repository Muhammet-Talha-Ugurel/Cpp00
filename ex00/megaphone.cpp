/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <mugurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:05:52 by mugurel           #+#    #+#             */
/*   Updated: 2024/03/19 00:05:54 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char** arg) {
    if (ac < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }
    else {
        for (int i = 1; i < ac; i++) {
            for (int j = 0; arg[i][j]; j++) {
                std::cout << (char)toupper(arg[i][j]);
            }
        }
    }
    std::cout << std::endl;
    return (0);
}