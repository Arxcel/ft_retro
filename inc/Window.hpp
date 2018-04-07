/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 09:29:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/07 09:29:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP
# include <ncurses.h>
# include <iostream>
# include <sys/time.h>
# include <sys/ioctl.h>
# include "Player.hpp"
# include "Enemy.hpp"
# include "Background.hpp"
# include "Bullet.hpp"
# define MENU_SIZE 2
# define ENEMY_NUM 500
# define BULLET_NUM 500
# define BACKGROUND_NUM 500

class Window {
public:

		Window();
		Window(Window const &w);
		~Window();

		Window &operator=(Window const &w);
		void			init();
		void			createWin();
		void			destroyWin();
		void			game();
		unsigned int	frameTime(timeval t1, timeval t2);
		void			reDraw() const;
		void			updateFrame();
		void			generateEnemy();
		void			generateBackground();
		void			generateBullet();
		void			checkCollision();

private:
	WINDOW			*_win;
	int				_score;
	int 			_wW;
	int 			_wH;
	int				_isRunning;
	int 			_lastInput;
	int 			_input;
	struct timeval	_tvalBefore;
	struct timeval	_tvalAfter;
	struct timeval	_baseTime;
	Player			_player;
	int				_frameCounter;
	Background		*_stars;
	Enemy 			*_enemies;
	Bullet 			*_bullets;
	static int		_countEnemy;
	static int		_countBackground;
	static int		_countBullet;
};


#endif //RUSH00_WINDOW_HPP
