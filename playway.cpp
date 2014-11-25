#include "playway.h"
//地图初始化
static void DrawMapWay(int i);
extern void InitialMap()
{
	int boom[7] = {6,19,23,44,36,68,89};
	int stop[6] = {4,14,38,55,78,97};
	int lucky[5]= {7,33,56,76,80};
	int ship[4]  = {10,30,50,70};
	for(int i=0;i<boom.count;i++)
	{
		Map[boom[i]] = 1;
	}
	for(int i=0;i<stop.count;i++)
	{
		Map[stop[i]] = 2;
	}
	for(int i=0;i<lucky.count;i++)
	{
		Map[lucky[i]] = 3;
	}
	for(int i=0;i<ship.count;i++)
	{
		Map[ship[i]] = 4;
	}
}

//
extern void DrawMap()
{
	for(int i=0;i<30;i++)
	{
		DrawMapWay(i);
	}
	cout<<endl;
	for(int i=30;i<35;i++)
	{
		for(int j=0;j<29;j++)
			cout<<"  ";
		DrawMapWay(i);
		cout<<endl;
	}
	for(int i=64;i>34;i--)
	{
		DrawMapWay(i);
	}
	cout<<endl;
	for(int i=65;i<5;i++)
	{
		DrawMapWay(i);
		cout<<endl;
	}
	for(int i=70;i<30;i++)
	{
		DrawMapWay(i);
	}
}

static void DrawMapWay(int i)
{
	if(player1.getPos() == player2.getPos()&&player1.getPos()==i)
	{
		cout<<"<>";
	}
	else if(player1.getPos() == i)
	{
		cout<<"Ａ";
	}
	else if(player2.getPos() == i)
	{
		cout<<"Ｂ";
	}
	else
	{
		switch(Map[i])
		{
			case 0:
				cout<<"□";
				break;
			case 1:
				cout<<"☆";
				break;
			case 2:
				cout<<"▲";
				break;
			case 3:
				cout<<"○";
				break;
			case 4:
				cout<<"※";
				break;
		}
	}
}
