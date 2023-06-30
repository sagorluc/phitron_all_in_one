#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);

    stringstream ss(s);

    string word;

    map<string,int> m;

    int maxx = 0;

    while(ss >> word)
    {
        m[word]++;
    }

    string max_word;

    for(auto i=m.begin(); i != m.end(); i++)
    {
        if(i->second > maxx || (i->second == maxx && i->first < max_word))
        {
            maxx = i->second;
            max_word = i->first;
        }


    }
        cout<<"Maximum occurring word is '"<<max_word<<"',"<<" Occurring "<<maxx<<" times";

//    cout<<s;


    return 0;
}
