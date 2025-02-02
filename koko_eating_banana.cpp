    int findTotal(vector<int>& piles, int mid) {
        int total = 0;
        for (auto it : piles)
            total += ceil((double)it / (double)mid);
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while (low < high) {
            int mid = (low + high) / 2;
            int totalHours = findTotal(piles, mid);
            if (totalHours <= h)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
int main(){
    vector<int>piles;
    for(int i = 0 ; i < piles.size() ; i++)
        cin >> piles[i];
    int h;
    cin >> h;
    cout << minEatingSpeed(piles , h) << endl;
    return 0;
}
