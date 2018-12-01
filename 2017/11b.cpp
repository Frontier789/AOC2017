#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <map>
#include <set>

using namespace std;

class P;

map<string,P> irToP;

class P
{
public:
	int x,y,z;
	
	P(int x=0,int y=0,int z=0) : x(x), y(y), z(z) {}
	
	P operator+(const P &p) const {return P(x+p.x,y+p.y,z+p.z);}
	
	int len() const {return abs(x) + abs(y) + abs(z);}
	
	int act_len()
	{
		P ops[] = {irToP["s"] + irToP["ne"] + irToP["nw"],
				   irToP["n"] + irToP["sw"] + irToP["se"]};
	
		bool better = true;
		while (better)
		{
			better = false;
			
			for (P d : ops)
			{
				P p2 = (*this) + d;
				
				if (p2.len() < len())
				{
					*this = p2;
					better = true;
				}
			}
		}
		
		return len();
	}
};



int main()
{
	
	irToP["s" ] = P(0,0,-1);
	irToP["se"] = P(1,0,0);
	irToP["ne"] = P(0,1,0);
	irToP["n" ] = P(0,0,1);
	irToP["nw"] = P(-1,0,0);
	irToP["sw"] = P(0,-1,0);
	
	
	
	ifstream in("11a.in");
	
	P p;
	string s;
	
	int mx = 0;
	
	while (in >> s)
	{
		p = p + irToP[s];
		mx = max(mx,p.act_len());
	}
	
	cout << mx << endl;
}
