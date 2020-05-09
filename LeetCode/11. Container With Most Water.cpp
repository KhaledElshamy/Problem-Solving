class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int start = 0 , end = height.size()-1,maximumArea = 0;
        while(start<end){
            int length = min(height[start],height[end]);
            int width = end - start;
            int area = length * width;
            
            maximumArea = max(maximumArea,area);
            if(height[end]>=height[start])start++;
            else end--;
        }
        return maximumArea;
    }
};
