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

Window::Window() {
	init();
}

Window::Window(Window const & src) {
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
//	noecho();
	curs_set(false);
	cbreak();
	keypad(stdscr, true);
	refresh();
	createWin();
}

unsigned int    Window::frame(timeval t1, timeval t2) {

	return (unsigned int)((t2.tv_sec * 1000000 + t2.tv_usec) - (t1.tv_sec * 1000000 + t1.tv_usec));
}

void	Window::createWin() {

	struct winsize size;
	ioctl(0, TIOCGWINSZ, &size);
	this->_win = newwin(size.ws_row - MENU_SIZE, size.ws_col, MENU_SIZE, 0);
	box(this->_win, 0, 0);
	wrefresh(this->_win);
	this->_isRunning = true;
	this->_input = -1;
	this->_lastInput = -1;

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

void Window::game()
{

	while (this->_isRunning)
	{
		this->_input = getch();
//		std::cout << this->_input << std::endl;
		if (this->_input == 27)
			this->_isRunning = false;
		else if (this->_input != -1)
			this->_lastInput = this->_input;
	}
}