/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWinObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:30:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/07 10:30:00 by vkozlov          ###   ########.fr       */
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
	return this->_x;
}

int AWinObject::getY() const {
	return this->_y;
}

std::string AWinObject::getForm() const {
	return this->_form;
}

AWinObject &AWinObject::operator=(AWinObject const & rhs) {

	if (this != &rhs) {
		this->_form = rhs.getForm();
		this->_x = rhs.getX();
		this->_y = rhs.getY();
	}
	return *this;
}

void AWinObject::putInWindow() const {
	mvprintw(this->_y, this->_x, this->_form.c_str());
}