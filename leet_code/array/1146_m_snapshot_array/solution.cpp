/*
https://leetcode.com/problems/snapshot-array/
*/

#include <vector>

namespace {
/*
N - length
M - set times for spesific idx

Space: O(N)
Time:
SnapshotArray: O(1)
set: O(1)
snap: O(1)
get: logM
*/
class SnapshotArray {
    std::vector< std::vector< std::pair< int, int > > > snapshots;
    int snapshotIdx = 0;

public:
    SnapshotArray(int length)
    :   snapshots( length )
    {
        
    }

    void set(int index, int val) {
        auto& snapshot = snapshots[ index ];
        if( snapshot.empty() || snapshot.back().first < snapshotIdx ) {
            snapshot.emplace_back( snapshotIdx, val );
        }
        else {
            snapshot.back().second = val;
        }
    }

    int snap() {
        return snapshotIdx++;
    }

    int get(int index, int snap_id) {
        const auto& snapshot = snapshots[ index ];

        int ans = 0;
        int left = 0;
        int right = snapshot.size() - 1;

        while( left <= right ) {
            const int mid = left + ( right - left ) / 2;

            if( snapshot[ mid ].first <= snap_id ) {
                ans = snapshot[ mid ].second;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
} // namespace
