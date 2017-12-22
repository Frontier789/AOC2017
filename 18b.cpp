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

bool hasArg2(string cmd)
{
	return cmd == "set" || cmd == "add" || 
		   cmd == "mul" || cmd == "mod" || 
		   cmd == "jgz" || cmd == "mul";
}
/*
snd X plays a sound with a frequency equal to the value of X.
set X Y sets register X to the value of Y.
add X Y increases register X by the value of Y.
mul X Y sets register X to the result of multiplying the value contained in register X by the value of Y.
mod X Y sets register X to the remainder of dividing the value contained in register X by the value of Y (that is, it sets X to the result of X modulo Y).
rcv X recovers the frequency of the last sound played, but only when the value of X is not zero. (If it is zero, the command does nothing.)
jgz X Y jumps with an offset of the value of Y, but only if the value of X is greater than zero. (An offset of 2 skips the next instruction, an offset of -1 jumps to the previous instruction, and so on.)
*/
class Program
{
public:
	map<char,int64_t> registers;
	int64_t sound;
	int head;
	queue<int64_t> inQueue;
	queue<int64_t> *outQueue;
	
	int id;
	int snd;
	
	Program(int id) : sound(0), head(0), snd(0), id(id) {registers['p'] = id;}
	
	int64_t dispatch(string arg)
	{
		int64_t a;
		
		if ((arg[0] >= '0' && arg[0] <= '9') || arg[0] == '-') return stringstream(arg)>>a,a;
		
		return registers[arg[0]];
	}
	
	void exec(string cmd,char arg1,string arg2)
	{/*
		cout << head << "_ " << cmd << " " << arg1 << " " << arg2;
		if (hasArg2(cmd)) cout << " " << dispatch(arg2);
		cout << endl;
		*/
		cout << id << " " << head << "  : ";
		for (auto it : registers) cout << it.first << "=" << it.second << " ";
		cout << endl;
		
		if (cmd == "snd") ++head, outQueue->push(registers[arg1]), ++snd;
		if (cmd == "set") ++head, registers[arg1] = dispatch(arg2);
		if (cmd == "add") ++head, registers[arg1] += dispatch(arg2);
		if (cmd == "mul") ++head, registers[arg1] *= dispatch(arg2);
		if (cmd == "mod")
		{
			++head;
			registers[arg1] %= dispatch(arg2);
		}
		if (cmd == "jgz") if (registers[arg1] > 0) head += dispatch(arg2); else ++head;
		if (cmd == "rcv") 
		{
			if (inQueue.empty()) return;
			
			++head;
			registers[arg1] = inQueue.front();
			inQueue.pop();
		}
	}
};

class ASD
{
public:
	int64_t it;
	int64_t a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p;
	ASD(int p) : it(1), a(0), b(0), c(0), d(0), e(0), f(0), g(0), h(0), i(0), j(0), k(0), l(0), m(0), n(0), o(0), p(p), snd(0) {}
	queue<int64_t> sorM;
	queue<int64_t> *sorO;
	int snd;
	
