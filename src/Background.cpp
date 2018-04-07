/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 20:51:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/07 20:51:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:30:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/07 10:30:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Background.hpp"

Background::Background() {
	this->_isVisible = false;
	this->_form = ".";
}

Background::Background(Background const & src) {
	*this = src;
}

Background &Background::operator=(Background const & rhs) {

	if (this != &rhs)
	{
		this->_form = rhs.getForm();
	}
	return *this;
}

Background::~Background() {

}

bool Background::getIsVisible() const{
	return this->_isVisible;
}

void Background::setIsVisible(bool b)
{
	this->_isVisible = b;
}

void Background::move(int key, int winH, int winW, int frameCounter) {
	(void)key;
	(void)winH;
	(void)winW;
	if(frameCounter % 1 == 0)
		this->_x--;
	if (this->_x < 0)
		this->_isVisible = false;
}