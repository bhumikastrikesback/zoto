#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include <vector>
#include <string>
#include <algorithm>
#include "../models/Restaurant.h"
using namespace std;

class RestaurantManager {
    private:
        vector<Restaurant*> restraunts;
        static RestaurantManager* instance;
        
        RestaurantManager() {
            //private construstor
        }
    public:
        static RestaurantManager* getinstance(){
            if(!instance) {
                instance = new RestaurantManager();
            }
            return instance;
        }
        void addRestraunt(Restaurant* r) {
            restraunts.push_back(r);
        }
        vector<Restaurant*> searchByLocation(string loc){
            vector<Restaurant*> result;
            transform(loc.begin(), loc.end(), loc.begin(), :: tolower);
            for(auto r : restraunts) {
                string rl = r->getLocation();
                transform(rl.begin(), rl.end(), rl.begin(), :: tolower);
                if(rl == loc) {
                    result.push_back(r);
                }
            }

            return result;
        }
};

RestaurantManager* RestaurantManager::instance = nullptr;

#endif