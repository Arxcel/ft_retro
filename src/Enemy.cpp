/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:30:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/07 10:30:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

std::string darkForces[10] = {"H", "D", "B"};

Enemy::Enemy() {
	this->_isVisible = false;
	this->_form = darkForces[clock() % 5];
}

Enemy::Enemy(Enemy const & src) {
	*this = src;
}

Enemy &Enemy::operator=(Enemy const & rhs) {

	if (this != &rhs)
	{
		this->_form = rhs.getForm();
	}
	return *this;
}

Enemy::~Enemy() {

}

bool Enemy::getIsVisible() const{
	return this->_isVisible;
}

void Enemy::setIsVisible(bool b)
{
	this->_isVisible = b;
}

void Enemy::die()
{
	this->_isVisible = false;
}

void Enemy::putInWindow() const {
	if (this->_form == "H") {
		attron(COLOR_PAIR(1));
		mvprintw(this->_y, this->_x, this->_form.c_str());
		attroff(COLOR_PAIR(1));
	}
	else if (this->_form == "D") {
		attron(COLOR_PAIR(3));
		mvprintw(this->_y, this->_x, this->_form.c_str());
		attroff(COLOR_PAIR(3));
	}
	else if (this->_form == "B") {
		attron(COLOR_PAIR(4));
		mvprintw(this->_y, this->_x, this->_form.c_str());
		attroff(COLOR_PAIR(4));
	}
}

void Enemy::move(int key, int winH, int winW, int frameCounter) {
	(void)key;
	(void)winH;
	(void)winW;
	if(frameCounter % 3 == 0)
	{
		if (this->_form == "H") {
			this->_x--;
			this->_y += clock() % 2 ? 1 : (-1);
		} else {
			this->_x--;
		}


	}
	if (this->_x < 0)
		this->_isVisible = false;
}