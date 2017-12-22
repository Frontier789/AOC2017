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

string input[] = {
".########.....#...##.####",
"....#..#.#.##.###..#.##..",
"##.#.#..#.###.####.##.#..",
"####...#...####...#.##.##",
"..#...###.#####.....##.##",
"..#.##.######.#...###...#",
".#....###..##....##...##.",
"##.##..####.#.######...##",
"#...#..##.....#..#...#..#",
"........#.##..###.#.....#",
"#.#..######.#.###..#...#.",
".#.##.##..##.####.....##.",
".....##..#....#####.#.#..",
"...#.#.#..####.#..###..#.",
"##.#..##..##....#####.#..",
".#.#..##...#.#####....##.",
".####.#.###.####...#####.",
"...#...######..#.##...#.#",
"#..######...#.####.#..#.#",
"...##..##.#.##.#.#.#....#",
"###..###.#..#.....#.##.##",
"..#....##...#..#..##..#..",
".#.###.##.....#.###.#.###",
"####.##...#.#....#..##...",
"#.....#.#..#.##.#..###..#"};

class P
{
public:
	int x,y;
	P(int x=0,int y=0) : x(x), y(y) {}
	
	P operator+(P p) const {return P(x+p.x,y+p.y);}
	
	bool operator<(P p) const {return x < p.x || (x == p.x && y < p.y);}
	
	void l() {swap(x,y); y = -y;}
	void r() {swap(x,y); x = -x;}
};

int main()
{
	map<P,bool> mp;
	
	int n = sizeof(input) / sizeof(*input);
	
	// cout << n << endl;
	
	for (int i=0;i<n;++i)
	for (int j=0;j<n;++j)
	{
		if (input[i][j] == '#')
		{
			mp[P(i-n/2,j-n/2)] = true;
		}
	}
	
	P p,v(-1,0);
	
	P minp(-5,-5),maxp(5,5);
	
	int db = 0;
	for (int i=0;i<10000;++i)
	{
		if (mp[p]) v.l();
		else v.r();
		
		if (!mp[p]) ++db;
		
		mp[p] = !mp[p];
		
		p = p+v;
		
		minp.x = min(minp.x,p.x);
		minp.y = min(minp.y,p.y);
		maxp.x = max(maxp.x,p.x);
		maxp.y = max(maxp.y,p.y);
		/*
		for (int x=minp.x;x<=maxp.x;++x)
		{
			for (int y=minp.y;y<=maxp.y;++y)
			{
				if (x == p.x && y == p.y)
					cout << (mp[P(x,y)] ? "I" : "o");
				else
					cout << mp[P(x,y)];
			}
			cout << endl;
		}
		cout << endl;*/
	}
	cout << db << endl;
}
