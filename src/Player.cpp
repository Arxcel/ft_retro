/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:30:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/07 10:30:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player() {
	this->_form = "}";
}

Player::Player(Player const & src) {
	*this = src;
}

Player &Player::operator=(Player const & rhs) {

	if (this != &rhs)
	{
		this->_form = rhs.getForm();
	}
	return *this;
}

Player::~Player() {

}

void Player::move(int key) {
	if (key == KEY_DOWN)
		this->_y++;
	else if (key == KEY_UP)
		this->_y--;
	else if (key == KEY_LEFT)
		this->_x--;
	else if (key == KEY_RIGHT)
		this->_x++;
}