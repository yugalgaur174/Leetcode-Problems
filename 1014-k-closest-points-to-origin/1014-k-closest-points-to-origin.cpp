class Solution {
public:
    class custom{
        public:
        bool operator()(pair <int, int> a,pair<int, int> b){
            double dista=pow(a.first,2)+pow(a.second,2);
            double distb=pow(b.first,2)+pow(b.second, 2);
            return dista>distb;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>> , custom> pq;
        for(int i=0;i<points.size();i++){
            pq.push({points[i][0],points[i][1]});
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            ans.push_back({pq.top().first,pq.top().second});
            pq.pop();
        }
        return ans;
    }
};