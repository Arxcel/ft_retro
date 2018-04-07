/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:33:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/07 10:33:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet() {
	this->_isVisible = false;
	this->_form = "-";
}

Bullet::Bullet(Bullet const & src) {
	*this = src;
}

Bullet &Bullet::operator=(Bullet const & rhs) {

	if (this != &rhs)
	{
		this->_form = rhs.getForm();
	}
	return *this;
}

Bullet::~Bullet() {

}

bool Bullet::getIsVisible() const{
	return this->_isVisible;
}

void Bullet::setIsVisible(bool b)
{
	this->_isVisible = b;
}

void Bullet::putInWindow() const {
	attron(COLOR_PAIR(2));
	mvprintw(this->_y, this->_x, this->_form.c_str());
	attroff(COLOR_PAIR(2));

}

void Bullet::move(int key, int winH, int winW, int frameCounter) {
	(void)key;
	(void)winH;
	if(frameCounter % 2 == 0)
		this->_x++;
	if (this->_x > winW)
		this->_isVisible = false;
}