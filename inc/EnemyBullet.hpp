
#ifndef ENEMYBULLET_HPP
# define ENEMYBULLET_HPP
# include "AWinObject.hpp"

class EnemyBullet : public virtual AWinObject {
	
	public:
	EnemyBullet(EnemyBullet const &p);
	EnemyBullet();
	~EnemyBullet();
	void move(int, int, int, int);
	EnemyBullet &operator=(EnemyBullet const &w);
	bool getIsVisible() const;
	void setIsVisible(bool);
	void putInWindow() const;
	private:
	bool _isVisible;
};


#endif //
