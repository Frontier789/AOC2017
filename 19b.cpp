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

class vec2
{
public:
	int x,y;
	
	vec2(int x=0,int y=0) : x(x),y(y) {}
	
	vec2 operator+(const vec2 &v) const {return vec2(x+v.x,y+v.y);}
	
	vec2 perp() const { return vec2(-y,x); }
};

int main()
{
	ifstream in("19a.in");
	
	vector<string> mmap;
	
	string s;
	while (getline(in,s)) mmap.push_back(s);
	
	vec2 p;
	vec2 d(0,1);
	
	for (int x = 0;x<mmap[0].size();++x)
	{
		if (mmap[0][x] == '|') p.x = x;
	}
	
	int db = 0;
	while (mmap[p.y][p.x] != ' ')
	{
		char c = mmap[p.y][p.x]; 
		// cout << "(" << p.x << "," << p.y << ")" << endl; cout << c << endl;
		++db;
		if (c != '+')
		{
			p = p + d;
		}
		else
		{
			vec2 a = d.perp();
			
			if (mmap[p.y+a.y][p.x+a.x] != ' ') d = a;
			else d = vec2(-a.x,-a.y);
			
			p = p + d;
		}
	}
	
	cout << db << endl;
}

