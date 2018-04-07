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
	nodelay(stdscr, TRUE);
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
	this->_wW = size.ws_col;
	this->_wH = size.ws_row - MENU_SIZE;
	this->_win = newwin(this->_wH, this->_wW, MENU_SIZE, 0);
	wrefresh(this->_win);
}

void	Window::destroyWin() {
	clear();
	wrefresh(this->_win);
	delwin(this->_win);
}

void	Window::updateFrame(int a, Enemy &b) {
	this->_player.move(this->_lastInput, this->_wH, this->_wW, this->_frameCounter);
	if (a)
		b.move(0,this->_wH, this->_wW, this->_frameCounter);
}

void	Window::reDraw(int a, Enemy &b) const
{
	this->_player.putInWindow();
	if (a)
		b.putInWindow();
}



void Window::game()
{
	Enemy *e = nullptr;
	int f = 0;
	while (this->_isRunning)
	{
		this->_input = getch();
		if (this->_input == 'q' || this->_input == 'Q')
			return ;
		else if (this->_input != ERR)
			this->_lastInput = this->_input;
		gettimeofday(&this->_tvalAfter, nullptr);
		if (this->frameTime(this->_tvalBefore, this->_tvalAfter) >= 60000)
		{
			this->destroyWin();
			this->createWin();
			if (_frameCounter == 5)
			{
				e = new Enemy(this->_wH, this->_wW);
				f = 1;
			}
			this->updateFrame(f, *e);
			this->reDraw(f, *e);
			this->_tvalBefore = this->_tvalAfter;
			this->_frameCounter++;
			this->_lastInput = ERR;
		}
	}
}