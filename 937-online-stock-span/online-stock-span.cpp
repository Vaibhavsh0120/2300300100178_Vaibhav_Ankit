class StockSpanner {
public:
    
    vector<int> arr;

    StockSpanner() {
    }
    
    int next(int price) {

        // ----------------- Brute Force---------------
        
        arr.push_back(price);
        
        int i = arr.size() - 1;  // current index
        int span = 0;
        
        for(int j = i; j >= 0; j--) {
            if(arr[j] <= price) {
                span++;
            } else {
                break;
            }
        }
        
        return span;

        // --------------------------------------------
    }
};