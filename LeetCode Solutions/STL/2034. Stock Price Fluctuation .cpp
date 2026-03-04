class StockPrice {
private:
    unordered_map<int, int> timestampToPriceMap;
    multiset<int> priceSet;
    int latestStockPrice;
    int latestTimestamp;

public:
    StockPrice() {
        timestampToPriceMap.clear();
        priceSet.clear();
    }
    
    void update(int timestamp, int price) {
        if(latestTimestamp <= timestamp) {
            latestTimestamp = timestamp;
            latestStockPrice = price;
        }
        if(timestampToPriceMap.count(timestamp)) {
            auto oldPrice = priceSet.find(timestampToPriceMap[timestamp]);
            priceSet.erase(oldPrice);
        }
        timestampToPriceMap[timestamp] = price;
        priceSet.insert(price);
    }
    
    int current() {
        return latestStockPrice;
    }
    
    int maximum() {
        return *(--priceSet.end());
    }
    
    int minimum() {
        return *priceSet.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
