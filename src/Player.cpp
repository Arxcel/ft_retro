/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:30:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/15 14:09:18 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player() {
	_form = "}";
	_hP = 5;
}

Player::Player(Player const & src) {
	*this = src;
}

Player &Player::operator=(Player const & rhs) {

	if (this != &rhs)
	{
		_form = rhs.getForm();
	}
	return *this;
}

Player::~Player() {

}
void Player::putInWindow() const {
	attron(COLOR_PAIR(2));
	mvprintw(_y, _x, _form.c_str());
	attroff(COLOR_PAIR(2));
}

int Player::getHp() const {
	return _hP;
}

void  Player::setHp(int newHp)  {
	_hP = newHp;
}

void Player::move(int key, int winH, int winW, int frameCounter) {
	if (frameCounter)
	{
		if ((key == KEY_DOWN || key == 's' || key == 'S') && _y < winH)
			_y++;
		else if ((key == KEY_UP || key == 'w' || key == 'W') && _y > 3)
			_y--;

		if ((key == KEY_LEFT || key == 'a' || key == 'A') && _x > 1)
			_x--;
		else if ((key == KEY_RIGHT || key == 'd' || key == 'D') && _x < winW - 2)
			_x++;
	}
}