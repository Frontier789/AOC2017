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

vector<vector<int>> pack(const vector<vector<bool>> &mp,int n)
{
	vector<vector<int>> ret(mp.size()/n,vector<int>(mp[0].size()/n,0));
	
	for (int i=0;i<mp.size();++i)
	{
		for (int j=0;j<mp[i].size();++j)
		{
			ret[i/n][j/n] = ret[i/n][j/n]*2 + mp[i][j];
		}
	}
	
	return ret;
}

vector<vector<bool>> unpack(const vector<vector<int>> &mp,int n)
{
	vector<vector<bool>> ret(mp.size()*n,vector<bool>(mp[0].size()*n,false));
	
	for (int i=0;i<ret.size();++i)
	{
		for (int j=0;j<ret[i].size();++j)
		{
			int offset = (n - 1 - i%n)*n + (n - 1 - j%n);
			
			ret[i][j] = mp[i/n][j/n] & (0x1 << offset);
		}
	}
	
	return ret;
}

void rot(vector<vector<bool>> &d)
{
	vector<vector<bool>> tmp = d;
	
	for (int i=0;i<d.size();++i)
	{
		for (int j=0;j<d[i].size();++j)
		{
			tmp[i][j] = d[j][d.size() - 1 - i];
		}
	}
	
	d = tmp;
}

void mir(vector<vector<bool>> &d)
{
	vector<vector<bool>> tmp = d;
	
	for (int i=0;i<d.size();++i)
	{
		for (int j=0;j<d[i].size();++j)
		{
			tmp[i][j] = d[j][i];
		}
	}
	
	d = tmp;
}

vector<int> readRule(ifstream &in,int &n,bool doall)
{
	string s;
	in>>s;
	n = s.size();
	
	vector<vector<bool>> arr(n,vector<bool>(n,false));
	
	for (int i=0;i<n;++i)
	{
		if (i) in >> s;
		
		for (int j=0;j<s.size();++j)
		{
			arr[i][j] = s[j] == '#';
		}
	}
	
	vector<int> ret;
	
	auto 
	
	packed = pack(arr,n);
	ret.push_back(packed[0][0]);
	
	if (doall)
	{
		for (int db = 0;db < 3;++db)
		{
			rot(arr);
			packed = pack(arr,n);
			ret.push_back(packed[0][0]);
		}
		
		rot(arr);
		mir(arr);
		
		packed = pack(arr,n);
		ret.push_back(packed[0][0]);
		
		for (int db = 0;db < 3;++db)
		{
			rot(arr);
			packed = pack(arr,n);
			ret.push_back(packed[0][0]);
		}
	}
	
	return ret;
}

int main()
{
	ifstream in("21a.in");
	
	map<int,int> rules2;
	map<int,int> rules3;
	
	while (!in.eof())
	{
		int n;
		auto ws = readRule(in,n,true);
		
		auto &ins = (n == 2  ? rules2 : rules3);
		
		int f = readRule(in,n,false)[0];
		
		for (int a : ws) ins[a] = f;
/*
		for (int a : ws)
		{
			vector<vector<int>> d(1,vector<int>(1,a));

			auto unpacked = unpack(d,n);
			
			for (auto &i : unpacked)
			{
				for (auto j : i)
				{
					cout << j;
				}
				cout << endl;
			}
			cout << endl;
		}*/
	}
	
	vector<vector<bool>> state(3,vector<bool>(3,false));
	
	state[0][1] = true;
	state[1][2] = true;
	state[2][2] = true;
	state[2][1] = true;
	state[2][0] = true;
	
	for (int k = 0;k<18;++k)
	{
		int froms = 2;
		if (state.size() % 2 != 0) froms = 3;
		
		auto packed = pack(state,froms);
		auto &ins = (froms == 2  ? rules2 : rules3);
		
		for (auto &i : packed) for (auto &j : i) j = ins[j];
		
		state = unpack(packed,froms+1);
		
		/*
		for (auto &i : state)
		{
			for (auto j : i)
			{
				out << (j ? "#" : ".");
				
				if (j) ++s;
			}
			out << endl;
		}
		out << endl;
		*/
	}
	int s = 0;
	
	for (auto &i : state) for (auto j : i) if (j) ++s;
	
	cout << s << endl;
}
