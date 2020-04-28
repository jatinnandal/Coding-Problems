 bool compare_interval(vector<int> &a, vector<int> &b){
        return a[0]<b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0||intervals.size()==1)
            return intervals;
        sort(intervals.begin(),intervals.end(),compare_interval);
        vector<vector<int> > v;
        v.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=v[v.size()-1][1]){
                v[v.size()-1][1] = max(intervals[i][1],v[v.size()-1][1]);
            }else{
                v.push_back(intervals[i]);
            }
        }
        return v;
    }
};
