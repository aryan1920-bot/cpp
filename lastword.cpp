#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int longt(string s)
{
    int n=s.length()-1;
    int res=1;
    while(n>0)
    {
        if((s[n]==' '&&s[n-1]!=' ')||s[n]!=' '&&s[n-1]!=' ')
        {
            res++;
            n--;
        }
        if(s[n]!=' '&&s[n-1]==' ')
        {
            return res;
        }

    }
       
}

int main()
{
    string s="enter the text here";
    cout<<longt(s);
}