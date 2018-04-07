/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:30:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/07 10:30:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP
#include "AWinObject.hpp"

class Enemy: public virtual AWinObject {
public:
	Enemy(Enemy const &p);
	Enemy(int, int);
	~Enemy();
	void move(int, int, int, int);
	Enemy &operator=(Enemy const &w);

private:
	Enemy();
};


#endif //RUSH00_ENEMY_HPP
