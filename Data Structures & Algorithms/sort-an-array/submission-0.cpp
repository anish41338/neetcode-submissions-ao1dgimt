class Solution {
public:
    void merge(vector<int>&nums,int start,int mid,int end){
        int l=start;
        int r=mid+1;
        vector<int>temp;
        while(l<=mid && r<=end){
            if(nums[l]<=nums[r])temp.push_back(nums[l++]);
            else temp.push_back(nums[r++]);
        }
        while(l<=mid)temp.push_back(nums[l++]);
        while(r<=end)temp.push_back(nums[r++]);
        for(int i=start;i<=end;i++){
            nums[i]=temp[i-start];
        }
    }
    void mergesort(vector<int>&nums,int start,int end){
        if(start>=end)return;
        int mid=start+(end-start)/2;
        mergesort(nums,start,mid);
        mergesort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return nums;
    }
};