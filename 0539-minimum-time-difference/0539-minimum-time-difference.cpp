class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int n = timePoints.size();
        int min = INT_MAX;
        for (int i = 0; i < timePoints.size() - 1; i++) {
            int a = stoi(timePoints[i].substr(0, 2));
            int b = stoi(timePoints[i].substr(3, 2));
            int c = stoi(timePoints[i + 1].substr(0, 2));
            int d = stoi(timePoints[i + 1].substr(3, 2));
            if (a == c && b == d)
                return 0;
            if(a==c ){
                if(d>b) {
                    if(min>d-b){
                        min=d-b;
                    }
                }
            }
            int hour, minute;
            hour = c - a;
            
            if(d>=b){
                minute=d-b;
            }
            else{
                minute=60-b+d;
                hour--;
            }
            hour = hour * 60 + minute;
            if (hour < min) {
                min = hour;
            }
        }
        int a = stoi(timePoints[0].substr(0, 2));
        int b = stoi(timePoints[0].substr(3, 2));
        int c = stoi(timePoints[n - 1].substr(0, 2));
        int d = stoi(timePoints[n - 1].substr(3, 2));
        if (a == c && b == d)
            return 0;
        a=24+a;
        int hour,minute;
        hour=a-c;
        if(b>=d){
            minute=b-d;
        }
        else{
            minute=60-d+b;
            hour--;
        }
        hour=hour*60+minute;
        // int hour, minute;
        // if ((24 - c + a) < c - a) {
        //     hour = 24 - c + a;
        // } else {
        //     hour = c - a;
        // }
        // if (d > b) {
        // if (b == 0) {
        //     b = 60;
        //     minute=b-d;
        //     hour--;
        // }
        // else{
        //     minute = d - b;

        // }
        // } else {
        //     minute = 60 - b + d;
        //     hour--;
        // }
        // hour = hour * 60 + minute;
        if (hour < min) {
            min = hour;
        }

        return min;
    }
};