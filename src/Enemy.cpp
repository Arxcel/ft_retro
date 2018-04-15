/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:30:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/15 14:09:18 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

std::string darkForces[3] = {"H", "D", "B"};

Enemy::Enemy() {
	_isVisible = false;
	_isForward = false;
	_form = darkForces[clock() % 3];
}

Enemy::Enemy(Enemy const & src) {
	*this = src;
}

Enemy &Enemy::operator=(Enemy const & rhs) {

	if (this != &rhs)
	{
		_form = rhs.getForm();
	}
	return *this;
}

Enemy::~Enemy() {

}

bool Enemy::getIsVisible() const{
	return _isVisible;
}

void Enemy::setIsVisible(bool b)
{
	_isVisible = b;
}

void Enemy::putInWindow() const {
	if (_form == "H") {
		attron(COLOR_PAIR(1));
		mvprintw(_y, _x, _form.c_str());
		attroff(COLOR_PAIR(1));
	}
	else if (_form == "D") {
		attron(COLOR_PAIR(3));
		mvprintw(_y, _x, _form.c_str());
		attroff(COLOR_PAIR(3));
	}
	else if (_form == "B") {
		attron(COLOR_PAIR(4));
		mvprintw(_y, _x, _form.c_str());
		attroff(COLOR_PAIR(4));
	}
}

void Enemy::move(int key, int winH, int winW, int frameCounter) {
	(void)key;
	(void)winH;
	(void)winW;
	if(frameCounter % 3 == 0)
	{
		if (_form == "H") {
			_y += clock() % 2 ? 1 : (-1);
		} else if (_form == "D"){
			if (_isForward)
				_y++;
			else
				_y--;
			if (_y < 0 || _y > winH)
				_isForward = !_isForward;
		}
			_x--;
	}
	if (_x < 0)
		_isVisible = false;
}