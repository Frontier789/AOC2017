#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

extern stringstream ss;

int main()
{
	int p,len;
	
	int sev = 0;
	
	while (ss >> p >> len)
	{
		int fp = p;
		
		if (len == 1) p = 0;
		else p = p % (len + len - 2);
		
		if (p > len) p = 2*len - p;
		
		// cout << p << " " << len << endl;
		
		if (p == 0) sev += fp * len;
	}
	
	cout << sev << endl;
}
/*
0 1 2 3   4 5 6 7   8 9 A B   C D E F
0 1 2 1   0 1 2 1   0 1 2 1   0 1 2 1

0 1 2 3 4 5
0 1 2 3 2 1
*/
stringstream ss(R"(0 3
1 2
2 4
4 4
6 5
8 8
10 6
12 6
14 6
16 6
18 8
20 8
22 12
24 10
26 9
28 8
30 8
32 12
34 12
36 12
38 12
40 8
42 12
44 14
46 14
48 10
50 12
52 12
54 14
56 14
58 14
62 12
64 14
66 14
68 14
70 12
74 14
76 14
78 14
80 18
82 17
84 30
88 14)");
