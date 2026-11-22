/*
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
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        //Old, New Node
        unordered_map<Node*, Node*> map;
        
        //Nullptr maps to null
        map[nullptr] = nullptr; 

        Node* curr = head;

        while (curr)
        {
            //Make copy
            map[curr] = new Node(curr->val); 

            curr = curr->next;
        }  

        //Loop through hashy and point everything
        curr = head;

        while (curr)
        {
            map[curr]->next = map[curr->next];
            map[curr]->random = map[curr->random];
            curr = curr->next;
        }

        return map[head];
    }

private:

};