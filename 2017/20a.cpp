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

class Particle
{
public:
	int id;
	int posD;
	int velD;
	int accD;
	
	Particle(int id = 0) : id(id) {}
	
	bool operator<(const Particle &p) const 
	{
		if (accD != p.accD) return accD < p.accD;
		if (velD != p.velD) return velD < p.velD;
		if (posD != p.posD) return posD < p.posD;
		
		return id < p.id;
	}
};

int main()
{
	ifstream in("20a.in");
	
	vector<Particle> ps;
	
	int px,py,pz,vx,vy,vz,ax,ay,az;
	
	for (int id = 0;in >> px >> py >> pz >> vx >> vy >> vz >> ax >> ay >> az;++id)
	{
		ps.push_back(Particle(id));
		
		ps.back().posD = abs(px) + abs(py) + abs(pz);
		ps.back().velD = abs(vx) + abs(vy) + abs(vz);
		ps.back().accD = abs(ax) + abs(ay) + abs(az);
	}
	
	sort(ps.begin(),ps.end());
	
	for (auto p : ps)
	{
		if (p.accD != ps[0].accD) break;
		
		cout << p.id << " " << p.accD << " " << p.velD << " " << p.posD << endl;
	}
}

