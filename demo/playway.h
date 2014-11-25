#ifndef _PLAYWAY_H
#define _PLAYWAY_H
//头文件包含
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
//命名空间
using namespace std;
//using namespace playway;
//类定义
class Player
{
	public:
	         Player();
		void setName(string);
		string getName();
		void setSattle(bool);
		bool getSattle();
		void move(int);
		int  getPos();
		void setPos(int);
	private:
		string name;
		int    pos;
//		int    number;
		bool   isSattled;
};

Player::Player()
{
//	number = Num;
	name = "null";
	pos = 0;
}
void Player::setSattle(bool y=false)
{
	isSattled = y;
}
bool Player::getSattle()
{
	return isSattled;
}
void Player::move(int count)
{
	pos += count;
	if(pos<0)
		pos = 0;
	else if(pos>99)
		pos = 99;
}
int Player::getPos()
{
	return pos;
}
void Player::setName(string Name)
{
	name = Name;
}
string Player::getName()
{
	return name;
}
void Player::setPos(int p)
{
	pos = p;
}





//全局变量
int Map[100]={0};
Player player[2];
//player player1,player2;


#endif
