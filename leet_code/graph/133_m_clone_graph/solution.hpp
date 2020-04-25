/*
https://leetcode.com/problems/clone-graph/
*/

#pragma once

#include <vector>
#include <map>
#include <string.h>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <stack>

using std::string;
using std::vector;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// DFS
//class Solution {
//
//    std::map< int, Node* > nodes;
//
//public:
//    Node* cloneGraph(Node* node) {
//        if( !node )
//            return nullptr;
//
//        auto it = nodes.find( node->val );
//        if( it == nodes.end() ) {
//            Node* newNode = new Node( node->val );
//            nodes[ node->val ] = newNode;
//
//            std::vector< Node* > neighbors;
//            for( Node* n : node->neighbors )
//                neighbors.push_back( cloneGraph( n ) );
//
//            newNode->neighbors = std::move( neighbors );
//
//            return newNode;
//        } else {
//            return it->second;
//        }
//
//        return nullptr;
//    }
//};

// DFS
//class Solution {
//
//    std::map< int, Node * > nodes;
//
//public:
//
//    Node* cloneGraph(Node* node) {
//        if( !node )
//            return nullptr;
//
//        if( nodes.find( node->val ) == nodes.end() ) {
//            Node* newNode = new Node( node->val );
//            nodes[ node->val ] = newNode;
//
//            for( Node* n : node->neighbors )
//                newNode->neighbors.push_back( cloneGraph( n ) );
//        }
//
//        return nodes[ node->val ];
//    }
//};

// DFS
//class Solution {
//
//    std::map< Node*, Node* > nodes;
//
//public:
//    Node* cloneGraph(Node* node) {
//        if( !node )
//            return nullptr;
//
//        if( nodes.find( node ) == nodes.end() ) {
//            Node* newNode = new Node( node->val );
//            nodes[ node ] = newNode;
//
//            for( Node* n : node->neighbors )
//                newNode->neighbors.push_back( cloneGraph( n ) );
//        }
//
//        return nodes[ node ];
//    }
//};


//BFS
//class Solution {
//public:
//    Node* cloneGraph(Node* node) {
//        if( !node )
//            return nullptr;
//
//        std::queue< Node* > todo;
//        std::unordered_map< Node*, Node* > seen;
//
//        Node* newNode = new Node( node->val );
//        seen[ node ] = newNode;
//        todo.push( node );
//
//        while( !todo.empty() ) {
//            auto cur = todo.front();
//            todo.pop();
//
//            for( auto adj : cur->neighbors ) {
//                auto it = seen.find( adj );
//                if( it == seen.end() ) {
//                    seen[ adj ] = new Node( adj->val );
//                    todo.push( adj );
//                }
//
//                seen[ cur ]->neighbors.push_back( seen[ adj ] );
//            }
//        }
//
//        return newNode;
//    }
//};

// DFS iteratively
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if( !node )
            return nullptr;

        std::stack< Node* > todo;
        std::unordered_map< Node*, Node* > seen;

        auto root = new Node( node->val );
        todo.push( node );
        seen[ node ] = root;

        while( !todo.empty() ) {
            auto cur = todo.top();
            todo.pop();

            for( auto adj : cur->neighbors ) {
                if( !seen.count( adj ) ) {
                    seen[ adj ] = new Node( adj->val );
                    todo.push( adj );
                }

                seen[ cur ]->neighbors.push_back( seen[ adj ] );
            }
        }

        return root;
    }
};
