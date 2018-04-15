/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlov <vkozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 09:29:00 by vkozlov           #+#    #+#             */
/*   Updated: 2018/04/15 14:09:53 by vkozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"

int Window::_countEnemy = 0;
int Window::_countBackground = 0;
int Window::_countBullet = 0;
int Window::_countEnemyBullet = 0;

Window::Window() {
	_enemies = new Enemy[ENEMY_NUM];
	_stars = new Background[BACKGROUND_NUM];
	_bullets = new Bullet[BULLET_NUM];
	_enemyBullets = new EnemyBullet[ENEMY_BULLET_NUM];
	_frameCounter = 0;
	_score = 0;
	init();
}

Window::Window(Window const & src) {
	_frameCounter = 0;
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
	delete[] _enemies;
	delete[] _stars;
	delete[] _bullets;
	delete[] _enemyBullets;
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
	_input = ERR;
	_lastInput = ERR;
	_isRunning = true;
	gettimeofday(&_baseTime, nullptr);
}

unsigned int    Window::frameTime(struct timeval t1, struct timeval t2) {
	return (unsigned int)((t2.tv_sec * 1000000 + t2.tv_usec) - (t1.tv_sec * 1000000 + t1.tv_usec));
}

void	Window::createWin() {

	struct winsize size;
	ioctl(0, TIOCGWINSZ, &size);
	gettimeofday(&_tvalBefore, nullptr);
	_wW = size.ws_col;
	_wH = size.ws_row - MENU_SIZE;
	_win = newwin(_wH, _wW, MENU_SIZE, 0);
	wrefresh(_win);
}

void	Window::destroyWin() {
	erase();
	wrefresh(_win);
	delwin(_win);
}

void	Window::checkCollision()
{
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (_enemies[i].getIsVisible()
			&& _player.getY() == _enemies[i].getY()
			&& _player.getX() == _enemies[i].getX()){
			_isRunning = false;
		}
	}
}

void	Window::checkPlayerShot()
{
	for (int i = 0; i < BULLET_NUM; i++) {
		for (int j = 0; j < ENEMY_NUM; j++) {
			if (_enemies[j].getIsVisible() && _bullets[i].getIsVisible())
			{
				if (_bullets[i].getX() == _enemies[j].getX() && _bullets[i].getY() == _enemies[j].getY())
				{
					_enemies[j].setIsVisible(false);
					_bullets[i].setIsVisible(false);
					if (_enemies[j].getForm() == "H")
						_score += 500;
					else if(_enemies[j].getForm() == "D")
						_score += 100;
					else
						_score += 10;
				}
			}
		}
	}
}

void	Window::checkEnemyBulletCollision()
{
	for (int i = 0; i < ENEMY_BULLET_NUM; i++) {
		if (_enemyBullets[i].getIsVisible()
			&& _player.getY() == _enemyBullets[i].getY()
			&& _player.getX() == _enemyBullets[i].getX()){
			_player.setHp(_player.getHp() - 1);
			_enemyBullets[i].setIsVisible(false);
			if (!_player.getHp())
				_isRunning = false;
		}
	}
}

void	Window::updateFrame() {
	_player.move(_lastInput, _wH, _wW, _frameCounter);
	checkEnemyBulletCollision();
	checkCollision();
	for (int i = 0; i < BACKGROUND_NUM; i++) {
		if (_stars[i].getIsVisible()){
			_stars[i].move(0, _wH, _wW, _frameCounter);
		}
	}
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (_enemies[i].getIsVisible()){
			_enemies[i].move(0, _wH, _wW, _frameCounter);
			checkPlayerShot();
			if (_frameCounter % 21 == 0)
				generateEnemyBullet(_enemies[i]);
		}
	}
	checkCollision();
	for (int i = 0; i < BULLET_NUM; i++) {
		if (_bullets[i].getIsVisible()){
			_bullets[i].move(0, _wH, _wW, _frameCounter);
		}
	}
	checkPlayerShot();
	for (int i = 0; i < ENEMY_BULLET_NUM; i++) {
		if (_enemyBullets[i].getIsVisible()){
			_enemyBullets[i].move(0, _wH, _wW, _frameCounter);
		}
	}
	checkEnemyBulletCollision();
}

void	Window::reDraw() const
{
	mvprintw(2, (int)(_wW * 0.02), "SCORE ");
	mvprintw(2, (int)(_wW * 0.12), "%d", _score);

	mvprintw(2, (int)(_wW * 0.90), "%d", _player.getHp());
	mvprintw(2, (int)(_wW * 0.85), "LIFE");
	for (int i = 0; i < BACKGROUND_NUM; i++) {
		if (_stars[i].getIsVisible()){
			_stars[i].putInWindow();
		}
	}
	for (int i = 0; i < ENEMY_NUM; i++) {
		if (_enemies[i].getIsVisible()){
			_enemies[i].putInWindow();
		}
	}
	_player.putInWindow();
	for (int i = 0; i < BULLET_NUM; i++) {
		if (_bullets[i].getIsVisible()){
			_bullets[i].putInWindow();
		}
	}
	for (int i = 0; i < ENEMY_BULLET_NUM; i++) {
		if (_enemyBullets[i].getIsVisible()){
			_enemyBullets[i].putInWindow();
		}
	}
}

void			Window::generateEnemy()
{
	_countEnemy++;
	if (!_enemies[_countEnemy % ENEMY_NUM].getIsVisible() &&
			!(frameTime(_baseTime, _tvalAfter) % clock() % 10))
	{
		_enemies[_countEnemy % ENEMY_NUM].setIsVisible(true);
		_enemies[_countEnemy % ENEMY_NUM].setX(_wW);
		_enemies[_countEnemy % ENEMY_NUM].setY((unsigned int)(clock() % (_wH)));
		_enemies[_countEnemy % ENEMY_NUM]._isForward = _enemies[_countEnemy % ENEMY_NUM].getY() < _wH / 2;
	}
}

void			Window::generateBackground()
{
	_countBackground++;
	if (!_stars[_countBackground % BACKGROUND_NUM].getIsVisible())
	{
		_stars[_countBackground % BACKGROUND_NUM].setIsVisible(true);
		_stars[_countBackground % BACKGROUND_NUM].setX(_wW);
		_stars[_countBackground % BACKGROUND_NUM].setY((unsigned int)(clock() % (_wH)));
	}
}

void			Window::generateBullet()
{
	_countBullet++;
	if (!_bullets[_countBullet % BULLET_NUM].getIsVisible())
	{
		_bullets[_countBullet % BULLET_NUM].setIsVisible(true);
		_bullets[_countBullet % BULLET_NUM].setX(_player.getX() + 1);
		_bullets[_countBullet % BULLET_NUM].setY(_player.getY());
	}
}
void			Window::generateEnemyBullet(Enemy const &e)
{
	if (clock() % 13 == 0 && e.getIsVisible())
	{
		_countEnemyBullet++;
		if (!_enemyBullets[_countEnemyBullet % ENEMY_BULLET_NUM].getIsVisible())
		{
			_enemyBullets[_countEnemyBullet % ENEMY_BULLET_NUM].setIsVisible(true);
			_enemyBullets[_countEnemyBullet % ENEMY_BULLET_NUM].setX(e.getX() - 1);
			_enemyBullets[_countEnemyBullet % ENEMY_BULLET_NUM].setY(e.getY());
		}
	}
}

void Window::game()
{
	while (_isRunning)
	{
		_input = getch();
		if (_input == 'q' || _input == 'Q')
			return ;
		else if (_input != ERR)
			_lastInput = _input;
		gettimeofday(&_tvalAfter, nullptr);
		if (frameTime(_tvalBefore, _tvalAfter) >= 40000)
		{
			destroyWin();
			createWin();
			generateBackground();
			generateEnemy();
			if (_lastInput == ' ')
				generateBullet();
			updateFrame();
			reDraw();
			_tvalBefore = _tvalAfter;
			_frameCounter++;
			_lastInput = ERR;
		}
	}
}