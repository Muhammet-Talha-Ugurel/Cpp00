/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mugurel <mugurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:04:58 by mugurel           #+#    #+#             */
/*   Updated: 2024/03/19 00:05:00 by mugurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setName(std::string name) {
    this->name = name;
}

void Contact::setSurname(std::string surname) {
    this->surname = surname;
}

void Contact::setPhone(std::string phone) {
    this->phone = phone;
}

void Contact::setNickname(std::string nick_name) {
    this->nick_name = nick_name;
}

void Contact::setDarkestSecret(std::string darkest_secret) {
    this->darkest_secret = darkest_secret;
}

std::string Contact::getName() {
    return this->name;
}

std::string Contact::getSurname() {
    return this->surname;
}

std::string Contact::getPhone() {
    return this->phone;
}

std::string Contact::getNickname() {
    return this->nick_name;
}

std::string Contact::getDarkestSecret() {
    return this->darkest_secret;
}