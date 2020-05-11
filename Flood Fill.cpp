class Solution {
public:
    bool isSafe(vector<vector<int>>& image, int sr, int sc){
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size())
            return false;
        return true;
    }
    
    void fillColor(vector<vector<int>>& image, int sr, int sc, int newcolor,int prevColor){
        if(!isSafe(image,sr,sc))
            return;
        if(image[sr][sc]!=prevColor)
            return;
        image[sr][sc] = newcolor;
        fillColor(image,sr+1,sc,newcolor,prevColor);
        fillColor(image,sr-1,sc,newcolor,prevColor);
        fillColor(image,sr,sc+1,newcolor,prevColor);
        fillColor(image,sr,sc-1,newcolor,prevColor);

    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        if(image[sr][sc]==newcolor)
            return image;
        fillColor(image,sr,sc,newcolor,image[sr][sc]);
        return image;
    }
};
