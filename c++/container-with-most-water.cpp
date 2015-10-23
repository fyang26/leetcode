class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size()==0) return 0;
        int n = height.size();
        int maxarea = 0;
        int lo=0, hi=n-1;
        while (lo<hi) {
            maxarea = max(maxarea, min(height[hi], height[lo]) * (hi-lo));
            if (height[lo]<height[hi]) lo++;
            else hi--;
        }
        return maxarea;
    }
};