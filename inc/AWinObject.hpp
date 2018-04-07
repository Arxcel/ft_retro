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
# include <ncurses.h>
# include <string>

class AWinObject {

public:
	int getX() const;
	int getY() const;
	std::string getForm() const;
	AWinObject();
	AWinObject(int x, int y);
	AWinObject(AWinObject const & win);
	virtual ~AWinObject();
	AWinObject &operator=(AWinObject const & win);
	virtual void	move(int, int, int) = 0;
	virtual void putInWindow() const;
protected:
	int _x;
	int _y;
	std::string _form;
};


#endif //RUSH00_AWINOBJECT_HPP
