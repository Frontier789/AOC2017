#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Rail
{
public:
    int a,b;
    bool used;

    Rail() : a(0), b(0), used(false) {}
};

vector<Rail> rails;

int64_t recFind(int64_t s = 0,int l = 0)
{
    int64_t mx = s;

    for (auto &rail : rails)
    {
        if (!rail.used && rail.a == l)
        {
            rail.used = true;
            mx = max(mx,recFind(s + rail.a + rail.b,rail.b));
            rail.used = false;
        }
        if (!rail.used && rail.b == l)
        {
            rail.used = true;
            mx = max(mx,recFind(s + rail.b + rail.a,rail.a));
            rail.used = false;
        }
    }

    return mx;
}

// 1401 - 4000

int main()
{
    ifstream in("24a.in");

    int a,b;
    while (in >> a >> b)
    {
        Rail r;
        r.a = a;
        r.b = b;
        rails.push_back(r);
    }

    cout << recFind() << endl;
}