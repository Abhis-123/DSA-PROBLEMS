
vector<int> twoSum(vector<int> &nums, int target){
        // result vector to store the result
        vector<int> result;

        // size of nums array
        int size = nums.size();

        // first pointer to track the elements of input vector
        for(int i = 0;i<size;i++){
            /*second pointer to track the elements of output vector*/
            for(int j = i+1;j<size;j++){

                // match the sum of the two elements 
                if (nums[i]+nums[j]==target){
                    // break out of loop
                    // and push indexes in result vector
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
     return result;   
    }
int main(){
    vector<int> nums{[2,7,11,15};
    int target = 9;
    // nums.push_back()
    cout << twoSum(nums) << endl;


}