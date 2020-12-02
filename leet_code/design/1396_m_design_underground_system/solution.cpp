/*
https://leetcode.com/problems/design-underground-system/
*/

#include <string>
#include <unordered_map>

using std::string;

namespace {
/*
P - number of passengers making a journey concurrently during peak time
S - number of stations on the network

Time O(1)
Space O(P + S^2)
*/
class UndergroundSystem {
    struct Rout {
        int count{ 0 };
        int totalTime{ 0 };
    };

    std::unordered_map< int, std::pair< std::string, int > > idToStartStation;
    std::unordered_map< std::string, std::unordered_map< std::string, Rout > > routs;

public:
    UndergroundSystem() {
        
    }

    void checkIn(int id, string stationName, int t) {
        idToStartStation.try_emplace( id, stationName, t );
    }

    void checkOut(int id, string stationName, int t) {
        auto it = idToStartStation.find( id );
        auto& routInfo = routs[ it->second.first ][ stationName ];
        ++routInfo.count;
        routInfo.totalTime += t - it->second.second;
        idToStartStation.erase( it );
    }

    double getAverageTime(string startStation, string endStation) {
        const auto& routInfo = routs[ startStation ][ endStation ];
        return static_cast< double >( routInfo.totalTime ) / routInfo.count;
    }
};
} // namespace
