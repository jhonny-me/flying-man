#include "playway.h"
//#include "playway.cpp"

void play(int,int);
void InitialMap();
void DrawMap();
void hello();
static int random(int,int);

//Player player[2];

int main(int argc ,char *argv[])
{
	hello();
	if(argc!=2)
	{
		cout<<"Please input your name to play"<<endl;
		string name;
		cin>>name;
		player[0].setName(name);
	}
	else
	{
		string name(argv[1]);
		player[0].setName(name);
	}
	InitialMap();
	DrawMap();
	while(1)
	{
		if(player[0].getSattle()== true)
		{
			player[0].setSattle(false);
		}
		else
		{
			play(0,random(1,7));
		}
		if(player[0].getPos()>=99)
		{
			cout<<player[0].getName()<<"已经跑到火星去了"<<endl;
			break;
		}
		if(player[1].getSattle()==true)
		{
			player[1].setSattle(false);
		}
		else
		{
			play(1,random(1,7));
		}
		if(player[1].getPos()>=99)
		{
			cout<<player[0].getName()<<"已经跑到火星去了"<<endl;
			break;
		}
	}
}



//游戏头
void hello()
{
	cout<<"*******************************"<<endl;
	cout<<"*******************************"<<endl;
	cout<<"********flying man v0.1********"<<endl;
	cout<<"*******************************"<<endl;
	cout<<"*******************************"<<endl;
}



//地图初始化
static void DrawMapWay(int i);
void InitialMap()
{
	int boom[7] = {6,19,23,44,36,68,89};
	int stop[6] = {4,14,38,55,78,97};
	int lucky[5]= {7,33,56,76,80};
	int ship[4]  = {10,30,50,70};
	for(int i=0;i<7;i++)
	{
		Map[boom[i]] = 1;
	}
	for(int i=0;i<6;i++)
	{
		Map[stop[i]] = 2;
	}
	for(int i=0;i<5;i++)
	{
		Map[lucky[i]] = 3;
	}
	for(int i=0;i<4;i++)
	{
		Map[ship[i]] = 4;
	}
}

//画地图
void DrawMap()
{
	system("clear");
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
	for(int i=65;i<70;i++)
	{
		DrawMapWay(i);
		cout<<endl;
	}
	for(int i=70;i<100;i++)
	{
		DrawMapWay(i);
	}
	cout<<endl;
}
//画图方法
static void DrawMapWay(int i)
{
	if(player[0].getPos() == player[1].getPos()&&player[0].getPos()==i)
	{
		cout<<"<>";
	}
	else if(player[0].getPos() == i)
	{
		cout<<"Ａ";
	}
	else if(player[1].getPos() == i)
	{
		cout<<"Ｂ";
	}
	else
	{
		switch(Map[i])
		{
			case 0:
				cout<<"□ ";
				break;
			case 1:
				cout<<"☆ ";
				break;
			case 2:
				cout<<"▲ ";
				break;
			case 3:
				cout<<"○ ";
				break;
			case 4:
				cout<<"※ ";
				break;
		}
	}
}

static int random(int start,int end)
{
	srand((unsigned)time(NULL));
	return rand()%(end-start)+start;
}



void play(int num,int count)
{
	cout<<"玩家"<<player[num].getName()<<"正在行动。。。。。。"<<endl;
	cin.get();
	cout<<player[num].getName()<<"摇出了"<<count<<endl;
	cin.get();
	player[num].move(count);
	if(player[num].getPos() == player[1-num].getPos())
	{
		cout<<"玩家"<<player[num].getName()<<"踩到了"<<player[1-num].getName()<<",并且扔下了香蕉皮，导致"<<player[1-num].getName()<<"摔退1格"<<endl;
		player[1-num].move(-1);
	}
	cin.get();
	switch(Map[player[num].getPos()])
	{
		case 0:
			cout<<player[num].getName()<<"踩到了方块，嘛事没有，吃嘛嘛香";
			break;
		case 1:
			cout<<"我擦，炸弹，。。。。被炸飞6格";
			if(rand()%2)
				player[num].move(6);
			else
				player[num].move(-6);
			break;
		case 2:
			cout<<"被金莲姐棍子砸到头，暂停一回合";
			player[num].setSattle(true);
			break;
		case 3:
			cout<<"偶遇小叮当，测马奔腾吧骚年：前进10格";
			player[num].move(10);
			break;
		case 4:
			cout<<"幸运大转盘，转转转。。。。"<<endl;
			if(rand()%2)
			{
				cout<<"快到碗里来，你丫才到碗里去:交换位置"<<endl;
				int tmp = player[num].getPos();
				player[num].setPos(player[1-num].getPos());
				player[1-num].setPos(tmp);
			}
			else
			{
				cout<<"拉登现世，见谁炸谁,轰炸对方使其随机倒退0~10格"<<endl;
				int tmp = rand()%11;
				cout<<"成功将对手炸退了"<<tmp<<"格.";
				if(tmp == 0)
					cout<<endl<<"哼~~~你个阳痿。";
				cout<<endl;
			}
	}
	cin.get();
	DrawMap();
}
