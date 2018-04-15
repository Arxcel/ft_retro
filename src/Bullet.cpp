/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:33:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/15 14:09:18 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet() {
	_isVisible = false;
	_form = "->";
}

Bullet::Bullet(Bullet const & src) {
	*this = src;
}

Bullet &Bullet::operator=(Bullet const & rhs) {

	if (this != &rhs)
	{
		_form = rhs.getForm();
	}
	return *this;
}

Bullet::~Bullet() {

}

bool Bullet::getIsVisible() const{
	return _isVisible;
}

void Bullet::setIsVisible(bool b)
{
	_isVisible = b;
}

void Bullet::putInWindow() const {
	attron(COLOR_PAIR(2));
	mvprintw(_y, _x, _form.c_str());
	attroff(COLOR_PAIR(2));

}

void Bullet::move(int key, int winH, int winW, int frameCounter) {
	(void)key;
	(void)winH;
	if(frameCounter % 1 == 0)
		_x++;
	if (_x > winW)
		_isVisible = false;
}