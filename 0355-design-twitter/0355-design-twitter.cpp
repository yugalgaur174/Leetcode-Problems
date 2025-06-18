class Twitter {
public:
    // unordered_map<int, vector<pair<int, int>>> feed;
    unordered_map<int, priority_queue<pair<int, pair<int, int>>>> feed;
    unordered_map<int, unordered_set<int>> ifollow, followsme;
    unordered_map<int, vector<pair<int, int>>> posts;
    int time=0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        // feed[userId].push_back({tweetId, userId});
        feed[userId].push({++time,{tweetId, userId}});
        posts[userId].push_back({time,tweetId});
        for(auto & it: followsme[userId]){
            feed[it].push({time,{tweetId,userId}});
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        vector<pair<int, pair<int, int>>> temp;
        for(int i=feed[userId].size()-1;i>=0;i--){
            int a=feed[userId].top().second.first;
            int b=feed[userId].top().second.second;
            int t=feed[userId].top().first;
            temp.push_back({t,{a,b}});
            feed[userId].pop();
            if(ifollow[userId].count(b) || b==userId ){
                ans.push_back(a);
            }
            
            if(ans.size()==10){
                break;
            }
        }
        for(int i=0;i<temp.size();i++){
            feed[userId].push(temp[i]);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(ifollow[followerId].count(followeeId)){
            return;
        }
        ifollow[followerId].insert(followeeId);
        for(int i=0;i<posts[followeeId].size();i++){
            feed[followerId].push({posts[followeeId][i].first,{posts[followeeId][i].second,followeeId}});
        }
        followsme[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        ifollow[followerId].erase(followeeId);
        followsme[followeeId].erase(followerId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */