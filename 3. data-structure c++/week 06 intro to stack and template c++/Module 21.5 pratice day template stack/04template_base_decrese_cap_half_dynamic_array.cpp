#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Dynanic_array_stack{

public:

    T *a;
    int stack_size;
    int arr_capacity;

    //constructor
    Dynanic_array_stack()
    {
        a = new T[1];
        arr_capacity = 1;
        stack_size = 0;

    }

    // increase array capacity.
    void decrease_capacity()
    {
        if (stack_size < arr_capacity / 2)
        {
            arr_capacity /= 2;

        }
    }

    // push element in stack.
    void PUSH(T value)
    {
        // corner case
        if(stack_size + 1 > arr_capacity)
        {
            decrease_capacity();
        }
        stack_size = stack_size + 1;
        a[stack_size - 1] = value;

    }

    // remove element at top in stack.
    void POP()
    {
        // corner case
        if(stack_size < arr_capacity)
            decrease_capacity();

        if(stack_size == 0)
        {
            cout<<"stack is empty.\n";
            return;
        }
        a[stack_size - 1] = 0;
        stack_size = stack_size - 1;
    }

    // print at the top most element at stack.
    T TOP()
    {
        // corner case
        if(stack_size < arr_capacity)
            decrease_capacity();

        if(stack_size == 0)
        {
            cout<<"nothing got in stack";
            T a;
            return a;
        }
        return a[stack_size - 1];
    }



};
int main()
{
    Dynanic_array_stack<float> das;

    das.PUSH(5.1);
    das.PUSH(4.2);
    das.PUSH(3.9);
    das.PUSH(2.4);


    Dynanic_array_stack<char> dcs;

    dcs.PUSH('f');
    dcs.PUSH('e');
    dcs.PUSH('d');
    dcs.PUSH('c');
    dcs.PUSH('b');
    dcs.PUSH('a');

    while(das.stack_size != 0)
    {
        cout<<"\n"<<das.TOP()<<" ";
        das.POP();
        cout<<dcs.TOP()<<" ";
        dcs.POP();
    }


    return 0;
}

