#include<bits/stdc++.h>
using namespace std;

// stack using statick array

const int MAX_SIZE = 500;

class STACK{

public:

    int a[MAX_SIZE];
    int stack_size;

    // constructor
    STACK()
    {
        stack_size = 0;
    }

    // add elements in the stack. time complexity- O(1)

    void PUSH(int value)
    {
        // corner case
        if(stack_size+1 > MAX_SIZE) // stack_size MAX_SIZE er besi hole error dekhabe.
        {
            cout<< "stack is full.\n";
            return;

        }

        stack_size = stack_size + 1; // value push korar somoy stack_size 1 barate hobe;

        a[stack_size - 1] = value; // last index value dhorte hole stack_size -1 korte hobe.
    }

    // delete the top most element from the stack. o(1)
    void POP()
    {
        // corner case
        if(stack_size == 0) // stack empty or kono value na thakle msg debe.
        {
            cout<< "stack is empty.\n";
            return;
        }

        a[stack_size - 1] = 0; // last element delete houyer por seta 0 diye fill hoye jabe.kono gurbage value thakbe nah.
        stack_size = stack_size - 1; // stack_size-1 korlei last element delete hoye jabe.
    }


    // returns the top element from the stack
    int TOP()
    {
        // corner case
        if(stack_size == 0)
        {
            cout<< "stack is empty.\n";
            return -1;
        }
        return a[stack_size -1];
    }


};
int main()
{
    STACK stk;

    stk.PUSH(3);
    cout<<stk.TOP()<<" ";
    stk.PUSH(4);
    cout<<stk.TOP()<<" ";
    stk.PUSH(5);
    cout<<stk.TOP()<<"\n";

    stk.POP();
    cout<<stk.TOP()<<"\n";
    stk.POP();
    cout<<stk.TOP()<<"\n";
    stk.POP();
    cout<<stk.TOP()<<"\n";




    return 0;
}
