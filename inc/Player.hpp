/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:30:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/07 10:30:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP
#include "AWinObject.hpp"

class Player : public AWinObject {
public:
	Player();
	Player(Player const &p);
	~Player();
	void move(int, int, int);
	Player &operator=(Player const &w);
};


#endif //RUSH00_PLAYER_HPP
