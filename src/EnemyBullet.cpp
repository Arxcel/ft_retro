/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyBullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:33:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/07 10:33:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyBullet.hpp"

EnemyBullet::EnemyBullet() {
	this->_isVisible = false;
	this->_form = "<-";
}

EnemyBullet::EnemyBullet(EnemyBullet const & src) {
	*this = src;
}

EnemyBullet &EnemyBullet::operator=(EnemyBullet const & rhs) {

	if (this != &rhs)
	{
		this->_form = rhs.getForm();
	}
	return *this;
}

EnemyBullet::~EnemyBullet() {

}

bool EnemyBullet::getIsVisible() const{
	return this->_isVisible;
}

void EnemyBullet::setIsVisible(bool b)
{
	this->_isVisible = b;
}

void EnemyBullet::putInWindow() const {
	attron(COLOR_PAIR(1));
	mvprintw(this->_y, this->_x, this->_form.c_str());
	attroff(COLOR_PAIR(1));

}

void EnemyBullet::move(int key, int winH, int winW, int frameCounter) {
	(void)key;
	(void)winH;
	(void)winW;
	if(frameCounter % 1 == 0)
		this->_x--;
	if (this->_x < 0)
		this->_isVisible = false;
}