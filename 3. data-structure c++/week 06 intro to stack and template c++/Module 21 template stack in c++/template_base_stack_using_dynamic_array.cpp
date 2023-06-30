#include<bits/stdc++.h>
using namespace std;

// template bese stack using dynamic array.

template <class T>
class stack_dynamic_array{

public:
    T *a;
    int stack_size;
    int array_capacity;

    // constructor

    stack_dynamic_array()
    {
        a = new T[1]; // dynamic 1 size er array declare
        array_capacity = 1;   // ei array er total capacity now 1;
        stack_size = 0; // stack size initaily 0;
    }

    // make the array capacity multiplyed by 2;
    void increse_capacity_size()
    {
       T *tmp; // temponary variable declare kore

       tmp = new T[array_capacity*2]; // array capacity double kora holo.and temponare variable e rakha holo.

       for(int i=0; i<array_capacity; i++) // new array_capacity all value teponare variable rakha holo.
            tmp[i] = a[i];

       swap(a,tmp); // and value swaping kora holo.

       delete []tmp; // temponare valriable ke delete kora holo.

       array_capacity = array_capacity*2;

    }

    // add elements in the stack. time complexity- O(1)

    void PUSH(T value)
    {
        // corner case
        if(stack_size + 1 > array_capacity) // stack size jodi array capacityr boro hoy tahole array capacity double hole.
        {
            increse_capacity_size();

        }
        stack_size = stack_size + 1;
        a[stack_size - 1] = value;

    }

    // delete the top most element from the stack. o(1)
    void POP()
    {
        // corner case
        if(stack_size == 0)
        {
            cout<< "stack is empty.\n";
            return;
        }

        //a[stack_size - 1] = 0; // ei code line na holeo chole.
        stack_size = stack_size - 1;
    }

    // returns the top element from the stack
    T TOP()
    {
        // corner case
        if(stack_size == 0)
        {
            cout<< "stack is empty.\n";
            T a;
            return a;
        }

        return a[stack_size - 1];
    }




};
int main()
{
    stack_dynamic_array<double> stk;

    stk.PUSH(3.3);
    stk.PUSH(4.2);
    stk.PUSH(5.5);
    cout<<stk.TOP()<<"\n";

    stk.POP();
    cout<<stk.TOP()<<"\n";

    stk.POP();
    cout<<stk.TOP()<<"\n";

    stk.POP();
    cout<<stk.TOP()<<"\n";

    stack_dynamic_array<char> st;

    st.PUSH('a');
    st.PUSH('b');
    st.PUSH('c');
    cout<<st.TOP()<<"\n";

    st.POP();
    cout<<st.TOP()<<"\n";
    st.POP();
    cout<<st.TOP()<<"\n";
    st.POP();
    cout<<st.TOP()<<"\n";


    return 0;
}

