#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x=0,y=0;
	int dx=1,dy=0;
	int k=1;
	int rk = 289326;
	
	for (int l=1;;++l)
	{
		for (int i=0;i<l;++i)
		{
			x += dx;
			y += dy;
			++k;
			if (k == rk)
			{
				cout << abs(x) + abs(y) << endl;
				return 0;
			}
		}
		
			 if (dx == 1           ) dx = 0,  dy = 1;
		else if (dx == 0 && dy == 1) dx = -1, dy = 0;
		else if (dx == 0 && dy ==-1) dx = 1,  dy = 0;
		else if (dx ==-1           ) dx = 0,  dy =-1;
		
		for (int i=0;i<l;++i)
		{
			x += dx;
			y += dy;
			++k;
			if (k == rk)
			{
				cout << abs(x) + abs(y) << endl;
				return 0;
			}
		}
		
			 if (dx == 1           ) dx = 0,  dy = 1;
		else if (dx == 0 && dy == 1) dx = -1, dy = 0;
		else if (dx == 0 && dy ==-1) dx = 1,  dy = 0;
		else if (dx ==-1           ) dx = 0,  dy =-1;
	}
}