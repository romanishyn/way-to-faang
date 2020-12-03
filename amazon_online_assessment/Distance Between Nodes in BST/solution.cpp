/*
https://leetcode.com/discuss/interview-question/376375/
*/

#include <vector>

namespace {
/*
Copied:
Time complexity: O(n * h), where n is the number of nodes and h is the height of the tree.
In the worst case tree is not balanced (elements are already in sorted order) and complexity will be O(n^2).
Space complexity: O(n).
*/
class Solution {
    struct Node {
        using Ptr = std::unique_ptr< Node >;

        int value;
        Ptr left;
        Ptr right;

        Node( int value )
        :   value{ value }
        {}
    };

public:
    int getDistanceBetweenNodes( const std::vector< int >& nums, int node1, int node2 ) {
        int found = 0;
        Node::Ptr root;
        for( int num : nums ) {
            if( num == node1 || num == node2 )
                ++found;

            root = insertNode( std::move( root ), num );
        }

        if( found != 2 )
            return -1;

        auto nodeLCA = findLCA( root.get(), node1, node2 );
        return getDistanse( nodeLCA, node1 ) + getDistanse( nodeLCA, node2 );
    }

private:
    Node::Ptr insertNode( Node::Ptr root, int val ) {
        if( ! root )
            return std::make_unique< Node >( val );

        if( val < root->value )
            root->left = insertNode( std::move( root->left ), val );
        else
            root->right = insertNode( std::move( root->right ), val );

        return std::move( root );
    }

    Node* findLCA( Node* node, int node1, int node2 ) {
        while( node ) {
            if( node1 < node->value && node2 < node->value )
                node = node->left.get();
            else if( node1 > node->value && node2 > node->value )
                node = node->right.get();
            else
                break;
        }
        return node;
    }

    int getDistanse( Node* node, int value ) {
        int distance = 0;
        while( node->value != value ) {
            ++distance;
            if( value < node->value )
                node = node->left.get();
            else
                node = node->right.get();
        }
        return distance;
    }
};

int main() {
    Solution solution;
    std::vector< int > nums{ 2, 1, 3 };
    int node1 = 1;
    int node2 = 3;
    assert( solution.getDistanceBetweenNodes( nums, node1, node2 ) == 2 );
    return 0;
}
} // namespace
