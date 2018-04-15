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
	_isVisible = false;
	_form = "<-";
}

EnemyBullet::EnemyBullet(EnemyBullet const & src) {
	*this = src;
}

EnemyBullet &EnemyBullet::operator=(EnemyBullet const & rhs) {

	if (this != &rhs)
	{
		_form = rhs.getForm();
	}
	return *this;
}

EnemyBullet::~EnemyBullet() {

}

bool EnemyBullet::getIsVisible() const{
	return _isVisible;
}

void EnemyBullet::setIsVisible(bool b)
{
	_isVisible = b;
}

void EnemyBullet::putInWindow() const {
	attron(COLOR_PAIR(1));
	mvprintw(_y, _x, _form.c_str());
	attroff(COLOR_PAIR(1));

}

void EnemyBullet::move(int key, int winH, int winW, int frameCounter) {
	(void)key;
	(void)winH;
	(void)winW;
	if(frameCounter % 1 == 0)
		_x--;
	if (_x < 0)
		_isVisible = false;
}