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
typedef pair<int64_t,int64_t> R;

R recFind(R s = R(0,0),int l = 0)
{
    R mx = s;

    for (auto &rail : rails)
    {
        if (!rail.used && rail.a == l)
        {
            rail.used = true;
            R r = recFind(R(s.first + rail.a + rail.b,s.second+1),rail.b);
            rail.used = false;

            if (r.second > mx.second || (r.second == mx.second && r.first > mx.first)) mx = r;
        }
        if (!rail.used && rail.b == l)
        {
            rail.used = true;
            R r = recFind(R(s.first + rail.a + rail.b,s.second+1),rail.a);
            rail.used = false;

            if (r.second > mx.second || (r.second == mx.second && r.first > mx.first)) mx = r;
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

    cout << recFind().first << endl;
}