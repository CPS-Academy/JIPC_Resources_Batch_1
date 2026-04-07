class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> survivingAsteroids;
        for(auto& asteroid: asteroids) {
            if(asteroid > 0) {
                survivingAsteroids.push_back(asteroid);
                continue;
            }
            int asteroidValue = abs(asteroid);
            while(!survivingAsteroids.empty() 
                    && survivingAsteroids.back() > 0 
                    && survivingAsteroids.back() < asteroidValue) {
                        survivingAsteroids.pop_back();
            }

            if(!survivingAsteroids.empty() && survivingAsteroids.back() == asteroidValue) {
                survivingAsteroids.pop_back();
            }
            else if(survivingAsteroids.empty() || survivingAsteroids.back() < 0) {
                survivingAsteroids.push_back(asteroid);
            }
        }
        return survivingAsteroids;
    }
};
