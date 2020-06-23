/*
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
*/

#pragma once

#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>

using std::string;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

namespace V1 {
/*
 * Here we use DFS based on stack recursion.
 * When serialize each node:
 * if node null: add to stream null value
 * if node not-null: add value of node to stream, and handle left and right child recursively
 * When deserialize:
 * Get value from stream: if value equal to nullValue return null pointer, else create node from value and get assign
 * left and right node, this node get recursively.
 *
 * Time (n)
 * Space (n)
 * */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::ostringstream stream;
        serializeHelper(root, stream);
        return stream.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::istringstream stream( data );
        return deserializeHelper( stream );
    }

private:
    const char Delimiter = ',';
    const std::string NullNodeValue = "#";

private:
    void serializeHelper(TreeNode* node, std::ostringstream& stream) {
        if( !node ) {
            stream << NullNodeValue << Delimiter;
        }
        else {
            stream << node->val << Delimiter;

            serializeHelper( node->left, stream );
            serializeHelper( node->right, stream );
        }
    }

    TreeNode* deserializeHelper(std::istringstream& stream) {
        std::string nodeValue;
        std::getline( stream, nodeValue, Delimiter );

        if( nodeValue == NullNodeValue ) {
            return nullptr;
        }
        else {
            auto node = new TreeNode( std::stoi( nodeValue ) );

            node->left = deserializeHelper( stream );
            node->right = deserializeHelper( stream );

            return node;
        }
    }
};
} // namespace V1

namespace V2 {
/*
 * Here we use BFS method to handle binary tree. For null node we use NullNodeValue ("#"), and delimiter between values Delimiter (',').
 * When serialise the tree, add to string value of nodes, for null node value NullNodeValue, and all valid node push to queue.
 * When serialise the string, assign left and right node for each not-null node, and add not-null node to children to the queue, waiting to be handled.
 *
 * Serialization:
 * Time (n)
 * Space (n)
 *
 * Deserialization:
 * Time (n)
 * Space (n)
 * */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if( !root )
            return {};

        std::ostringstream stream;
        stream << root->val << Delimiter;

        std::queue< TreeNode* > queue;
        queue.push( root );

        while( !queue.empty() ) {
            auto node = queue.front();
            queue.pop();

            if( node->left ) {
                stream << node->left->val << Delimiter;
                queue.push( node->left );
            }
            else {
                stream << NullNodeValue << Delimiter;
            }

            if( node->right ) {
                stream << node->right->val << Delimiter;
                queue.push( node->right );
            }
            else {
                stream << NullNodeValue << Delimiter;
            }
        }

        return stream.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if( data.empty() )
            return nullptr;

        std::istringstream stream( data );

        std::string nodeValue;
        std::getline( stream, nodeValue, Delimiter );

        auto root = new TreeNode( std::stoi( nodeValue ) );

        std::queue< TreeNode* > queue;
        queue.push( root );

        while( !queue.empty() && stream ) {
            auto node = queue.front();
            queue.pop();

            std::getline( stream, nodeValue, Delimiter );
            if( nodeValue != NullNodeValue ) {
                auto left = new TreeNode( std::stoi( nodeValue ) );
                node->left = left;
                queue.push( left );
            }

            std::getline( stream, nodeValue, Delimiter );
            if( nodeValue != NullNodeValue ) {
                auto right = new TreeNode( std::stoi( nodeValue ) );
                node->right = right;
                queue.push( right );
            }
        }

        return root;
    }

private:
    const char Delimiter = ',';
    const std::string NullNodeValue = "#";
};
} // namespace V2

