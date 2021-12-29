#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void merge_two_sorted_arrays(vector<int>& nums1, int m,vector<int>& nums2,int n){
    // nums1 is sorted and of size m+n, first m elements are original elements 
    // of the array other elements are zeros (places for second array elements) 
    // nums2 is sorted and of size n
    while(m>=0||n>=0){
        if(m>0 & n>0){
            // set the max element of the two arrays
            if(nums1[m-1] > nums2[n-1]){
                nums1[n+m-1] = nums1[m-1];
                m--;
            }else{

                nums1[n+m-1] = nums2[n-1];
                n--;
            }
        }else{
            cout<<n<<" "<<m<<endl;
            if (n==0){
                break;
            }else{
                nums1[n+m-1] = nums2[n-1];
                n--;
            }
        }
    }
}

vector<int> array_to_vector(int array[], int n){
    vector<int> result;
    for(int i=0; i<n; i++){
        result.push_back(array[i]);
    }
    return result;
}

int main(){
    int x[] = {0};
    int x_size = 1;
    vector<int> nums1 = array_to_vector(x,x_size);
    int y[] = {5};
    int y_size = 1;
    vector<int> nums2 = array_to_vector(y,y_size);
    merge_two_sorted_arrays(nums1,x_size-y_size,nums2, y_size);
    for(int i=0; i<nums1.size(); i++){
        cout << nums1[i]<< endl;
    }
}