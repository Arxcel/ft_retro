/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWinObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:30:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/15 14:09:18 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWinObject.hpp"

AWinObject::AWinObject() : _x(5), _y(5), _form(" ") {

}

AWinObject::AWinObject(int x, int y) : _x(x), _y(y),  _form(" ") {

}

AWinObject::AWinObject(AWinObject const & src) : _x(src._x), _y(src._y), _form(src._form) {

}

AWinObject::~AWinObject() {

}

int AWinObject::getX() const {
	return _x;
}

int AWinObject::getY() const {
	return _y;
}

void AWinObject::setX(int x){
	_x = x;
}

void AWinObject::setY(int y){
	if (y < 3)
		y = 3;
	_y = y;
}

std::string AWinObject::getForm() const {
	return _form;
}

AWinObject &AWinObject::operator=(AWinObject const & rhs) {

	if (this != &rhs) {
		_form = rhs.getForm();
		_x = rhs.getX();
		_y = rhs.getY();
	}
	return *this;
}

void AWinObject::putInWindow() const {
	mvprintw(_y, _x, _form.c_str());
}