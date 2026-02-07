class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> workers;
        int workerCount = quality.size();
        for(int i = 0; i < workerCount; i++) {
            double ratio = (1.0*wage[i])/quality[i];
            workers.push_back({ratio, quality[i]});
        }
        sort(workers.begin(), workers.end());

        int qualitySum = 0;
        priority_queue<int> maxHeapQuality;
        double minCostToHire = 1e18;
        for(auto& worker: workers) {
            double ratio = worker.first;
            int quality = worker.second;

            maxHeapQuality.push(quality);
            qualitySum += quality;

            if(k < maxHeapQuality.size()) {
                qualitySum -= maxHeapQuality.top();
                maxHeapQuality.pop();
            }

            if(k == maxHeapQuality.size()) {
                minCostToHire = min(minCostToHire, 1.0*qualitySum*ratio);
            }
        }

        return minCostToHire;
    }
};



class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int workerCount = quality.size();
        double minCostToHire = 1e18;
        for(int i = 0; i < workerCount; i++) {
            double ratio = (1.0*wage[i])/quality[i];
            vector<double> allowedWorkers;
            for(int j = 0; j < workerCount; j++) {
                int workerQuality = quality[j];
                int workerWage = wage[j];
                if(ratio*workerQuality >= workerWage) {
                    allowedWorkers.push_back(ratio*workerQuality);
                }
            }
            sort(allowedWorkers.begin(), allowedWorkers.end());
            if(allowedWorkers.size() < k) {
                continue;
            }
            double min_k_wages = 0;
            for(int j = 0; j < k; j++) {
                min_k_wages += allowedWorkers[j];
            }
            minCostToHire = min(minCostToHire, min_k_wages);
        }
        return minCostToHire;
    }
};
