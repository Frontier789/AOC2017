#include <iostream>

using namespace std;

class Program
{
public:
    int64_t a,b,c,d,e,f,g,h;
    int it,m;

    Program() : a(0), b(0), c(0), d(0), e(0), f(0), g(0), h(0), it(0), m(0) {}

    void do_set(int64_t &to,int64_t v) {++it; to = v;}
    void do_sub(int64_t &to,int64_t v) {++it; to -= v;}
    void do_mul(int64_t &to,int64_t v) {++it; to *= v; ++m;}
    void do_jnz(int64_t x,int64_t y) {if (x) it += y; else ++it;}
    bool step()
    {
        if (it < 0 || it > 31) return false;
/*
b = 99;
c = b;
b *= 100;
b += 100000;
c = b;
c += 17000;
*/










        const int K = 17;




        if (it == 0)  do_set(b,34);
        if (it == 1)  do_set(c,51); // 99
        if (it == 2)  do_jnz(a,2);
        if (it == 3)  do_jnz(1,5);
        if (it == 4)  do_mul(b,100);
        if (it == 5)  do_sub(b,-100000);
        if (it == 6)  do_set(c,b);
        if (it == 7)  do_sub(c,-17000);
        if (it == 8)  do_set(f,1);
        if (it == 9)  do_set(d,2);
        if (it == 10) do_set(e,2);
        if (it == 11) do_set(g,d);
        if (it == 12) do_mul(g,e);
        if (it == 13) do_sub(g,b);
        if (it == 14) do_jnz(g,2);
        if (it == 15) do_set(f,0);
        if (it == 16) do_sub(e,-1);
        if (it == 17) do_set(g,e);
        if (it == 18) do_sub(g,b);
        if (it == 19) do_jnz(g,-8);
        if (it == 20) do_sub(d,-1);
        if (it == 21) do_set(g,d);
        if (it == 22) do_sub(g,b);
        if (it == 23) do_jnz(g,-13);
        if (it == 24) do_jnz(f,2);
        if (it == 25) do_sub(h,-1);
        if (it == 26) do_set(g,b);
        if (it == 27) do_sub(g,c);
        if (it == 28) do_jnz(g,2);
        if (it == 29) do_jnz(1,3);
        if (it == 30) do_sub(b,-K);
        if (it == 31) do_jnz(1,-23);

        /*
        if (g < -2) g = -2;
        if (e < b-2) e = b-2;
        if (d < b-2) d = b-2;
        */
        /*
        static bool volt = false;
        if (!volt) {
            a = 1; b = 109900; c = 126900; d = 109899; e = 109897; f = 1; g = -3; h = 0;
            volt = true;
        }
        */
        cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << endl;

        return true;
    }
};

#include <cmath>

inline bool isPrime(int64_t p)
{
	if (p<=1) return false;
	
	int64_t sqrtp = std::sqrt(p)+1;
	for (int64_t i=2;i<sqrtp;i++)
		if (i!=p && p%i==0)
			return false;
	
	return true;
}

int main()
{
    int a = 109900, b = 0;
    while (a <= 126900)
    {
        if (!isPrime(a)) ++b;
        a += 17;
    }
    cout << b << endl;
    return 0;
    // cout << (126900 - 109900) / 17 + 1 << endl;
    Program p;

    while (p.step());
    
    cout << p.h << endl;
}