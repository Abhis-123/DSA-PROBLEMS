#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int>& arr, int k){
    int  low = 0, high = arr.size();
    while(low<high){
        int mid = low + (high - low)/2;
        if(arr[mid]>=k){
            high = mid;
        }else{
            low = mid +1 ;
        }
    }
    if(low < arr.size() && arr[low]!=k) low++; 
    return low;
}
int upper_bound(vector<int>& arr, int k){
    int  low = 0, high = arr.size();
    while(low<high){
        int mid = low + (high - low)/2;
        if(arr[mid]>k){
            high = mid;
        }else{
            low = mid +1 ;
        }
    }
    if(high>0 && arr[high]!=k) high--; 
    return high;
}


int main(){

    vector<int> v = {1,1,1,2,3,4,4,6,6,6,8,8,8};
    cout<<upper_bound(v,7)<<endl;
    cout<<lower_bound(v,6)<<endl;

}