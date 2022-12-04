
// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
public:
    void funct(map<Node*,Node*>&track,Node*node){
    Node*root= new Node(node->val);
    track[node]=root;    
    for(auto it:node->neighbors){
        if(track.find(it)!=track.end()){
           root->neighbors.push_back(track[it]); 
        }else{
            funct(track,it);
            root->neighbors.push_back(track[it]);
        }
    }    
        
        
    }
    
    Node* cloneGraph(Node* node) {
    if(node==NULL)return NULL;
        map<Node*,Node*>track;
 funct(track,node);    
return track[node];        
    }
};