	void step()
	{
		if (it == 1) {
			i = 31; ++it;
		}
		if (it == 2) {
			a = 1; ++it;
		}
		if (it == 3) {
			p *= 17; ++it;
		}
		if (it == 4) {
			if (p > 0) {it += p;} else ++it;
		}
		if (it == 5) {
			a *= 2; ++it;
		}
		if (it == 6) {
			i += -1; ++it;
		}
		if (it == 7) {
			if (i > 0) {it += -2;} else ++it;
		}
		if (it == 8) {
			a += -1; ++it;
		}
		if (it == 9) {
			i = 127; ++it;
		}
		if (it == 10) {
			p = 735; ++it;
		}
		if (it == 11) {
			p *= 8505; ++it;
		}
		if (it == 12) {
			p %= a; ++it;
		}
		if (it == 13) {
			p *= 129749; ++it;
		}
		if (it == 14) {
			p += 12345; ++it;
		}
		if (it == 15) {
			p %= a; ++it;
		}
		if (it == 16) {
			b = p; ++it;
		}
		if (it == 17) {
			b %= 10000; ++it;
		}
		if (it == 18) {
			sorO->push(b); ++it; ++snd;
		}
		if (it == 19) {
			i += -1; ++it;
		}
		if (it == 20) {
			if (i > 0) {it += -9;} else ++it;
		}
		if (it == 21) {
			if (a > 0) {it += 3;} else ++it;
		}
		if (it == 22) {
			if (!sorM.empty()) { b = sorM.front(); sorM.pop(); ++it; }
		}
		if (it == 23) {
			if (b > 0) {it += -1;} else ++it;
		}
		if (it == 24) {
			f = 0; ++it;
		}
		if (it == 25) {
			i = 126; ++it;
		}
		if (it == 26) {
			if (!sorM.empty()) { a = sorM.front(); sorM.pop(); ++it; }
		}
		if (it == 27) {
			if (!sorM.empty()) { b = sorM.front(); sorM.pop(); ++it; }
		}
		if (it == 28) {
			p = a; ++it;
		}
		if (it == 29) {
			p *= -1; ++it;
		}
		if (it == 30) {
			p += b; ++it;
		}
		if (it == 31) {
			if (p > 0) {it += 4;} else ++it;
		}
		if (it == 32) {
			sorO->push(a); ++it; ++snd;
		}
		if (it == 33) {
			a = b; ++it;
		}
		if (it == 34) {
			if (1 > 0) {it += 3;} else ++it;
		}
		if (it == 35) {
			sorO->push(b); ++it; ++snd;
		}
		if (it == 36) {
			f = 1; ++it;
		}
		if (it == 37) {
			i += -1; ++it;
		}
		if (it == 38) {
			if (i > 0) {it += -11;} else ++it;
		}
		if (it == 39) {
			sorO->push(a); ++it; ++snd;
		}
		if (it == 40) {
			if (f > 0) {it += -16;} else ++it;
		}
		if (it == 41) {
			if (a > 0) {it += -19;} else ++it;
		}
		if (it >= 42 || it < 1)
		{
			exit(0);
		}
	}
};
// 125: low
int main()
{
	ASD a0(0),a1(1);
	a0.sorO = &a1.sorM;
	a1.sorO = &a0.sorM;
	
	for (int k=0;k<1245789;++k)
	{
		a0.step();
		a1.step();
		
	}
	cout << a1.snd << endl;
	return 0;
	
	ifstream in("18a.in");
	
	vector<tuple<string,char,string>> cmds;
	
	string cmd,y;
	char x;
	
	for (int line = 1;in >> cmd >> x;++line)
	{
		if (hasArg2(cmd))
		{
			getline(in,y);
			if (!y.size()) break;
			y = y.substr(1);
		}
		else y = "";
		
		cmds.push_back(tuple<string,char,string>(cmd,x,y));
		/*
		cout << "if (it == " << line << ") {" << endl << "\t";
		
		if (cmd == "set") cout << x << " = " << y << "; ++it;" << endl;
		if (cmd == "add") cout << x << " += " << y << "; ++it;" << endl;
		if (cmd == "mul") cout << x << " *= " << y << "; ++it;" << endl;
		if (cmd == "mod") cout << x << " %= " << y << "; ++it;" << endl;
		if (cmd == "rcv") cout << "if (!sorM.empty()) { " << x << " = sorM.front(); sorM.pop(); ++it; }" << endl;
		if (cmd == "jgz") cout << "if (" << x << " > 0) {" << "it += " << y << "} else ++it;" << endl;
		if (cmd == "snd") cout << "sorO.push(" << x << "); ++it;" << endl;
		
		
		cout << "}" << endl;*/
	}
	
	Program p0(0),p1(1);
	p0.outQueue = &p1.inQueue;
	p1.outQueue = &p0.inQueue;
	
	for (int l=0;true;++l)
	{
		tuple<string,char,string> t = cmds[p0.head];
		p0.exec(get<0>(t),get<1>(t),get<2>(t));
		
		t = cmds[p1.head];
		p1.exec(get<0>(t),get<1>(t),get<2>(t));
		
		if (p0.head < 0 || p0.head >= cmds.size() ||
			p1.head < 0 || p1.head >= cmds.size()) break;
	}
	
	cout << p1.snd << endl;
}

