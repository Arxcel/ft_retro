/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 20:55:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/07 20:55:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUND_H
# define BACKGROUND_H
#include "AWinObject.hpp"

class Background: public virtual AWinObject {

public:
	Background(Background const &p);
	Background();
	~Background();
	void move(int, int, int, int);
	Background &operator=(Background const &w);
	bool getIsVisible() const;
	void setIsVisible(bool);
private:
	bool _isVisible;
};

#endif