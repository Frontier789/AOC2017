#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

class Gen
{
	int64_t m_prev;
	int64_t m_mul;
	int64_t m_dv;
public:
	Gen(int64_t st,int64_t mul,int64_t dv) : m_prev(st), m_mul(mul), m_dv(dv) {}
	
	int64_t nxt()
	{
		m_prev = (m_prev * m_mul) % m_dv;
		
		return m_prev;
	}
};

int main()
{
	Gen A(699,16807,2147483647);
	Gen B(124,48271,2147483647);
	
	int64_t mask = ((1 << 16) - 1);
	
	int db = 0;
	for (int i=0;i<40000000;++i)
	{
		int64_t Ap = A.nxt(), Bp = B.nxt();
		
		if ((Ap & mask) == (Bp & mask))
		{
			++db;
		}
	}
	
	cout << db << endl;
}

