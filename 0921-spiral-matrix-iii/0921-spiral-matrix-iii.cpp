class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        vector<int> cur;
        cur.push_back(r0); cur.push_back(c0);
        int times = 1;
        int rdstride = 2*times-1; 
        int lustride =  2*times; 
        char dir = 'r';
        int res = rdstride;
        while(ans.size()!=R*C){
            if(cur[0]>=0 && cur[0]<R && cur[1]>=0 && cur[1]<C){
                ans.push_back(cur);
            }
            switch(dir){
                case 'r':
                    cur[1]+=1;
                    res--;
                    if(res==0){
                        dir = 'd';
                        res = rdstride;
                    }
                    break;
                case 'd':
                    cur[0]+=1;
                    res--;
                    if(res==0){
                        dir = 'l';
                        res = lustride;
                    }
                    break;
                case 'l':
                    cur[1]-=1;
                    res--;
                    if(res==0){
                        dir = 'u';
                        res = lustride;
                    }
                    break;
                case 'u':
                    cur[0]-=1;
                    res--;
                    if(res==0){
                        dir = 'r';
                        times+=1;
                        rdstride = 2*times-1;
                        lustride =  2*times;
                        res = rdstride;
                    }
            }
            
        }
        return ans;
    }
};