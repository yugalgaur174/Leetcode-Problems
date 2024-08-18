#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int nthUglyNumber(int m) {
        if (m <= 0) return 0;
        std::priority_queue<long, std::vector<long>, std::greater<long>> pq;
        std::unordered_set<long> seen;
        pq.push(1);
        seen.insert(1);
        std::vector<int> factors = {2, 3, 5};
        long current_ugly = 1;
        for (int i = 1; i < m; ++i) {
            current_ugly = pq.top();
            pq.pop();
            for (int factor : factors) {
                long next_ugly = current_ugly * factor;
                if (seen.find(next_ugly) == seen.end()) {
                    pq.push(next_ugly);
                    seen.insert(next_ugly);
                }
            }
        }
        return pq.top();
    }
};



// class Solution {
// public:
//     int nthUglyNumber(int m) {
//         // if(n<0) return 0;
//         // for(int i=n;i)
//         int count=0;
//         for(int n=1;n<INT_MAX;n++){
//             int i=n;
//             while(i%10==0) i/=10;
//             while(i%15==0) i/=15;
//             while(i%2==0) i/=2;
//             while(i%3==0) i/=3;
//             while(i%5==0) i/=5;
//             if(i==1) count++;
//             if(count==m) return n;
//         }
//         return count;
//     }
// };