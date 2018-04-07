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
# define MENU_SIZE 2
# include <ncurses.h>
# include <iostream>
# include <sys/time.h>
# include <sys/ioctl.h>
# include "Player.hpp"
# include "Enemy.hpp"

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
		void			reDraw(int a, Enemy &b) const;
		void			updateFrame(int a, Enemy &b);


private:
	WINDOW			*_win;
	int 			_wW;
	int 			_wH;
	int				_isRunning;
	int 			_lastInput;
	int 			_input;
	struct timeval	_tvalBefore;
	struct timeval	_tvalAfter;
	Player			_player;
	int				_frameCounter;

};


#endif //RUSH00_WINDOW_HPP
