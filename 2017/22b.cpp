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
	map<P,int> mp;
	
	int n = sizeof(input) / sizeof(*input);
	
	// cout << n << endl;
	
	for (int i=0;i<n;++i)
	for (int j=0;j<n;++j)
	{
		if (input[i][j] == '#')
		{
			mp[P(i-n/2,j-n/2)] = 2;
		}
	}
	
	P p,v(-1,0);
	
	int db = 0;
	for (int i=0;i<10000000;++i)
	{
		if (mp[p] == 2) v.l();
		if (mp[p] == 0) v.r();
		// if (mp[p] == 1) v = v;
		if (mp[p] == 3) v = P(-v.x,-v.y);
		
		mp[p] = (mp[p]+1)%4;
		
		if (mp[p] == 2) ++db;
		
		p = p+v;
	}
	cout << db << endl;
}
