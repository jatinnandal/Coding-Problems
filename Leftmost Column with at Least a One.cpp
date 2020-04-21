/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> v = binaryMatrix.dimensions();
        int ans = 101;
        for(int i=0;i<v[0];i++){
            int s = 0, e = v[1]-1;
            while(s<=e){                //binary search to find the leftmost col with 1 for each row
                int mid = (s+e)/2;
                if(binaryMatrix.get(i,mid)==1){
                        ans = min(ans,mid);
                        e = mid-1;
                }else{
                    s = mid+1;
                }
            }
        }
        if(ans==101)
            return -1;
        return ans;
    }
};
