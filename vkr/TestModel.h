#ifndef TESTMODEL_H
#define TESTMODEL_H

typedef int content_type_t;

typedef std::exception LockedException;

class Container
{
};

class LockableContainer: public Container
{
};

class Movable
{
public:
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual void getXY(int& x, int& y) = 0;
	virtual void setXY(int x, int y) = 0;
	virtual void setX(int x) = 0;
	virtual void setY(int y) = 0;
};

class Browseable
{
public:
	virtual content_type_t browse() throw(LockedException) = 0;
};

class Chest: public LockableContainer
{
protected:
	content_type_t content;
};

class MovableChest: public Chest
{
protected:
	int x;
	int y;
};

typedef Chest* ChestArray;

class MovableChestArray
{
protected:
	MovableChest* chests;
	int chestCount;
public:
	virtual MovableChest* getChests();
	virtual void addChest(MovableChest& mc);
	virtual int getChestCount();
	static void createMovableChestArray(int num);
	MovableChestArray(int size);
	virtual ~MovableChestArray();
};


#endif /* TESTMODEL_H */
