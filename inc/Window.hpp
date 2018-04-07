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
class Window {
public:

		Window();
		Window(Window const &w);
		~Window();

		Window &operator=(Window const &w);
		void			init();
		void			createWin();
		void			destroyWin();
		WINDOW			&getWin() const;
		void			game();
		unsigned int	frame(timeval t1, timeval t2);


		private:
	WINDOW			*_win;
	int				_isRunning;
	int 			_lastInput;
	int 			_input;

};


#endif //RUSH00_WINDOW_HPP
