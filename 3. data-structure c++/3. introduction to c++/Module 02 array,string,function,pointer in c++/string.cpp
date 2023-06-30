//#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
//    string s = "hei! how are you.";
//    string s1 = "i am fine! and you.";
//
//    string s3 = s + s1;//concatinat string.
//    s.pop_back();//it will delate last word if string.
//    cout<<s<<endl;
//    s.erase(s.begin()+3);//it will delete the word whatever i want.
//    cout<<s<<"\n";
    string n = "how are you";
    //n.erase(n.begin()+ n.size()-1);
    n.pop_back();
    n.erase(n.begin()+n.size()-4);
    cout<<n<<endl;

//    cout<<s3<<endl;
//    cout<<s3.size()<<endl;//function to find how many character have in string.
//
//    int i;
//    for(i=0; i<s3.size(); i++)
//    {
//        s[i] = s[i]+1;
//        cout<<s[i];
//    }


//    cout<<s[0]<<endl;
//    cout<<s[1]<<endl;
//    cout<<s[2]<<endl;
//    cout<<s[3]<<endl;
//    cout<<s[4]<<endl;
//    cout<<s[5]<<endl;

    return 0;
}
