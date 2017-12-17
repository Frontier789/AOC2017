#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <map>
#include <set>

using namespace std;

class P
{
public:
	int x,y,z;
	
	P(int x=0,int y=0,int z=0) : x(x), y(y), z(z) {}
	
	P operator+(const P &p) const {return P(x+p.x,y+p.y,z+p.z);}
	
	int len() const {return abs(x) + abs(y) + abs(z);}
};



int main()
{
	map<string,P> irToP;
	
	irToP["s" ] = P(0,0,-1);
	irToP["se"] = P(1,0,0);
	irToP["ne"] = P(0,1,0);
	irToP["n" ] = P(0,0,1);
	irToP["nw"] = P(-1,0,0);
	irToP["sw"] = P(0,-1,0);
	
	P ops[] = {irToP["s"] + irToP["ne"] + irToP["nw"],
			   irToP["n"] + irToP["sw"] + irToP["se"]};
	
	ifstream in("11a.in");
	
	P p;
	string s;
	
	while (in >> s) p = p + irToP[s];
	
	bool better = true;
	while (better)
	{
		better = false;
		
		for (P d : ops)
		{
			P p2 = p + d;
			
			if (p2.len() < p.len())
			{
				p = p2;
				better = true;
			}
		}
	}
	
	cout << p.x << " " << p.y << " " << p.z << endl;
	cout << p.len() << endl;
}
