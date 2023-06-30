#include<bits/stdc++.h>
using namespace std;
string erase_frist_and_last(string s)
{
    s.erase(s.begin()+2);
    s.pop_back();
    return s;
}

void erase_frist_and_last1(string &s)
{
    s.erase(s.begin());
    s.pop_back();
    cout<<"eraseing function s = "<<s<<endl;

}
int sop(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = a;
    b = temp;

    /*
    a = 5 b = 6

    c = a c = 5

    a = b a = 6
    b = c b = 5
    */
    return 0;

}
int main()
{
//    string n,x;
//    cin>>n>>x;
//    string ans = erase_frist_and_last(n);
//    cout<<n<<endl;
//    cout<<ans<<endl;

//   erase_frist_and_last1(n);
//   cout<<n<<endl;

    int n,x;
    cin>>n>>x;

    sop(n,x);
    cout<<"a = "<<n<<endl<<"b = "<<x<<endl;


    return 0;
}
