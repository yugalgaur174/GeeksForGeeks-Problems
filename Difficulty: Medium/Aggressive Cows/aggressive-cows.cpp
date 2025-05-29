class Solution {
public:
    bool canWePlace(vector<int> &nums, int j, int k){
        int last=nums[0];
        int cow=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-last>=j){
                last=nums[i];
                cow++;
                if(cow>=k){
                    return true;
                }
            }
            else{
                continue;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums[nums.size()-1]-nums[0];
        for(int i=1;i<=n;i++){
            if(canWePlace(nums,i, k)){
                continue;
            }
            else{
                return i-1;
            }
        }
        return n;
    }
};