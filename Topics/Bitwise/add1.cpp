#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    //  x = num ^ (1 << (i-1));  flip  the ith bit of number
        int x;
        cin>>x;
        int m = 1;
        int i = 0;
        while((x&(m<<i))){
            i++;
        }
        x = x^(1>>i+1);
        cout<<i<<" "<<x<<endl;

    
}