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

Window::Window() {
	this->_frameCounter = 0;
	init();
}

Window::Window(Window const & src) {
	this->_frameCounter = 0;
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
	this->_input = ERR;
	this->_lastInput = ERR;
	this->_isRunning = true;
}

unsigned int    Window::frameTime(struct timeval t1, struct timeval t2) {
	return (unsigned int)((t2.tv_sec * 1000000 + t2.tv_usec) - (t1.tv_sec * 1000000 + t1.tv_usec));
}

void	Window::createWin() {

	struct winsize size;
	ioctl(0, TIOCGWINSZ, &size);
	gettimeofday(&this->_tvalBefore, nullptr);
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

void	Window::updateFrame() {
	this->_player.move(this->_lastInput);
}

void	Window::reDraw() const
{
	this->_player.putInWindow();
}



void Window::game()
{
	this->reDraw();
	while (this->_isRunning)
	{
		this->_input = getch();
		std::cout << "test" << std::endl;
		if (this->_input == 27)
			return ;
		else if (this->_input != ERR)
			this->_lastInput = this->_input;
		gettimeofday(&this->_tvalAfter, nullptr);
		printw("Code of pressed key is %d\n", this->_input);
		if (this->frameTime(this->_tvalBefore, this->_tvalAfter) >= 16.6)
		{
			this->destroyWin();
			this->createWin();
			this->updateFrame();
			this->reDraw();
			this->_tvalBefore = this->_tvalAfter;
			this->_frameCounter++;
			this->_lastInput = ERR;
		}
	}
}