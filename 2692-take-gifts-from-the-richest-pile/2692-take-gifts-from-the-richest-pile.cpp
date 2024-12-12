class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int i=0;i<gifts.size();i++){
            pq.push(gifts[i]);
        }
        if(gifts.size()==0)return 0;

        long long ans=0;
        for(int i=0;i<k;i++){
            int a=sqrt(pq.top());
            
            pq.pop();
            pq.push(a);
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};