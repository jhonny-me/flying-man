#include "playway.h"
//#include "playway.cpp"

int main(int argc ,char *argv[])
{
	if(argc!=2)
	{
		cout<<"Please input your name to play"<<endl;
		string name;
		cin>>name;
		player1.setName(name);
	}
	else
	{
		string name(argv[1]);
		player1.setName(name);
	}
	::InitialMap();
	::DrawMap();
}








