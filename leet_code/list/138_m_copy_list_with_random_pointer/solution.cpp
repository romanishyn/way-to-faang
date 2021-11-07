/*
https://leetcode.com/problems/copy-list-with-random-pointer/
*/

#include <unordered_map>

namespace {
/*
N - number of nodes

Time O(N)
Space O(N)
*/

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map< Node*, Node* > originalCopy;
        return cloneNode( head, originalCopy );
    }

private:
    Node* cloneNode( Node* node, std::unordered_map< Node*, Node* >& originalCopy ) {
        if( ! node )
            return node;

        if( auto it = originalCopy.find( node ); it != originalCopy.end() )
            return it->second;

        auto copyNode = new Node( node->val );
        originalCopy.try_emplace( node, copyNode );

        copyNode->next = cloneNode( node->next, originalCopy );
        copyNode->random = cloneNode( node->random, originalCopy );

        return copyNode;
    }
};
} // namespace

namespace {
/*
N - number of nodes

Time O(N)
Space O(N)
*/
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if( ! head )
            return head;

        std::unordered_map< Node*, Node* > originalCopy;

        auto curr = head;
        while( curr ) {
            originalCopy.try_emplace( curr, new Node( curr->val ) );
            curr = curr->next;
        }

        curr = head;
        while( curr ) {
            auto clone = originalCopy[ curr ];
            clone->next = originalCopy[ curr->next ];
            clone->random = originalCopy[ curr->random ];

            curr = curr->next;
        }

        return originalCopy[ head ];
    }
};
} // namespace

namespace {
/*
N - number of nodes

Time O(N)
Space O(1)
*/
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if( ! head )
            return head;

        auto curr = head;
        while( curr ) {
            auto clone = new Node( curr->val );
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        curr = head;
        while( curr ) {
            if( curr->random )
                curr->next->random = curr->random->next;

            curr = curr->next->next;
        }

        auto copyHead = head->next;
        auto copyCurr = copyHead;
        curr = head;

        while( curr ) {
            curr->next = copyCurr->next;
            curr = curr->next;
            if( curr ) {
                copyCurr->next = curr->next;
                copyCurr = copyCurr->next;
            }
        }

        return copyHead;
    }
};
} // namespace

namespace {
/*
N - nubmer of nodes

Time O(N)
Space O(N)
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map< Node*, Node* > origToCopy;
        origToCopy[ nullptr ] = nullptr;
        
        auto curr = head;
        while( curr ) {
            auto node = new Node( curr->val );
            origToCopy[ curr ] = node;
            curr = curr->next;
        }
        
        curr = head;
        while( curr ) {
            auto node = origToCopy[ curr ];
            node->next = origToCopy[ curr->next ];
            node->random = origToCopy[ curr->random ];
            curr = curr->next;
        }
        
        return origToCopy[ head ];
    }
};
} // namespace

namespace {
/*
N - number of nodes

Time O(N)
Space O(1)
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if( ! head )
            return nullptr;
        
        auto curr = head;
        while( curr ) {
            auto node = new Node( curr->val );
            node->next = curr->next;
            curr->next = node;
            curr = curr->next->next;
        }
        
        curr = head;
        while( curr ) {
            if( curr->random )
                curr->next->random = curr->random->next;
            
            curr = curr->next->next;
        }
        
        auto copyHead = head->next;
        auto copyCurr = copyHead;
        curr = head;
        while( curr ) {
            curr->next = curr->next->next;
            if( curr->next )
                copyCurr->next = curr->next->next;
            curr = curr->next;
            copyCurr = copyCurr->next;
        }
        
        return copyHead;
    }
};
} // namespace
