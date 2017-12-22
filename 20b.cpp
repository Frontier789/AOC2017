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

class vec3
{
public:
	int x,y,z;
	
	vec3(int x=0,int y=0,int z=0) : x(x),y(y),z(z) {}
	
	vec3 operator+(const vec3 &v) const {return vec3(x+v.x,y+v.y,z+v.z);}
	
	bool operator==(const vec3 &v) const {return x == v.x && y == v.y && z == v.z;}
};

istream &operator>>(istream &in,vec3 &v)
{
	return in >> v.x >> v.y >> v.z;
}

class Particle
{
public:
	vec3 p,v,a;
	
	void update()
	{
		v = v+a;
		p = p+v;
	}
};

istream &operator>>(istream &in,Particle &p)
{
	return in >> p.p >> p.v >> p.a;
}

int main()
{
	ifstream in("20a.in");
	
	vector<Particle> ps;
	
	for (Particle p;in >> p;ps.push_back(p));
	
	for (int l=0;l<100;++l)
	{
		vector<Particle> np;
		
		for (auto &p : ps)
		{
			int db = -1;
			for (auto &k : ps)
			{
				if (p.p == k.p) ++db;
			}
			
			if (db == 0)
				np.push_back(p);
		}
		
		ps.swap(np);
		
		for (auto &p : ps) p.update();
	}
	
	cout << ps.size() << endl;
}

