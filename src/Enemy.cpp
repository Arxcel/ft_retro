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

Enemy::Enemy() {
}

Enemy::Enemy(int winH, int winW) {
	this->_form = "H";
	this->_y = (unsigned int)(clock() % (winH - 1));
	this->_x = winW - 1;
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

void Enemy::move(int key, int winH, int winW, int frameCount) {
	(void)key;
	(void)winH;
	(void)winW;
	(void)frameCount;
	if (frameCount % 20)
		this->_x--;
}