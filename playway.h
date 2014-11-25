#ifndef _PLAYWAY_H
#define _PLAYWAY_H
//头文件包含
#include <iostream>
#include <string>
//命名空间
using namespace std;
//using namespace playway;
//类定义
class player
{
	public:
	         player(string,int);
		void setName(string);
		void setSattle(bool);
		void move(int);
		int  getPos();
	private:
		string name;
		int    pos;
		bool   isSattled;
};

player::player(string Name="NULL",int where=0)
{
	name = Name;
	pos = where;
}
void player::setSattle(bool y=false)
{
	isSattled = y;
}
void player::move(int count)
{
	pos += count;
}
int player::getPos()
{
	return pos;
}
void player::setName(string Name)
{
	name = Name;
}


//函数申明
void InitialMap();
void DrawMap();




//全局变量
int Map[100]={0};
player player1,player2;


#endif
