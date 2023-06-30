#include<bits/stdc++.h>
using namespace std;

/*
insertion array.
time complexity -
memory complexity - o(n)

v.inseart(v.begin(),v.begin()+i)

*/

class arra{
private:

    int *arr;
    int cap;
    int sz;
    void Increase_size()
    {
        cap = cap*2;
        int *tmp = new int[cap]; //capacity update korar jonno new variable noya holo.
        for(int i=0; i<sz; i++)
        {
            tmp[i] = arr[i]; //arr[] theke sob kicu tmp[] copy kora holo.
        }
        delete [] arr; //old arr[] theke je memory use kora hoyecilo seta delete kore deoya holo.
        arr = tmp; //arr ke tmp te point kore dilam

    }
public:
    arra()
    {
        arr = new int[1];
        cap = 1;
        sz = 0;
    }

    //time complexity-o(1)
    void Push_back(int x)
    {
        if(cap==sz)
        {
            Increase_size();
        }
        arr[sz] = x;
        sz++;

    }

    //time complexity o(size-posi) o(sz)
    void Insert(int posi, int x)
    {
        if(cap==sz)
            Increase_size();

        for(int i=sz-1; i>=posi; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[posi]= x;
        sz++;

    }

    //time complexity- o(n)
    void print()
    {
        for(int i=0; i<sz; i++)
        {
            cout<<arr[i]<<" ";

        }
        cout<<"\n";
    }


    //time complexity-o(1)
    int getSize()
    {
        return sz;
    }

    //time complexity- o(1)
    int getElement(int index)
    {
        if(index>=sz)
        {
            cout<<"Error "<<index<<"is out of bound!\n";
            return -1;
        }
        else
         return arr[index];

    }

    //time complexity- O(1)
    void Pop_back()
    {
        if(sz==0)
        {
            cout<<"current size is zero!";
            return;
        }
        else
            sz--;
    }

    //time complexity- O(sz)
    void Erase(int pos)
    {
        if(pos>=sz)
        {
            cout<<"position does not exist.\n";
        }
        for(int i=pos+1; i<sz; i++)
        {
            arr[i-1] = arr[i];
            //swap(arr[i-1],arr[i]);
        }
        sz--;

    }

};

int main()
{
    arra a; //class ke coll kora holo.

    a.Push_back(10);
    a.Push_back(20);
    a.Push_back(30);
    a.Push_back(40);
    a.Push_back(50);
    a.Insert(1,5);

    a.print();

    a.Pop_back();
    a.print();

    a.Pop_back();
    a.print();

    a.Pop_back();
    a.print();

    a.Erase(1);
    a.print();

//    cout<<a.getSize()<<"\n";
//
//    for(int i=0; i<a.getSize(); i++)
//    {
//        cout<<a.getElement(i)<<"\n";
//    }




    return 0;
}
