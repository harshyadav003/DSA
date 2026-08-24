class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {//gs=groupSize
         int n = hand.size();

        if (n % gs != 0)
            return false;

        unordered_map<int, int> freq;
        priority_queue<int, vector<int>, greater<int>> minh;

        for (int x : hand) {
            freq[x]++;
            minh.push(x);
        }
          while (!minh.empty()) {
            int curr=minh.top();
            if(freq[curr] == 0) {
                    minh.pop();
                    continue;
                }

            for(int i=0;i<gs;i++){
                if(freq[curr+i]==0) return false;

                 freq[curr + i]--;
            }
            minh.pop();
          }
        return true;
    }
};