#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Parent{
    public:
    Parent(){
        cout<<"Parent"<<endl;
     }

};

class Parent2{
    public:
    Parent2(){
        cout<<"Parent2"<<endl;
     }

};
class Child: public Parent2, public Parent{
    int age = 0;
    public :  
        Child(){
                cout<<"Child"<<endl;
        }
};
int main(){
    Child c = Child();
    return 0;
}