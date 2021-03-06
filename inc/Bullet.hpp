/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:33:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/07 10:33:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP
# include "AWinObject.hpp"

class Bullet : public virtual AWinObject {
	
	public:
		Bullet(Bullet const &p);
		Bullet();
		~Bullet();
		void move(int, int, int, int);
		Bullet &operator=(Bullet const &w);
		bool getIsVisible() const;
		void setIsVisible(bool);
		void putInWindow() const;
//		void die();
	private:
		bool _isVisible;
};


#endif //RUSH00_BULLET_HPP
