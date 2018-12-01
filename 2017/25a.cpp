#include <iostream>
#include <deque>

using namespace std;

class Turing
{
public:
	deque<bool> tape;
	int cur;
	char state;
    int num1;
	
	Turing() : tape(1,0), cur(0), state('A'), num1(0) {}
	
	void step()
	{
        bool prevtapec = tape[cur];
        bool &tapec = tape[cur];
        bool R;

		switch (state)
        {
            case 'A':
                if (!tapec) tapec = true,  R = 1, state = 'B';
                else        tapec = false, R = 0, state = 'B';
                break;
            case 'B':
                if (!tapec) tapec = false, R = 1, state = 'C';
                else        tapec = true,  R = 0, state = 'B';
                break;
            case 'C':
                if (!tapec) tapec = true,  R = 1, state = 'D';
                else        tapec = false, R = 0, state = 'A';
                break;
            case 'D':
                if (!tapec) tapec = true,  R = 0, state = 'E';
                else        tapec = true,  R = 0, state = 'F';
                break;
            case 'E':
                if (!tapec) tapec = true,  R = 0, state = 'A';
                else        tapec = false, R = 0, state = 'D';
                break;
            case 'F':
                if (!tapec) tapec = true,  R = 1, state = 'A';
                else        tapec = true,  R = 0, state = 'E';
                break;
            default: cout << "wtf" << endl; break;
        }

        if (R) cur += 1;
        else cur -= 1;

        if (cur == -1)
        {
            cur = 0;
            tape.push_front(false);
        }
        if (cur == tape.size())
        {
            tape.push_back(false);
        }

        num1 += tapec - prevtapec;
	}
};

int main()
{
    Turing machine;

    for (int n = 0;n < 12629077;++n)
    {
        if (n % 163 == 0 && false)
        {
            cout << n << ". " << machine.num1 << " _ " << machine.state << ": ";
            for (int i = 0;i < machine.tape.size();++i)
            {
                if (i == machine.cur) cout << "[" << machine.tape[i] << "] ";
                else cout << machine.tape[i] << " ";
            }
            cout << endl;
        }
        machine.step();
    }

    cout << machine.num1 << endl;
}