class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        vector<pair<int, int>>left;
        vector<pair<int, int>>right;
        left.push_back({0,0});
        for(int i=0;i<boxes.size();i++){
            auto it=left.back();
            int a=it.first;
            int b=it.second;
            b+=a;
            if(boxes[i]=='1'){
                a++;
            }
            left.push_back({a,b});
        }
        right.push_back({0,0});
        for(int i=boxes.size()-1;i>=0;i--){
            auto it=right[0];
            int a=it.first;
            int b=it.second;
            b+=a;
            if(boxes[i]=='1'){
                a++;
            }
            right.insert(right.begin(), {a,b});
        }
        for(int i=1;i<=boxes.size();i++){
            int a=left[i].second+right[i-1].second;
            ans.push_back(a);
        }
        return ans;
    }
};