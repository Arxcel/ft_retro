/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 09:29:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/07 09:29:00 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"
#include <sys/ioctl.h>

Window::Window()
{

	init();
}

Window::Window(Window const & src)
{

	init();
	*this = src;
}

Window &Window::operator=(Window const & rhs) {

	if (this != &rhs)
	{

	}
	return *this;
}

Window::~Window() {
	destroyWin();
	endwin();
	std::cout << "\\=== GAME OVER ===/" << std::endl;
}

void	Window::init() {

	initscr();
	noecho();
	curs_set(false);
	cbreak();
	keypad(stdscr, true);
	refresh();
	createWin();
}

void	Window::createWin() {

	struct winsize size;
	ioctl(0, TIOCGWINSZ, &size);
	this->_win = newwin(size.ws_row - MENU_SIZE, size.ws_col, MENU_SIZE, 0);
	box(this->_win, 0, 0);
	wrefresh(this->_win);
}

void	Window::destroyWin() {
	wrefresh(this->_win);
	clear();
	refresh();
	delwin(this->_win);
}

WINDOW &Window::getWin() const
{
	return *this->_win;
}

//void Window::game()
//{
//	this->_input = getch();
//}