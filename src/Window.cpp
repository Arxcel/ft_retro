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

int Window::_countEnemy = 0;
int Window::_countBackground = 0;
int Window::_countBullet = 0;
int Window::_countEnemyBullet = 0;
Window::Window() {
	this->_enemies = new Enemy[ENEMY_NUM];
	this->_stars = new Background[BACKGROUND_NUM];
	this->_bullets = new Bullet[BULLET_NUM];
	this->_enemyBullets = new EnemyBullet[ENEMY_BULLET_NUM];
	this->_frameCounter = 0;
	this->_score = 0;
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
	delete[] this->_enemies;
	delete[] this->_stars;
	delete[] this->_bullets;
	delete[] this->_enemyBullets;
	std::cout << "\\=== GAME OVER ===/" << std::endl;
}

void	Window::init() {

	initscr();
	noecho();
	curs_set(false);
	cbreak();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	start_color();
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, nullptr);
	refresh();
	init_pair(0, COLOR_BLACK, COLOR_WHITE);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);

	createWin();
	this->_input = ERR;
	this->_lastInput = ERR;
	this->_isRunning = true;
	gettimeofday(&this->_baseTime, nullptr);
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

void	Window::checkCollision()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (this->_enemies[i].getIsVisible()
			&& this->_player.getY() == this->_enemies[i].getY()
			&& this->_player.getX() == this->_enemies[i].getX()){
			this->_isRunning = false;
		}
	}
}

void	Window::checkPlayerShot()
{
	for (int i = 0; i < BULLET_NUM; i++) {
		for (int j = 0; j < ENEMY_NUM; j++) {
			if (this->_enemies[j].getIsVisible() && this->_bullets[i].getIsVisible())
			{
				if (this->_bullets[i].getX() == this->_enemies[j].getX() && this->_bullets[i].getY() == this->_enemies[j].getY())
				{
					this->_enemies[j].setIsVisible(false);
					this->_bullets[i].setIsVisible(false);
					if (this->_enemies[j].getForm() == "H")
						this->_score += 100;
					else
						this->_score += 10;
				}
			}
		}
	}
}

void	Window::checkEnemyBulletCollision()
{
	for (int i = 0; i < ENEMY_BULLET_NUM; i++) {
		if (this->_enemyBullets[i].getIsVisible()
			&& this->_player.getY() == this->_enemyBullets[i].getY()
			&& this->_player.getX() == this->_enemyBullets[i].getX()){
			this->_player.setHp(this->_player.getHp() - 1);
			this->_enemyBullets[i].setIsVisible(false);
			if (!this->_player.getHp())
				this->_isRunning = false;
		}
	}
}

void	Window::updateFrame() {
	this->_player.move(this->_lastInput, this->_wH, this->_wW, this->_frameCounter);
	this->checkEnemyBulletCollision();
	this->checkCollision();
	for (int i = 0; i < BACKGROUND_NUM; i++) {
		if (this->_stars[i].getIsVisible()){
			this->_stars[i].move(0, this->_wH, this->_wW, this->_frameCounter);
		}
	}
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (this->_enemies[i].getIsVisible()){
			this->_enemies[i].move(0, this->_wH, this->_wW, this->_frameCounter);
			this->checkPlayerShot();
			if (this->_frameCounter % 21 == 0)
				generateEnemyBullet(this->_enemies[i]);
		}
	}
	this->checkCollision();
	for (int i = 0; i < BULLET_NUM; i++) {
		if (this->_bullets[i].getIsVisible()){
			this->_bullets[i].move(0, this->_wH, this->_wW, this->_frameCounter);
		}
	}
	this->checkPlayerShot();
	for (int i = 0; i < ENEMY_BULLET_NUM; i++) {
		if (this->_enemyBullets[i].getIsVisible()){
			this->_enemyBullets[i].move(0, this->_wH, this->_wW, this->_frameCounter);
		}
	}
	this->checkEnemyBulletCollision();
}

void	Window::reDraw() const
{
	mvprintw((int)(this->_wH * 0.02), (int)(this->_wW * 0.02), "SCORE ");
	mvprintw((int)(this->_wH * 0.02), (int)(this->_wW * 0.12), "%d", this->_score);

	mvprintw((int)(this->_wH * 0.02), (int)(this->_wW * 0.90), "%d", this->_player.getHp());
	mvprintw((int)(this->_wH * 0.02), (int)(this->_wW * 0.85), "LIFE");
	for (int i = 0; i < BACKGROUND_NUM; i++) {
		if (this->_stars[i].getIsVisible()){
			this->_stars[i].putInWindow();
		}
	}
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (this->_enemies[i].getIsVisible()){
			this->_enemies[i].putInWindow();
		}
	}
	this->_player.putInWindow();
	for (int i = 0; i < BULLET_NUM; i++) {
		if (this->_bullets[i].getIsVisible()){
			this->_bullets[i].putInWindow();
		}
	}
	for (int i = 0; i < ENEMY_BULLET_NUM; i++) {
		if (this->_enemyBullets[i].getIsVisible()){
			this->_enemyBullets[i].putInWindow();
		}
	}
}

void			Window::generateEnemy()
{
	_countEnemy++;
	if (!this->_enemies[_countEnemy % ENEMY_NUM].getIsVisible() &&
			!(this->frameTime(this->_baseTime, this->_tvalAfter) % clock() % 10))
	{
		this->_enemies[_countEnemy % ENEMY_NUM].setIsVisible(true);
		this->_enemies[_countEnemy % ENEMY_NUM].setX(this->_wW);
		this->_enemies[_countEnemy % ENEMY_NUM].setY((unsigned int)(clock() % (this->_wH)));
	}
}

void			Window::generateBackground()
{
	_countBackground++;
	if (!this->_stars[_countBackground % BACKGROUND_NUM].getIsVisible())
	{
		this->_stars[_countBackground % BACKGROUND_NUM].setIsVisible(true);
		this->_stars[_countBackground % BACKGROUND_NUM].setX(this->_wW);
		this->_stars[_countBackground % BACKGROUND_NUM].setY((unsigned int)(clock() % (this->_wH)));
	}
}

void			Window::generateBullet()
{
	_countBullet++;
	if (!this->_bullets[_countBullet % BULLET_NUM].getIsVisible())
	{
		this->_bullets[_countBullet % BULLET_NUM].setIsVisible(true);
		this->_bullets[_countBullet % BULLET_NUM].setX(this->_player.getX() + 1);
		this->_bullets[_countBullet % BULLET_NUM].setY(this->_player.getY());
	}
}
void			Window::generateEnemyBullet(Enemy const &e)
{
	if (clock() % 13 == 0 && e.getIsVisible())
	{
		_countEnemyBullet++;
		if (!this->_enemyBullets[_countEnemyBullet % ENEMY_BULLET_NUM].getIsVisible())
		{
			this->_enemyBullets[_countEnemyBullet % ENEMY_BULLET_NUM].setIsVisible(true);
			this->_enemyBullets[_countEnemyBullet % ENEMY_BULLET_NUM].setX(e.getX() - 1);
			this->_enemyBullets[_countEnemyBullet % ENEMY_BULLET_NUM].setY(e.getY());
		}
	}
}

void Window::game()
{
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
			this->generateBackground();
			this->generateEnemy();
			if (this->_lastInput == ' ')
				this->generateBullet();
			this->updateFrame();
			this->reDraw();
			this->_tvalBefore = this->_tvalAfter;
			this->_frameCounter++;
			this->_lastInput = ERR;
		}
	}
}