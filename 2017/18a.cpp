#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

struct Cmd
{
	string str;
	char x;
	int y;
	char y_char;
};

int main()
{
	map<char,int64_t> registers;
	int64_t lastSound = 0;
	
	ifstream in("18a.in");
	
	vector<Cmd> cmds;
	
	string str;
	while (in >> str)
	{
		cmds.push_back(Cmd());
		Cmd &cmd = cmds.back();
		
		cmd.str = str;
		in >> cmd.x;
		cmd.y_char = '\0';
		cmd.y = 0;
		
		string ystr;
		if (str == "set" || str == "add" || str == "mul" || str == "mod" || str == "jgz")
		{
			in >> ystr;
			stringstream ss(ystr);
			
			if (ystr[0] >= 'a' && ystr[0] <= 'z')
			{
				ss >> cmd.y_char;
			}
			else
			{
				ss >> cmd.y;
			}
		}
	}
	/*
	for (int i=0;i<cmds.size();++i)
	{
		cout << cmds[i].str << " " << cmds[i].x << " " << cmds[i].y << " " << cmds[i].y_char << endl;
	}
	*/
	for (int i=0;i<cmds.size();++i)
	{
		string cmd = cmds[i].str;
		char x = cmds[i].x;
		int64_t y = cmds[i].y_char ? registers[cmds[i].y_char] : cmds[i].y;
		
		// cout << cmd << " " << x << "->(" << registers[x] << ")   " << y << endl;
		
		if (cmd == "snd")
		{
			lastSound = registers[x];
		}
		if (cmd == "set")
		{
			registers[x] = y;
		}
		if (cmd == "add")
		{
			registers[x] += y;
		}
		if (cmd == "mul")
		{
			registers[x] *= y;
		}
		if (cmd == "mod")
		{
			registers[x] %= y;
		}
		if (cmd == "rcv")
		{
			if (registers[x])
			{
				cout << lastSound << endl;
				return 0;
				
				registers[x] = lastSound;
			}
		}
		if (cmd == "jgz")
		{
			if (registers[x] > 0)
				i += y-1;
		}
	}
}

