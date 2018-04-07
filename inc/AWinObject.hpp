/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWinObject.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:30:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/07 10:30:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWINOBJECT_HPP
# define AWINOBJECT_HPP

#include "Window.hpp"

class AWinObject {

public:
	int getX() const;
	int getY() const;
	char getForm() const;
	AWinObject(void);
	AWinObject(int x, int y);
	AWinObject(AWinObject const & win);
	virtual ~AWinObject() {};
	AWinObject &operator=(AWinObject const & win);
	virtual bool	move( int ) = 0;
	virtual void putInWindow() const;
protected:
	int _x;
	int _y;
	char _form;
};


#endif //RUSH00_AWINOBJECT_HPP
