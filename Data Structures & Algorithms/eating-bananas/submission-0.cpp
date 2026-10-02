class Solution {
public:
    int needToBeEaten(vector<int> &piles, int value){
        int sum = 0;
        for (auto val: piles){
            sum += val / value;
            if (val % value != 0) sum++;
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int left = 1, right = piles[piles.size() - 1];
        int solution = -1;
        while (left <= right){
            int mid = (left + right) / 2;
            if (needToBeEaten(piles, mid) <= h){
                solution = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return solution;
    }
};