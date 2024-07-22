class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        for(int i=0;i<names.size();i++){
                int max=heights[i];
                int m=i;
            for(int j=i;j<names.size();j++){
                if(heights[j]>max){
                    max=heights[j];
                    m=j;
                }
            }
            swap(names[i],names[m]);
            swap(heights[i],heights[m]);
        }
        return names;
    }
};