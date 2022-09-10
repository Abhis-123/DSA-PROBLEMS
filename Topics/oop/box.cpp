#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Box{
    public:
        int breadth, height, length;
        Box(){
            breadth = 0; height = 0; length = 0;
        }
        Box(int l,int b, int h){
            breadth = w;
            height = h;
            length = l;
        }
        Box(Box& other){
            breadth = other.breadth; height = other.height; length = other.length;
        }

        int getBreadth() { return breadth;}
        int getHeight() { return height;}
        int getLength() { return length;}
        long long CalculateVolume() { return (long long)breadth * height*length; }

        friend bool operator<(Box& b1, Box& b2){
            if(b1.length < b2.length){
                    return true;
            }
            if(b1.length == b2.length && b1.breadth < b2.breadth){
                return true;
            }
            if(b1.length == b2.length && b1.breadth ==b2.breadth && b1.height < b2.height){
                return true;
            }
            return false;
        }
        friend ostream operator <<(ostream s,Box& b){
            s<<b.getBreadth()<<" "<<b.getHeight()<<" "<< b.getLength();
            return s;
        }

};