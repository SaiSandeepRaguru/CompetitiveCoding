class Solution {
public:
    int search(vector<int>& a, int target) {
        int low=0,high=a.size()-1;
        while(low<=high){
            int mid=low+(high-low) /2;
            if(a[mid]==target){
                return mid;
            } //check if left half is sorted, dont worry about comparing target
            else if(a[low]<=a[mid]){ //use = because it may point to single element
                if(a[low]<=target && target<a[mid]){
                    high=mid-1;
                } else {
                    low=mid+1;
                }
            } //if left is not sorted then right would be sorted
            else {
                if(a[mid]<target && target<=a[high]){
                    low=mid+1;
                } else {
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};
