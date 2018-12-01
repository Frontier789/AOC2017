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
	int64_t m_c;
public:
	Gen(int64_t st,int64_t mul,int64_t dv,int64_t c) : m_prev(st), m_mul(mul), m_dv(dv), m_c(c) {}
	
	int64_t nxt()
	{
		do
		{
			m_prev = (m_prev * m_mul) % m_dv;
		}
		while (m_prev % m_c != 0);
		
		return m_prev;
	}
};

int main()
{
	Gen A(699,16807,2147483647,4);
	Gen B(124,48271,2147483647,8);
	
	int64_t mask = ((1 << 16) - 1);
	
	int db = 0;
	for (int i=0;i<5000000;++i)
	{
		int64_t Ap = A.nxt(), Bp = B.nxt();
		
		if ((Ap & mask) == (Bp & mask))
		{
			++db;
		}
	}
	
	cout << db << endl;
}

