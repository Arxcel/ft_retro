/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 20:51:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/15 14:09:18 by vkozlov          ###   ########.fr       */
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
	_isVisible = false;
	_form = ".";
}

Background::Background(Background const & src) {
	*this = src;
}

Background &Background::operator=(Background const & rhs) {

	if (this != &rhs)
	{
		_form = rhs.getForm();
	}
	return *this;
}

Background::~Background() {

}

bool Background::getIsVisible() const{
	return _isVisible;
}

void Background::setIsVisible(bool b)
{
	_isVisible = b;
}

void Background::move(int key, int winH, int winW, int frameCounter) {
	(void)key;
	(void)winH;
	(void)winW;
	if(frameCounter % 1 == 0)
		_x--;
	if (_x < 0)
		_isVisible = false;
}