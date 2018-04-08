/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:30:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/08 12:44:08 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player() {
	this->_form = "}";
	this->_hP = 5;
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
void Player::putInWindow() const {
	attron(COLOR_PAIR(2));
	mvprintw(this->_y, this->_x, this->_form.c_str());
	attroff(COLOR_PAIR(2));
}

int Player::getHp() const {
	return this->_hP;
}

void  Player::setHp(int newHp)  {
	this->_hP = newHp;
}

void Player::move(int key, int winH, int winW, int frameCounter) {
	if (frameCounter)
	{
		if ((key == KEY_DOWN || key == 's' || key == 'S') && this->_y < winH)
			this->_y++;
		else if ((key == KEY_UP || key == 'w' || key == 'W') && this->_y > 3)
			this->_y--;

		if ((key == KEY_LEFT || key == 'a' || key == 'A') && this->_x > 1)
			this->_x--;
		else if ((key == KEY_RIGHT || key == 'd' || key == 'D') && this->_x < winW - 2)
			this->_x++;
	}
}