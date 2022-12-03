
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


    Node*funct(map<Node*,int>&visited,Node*node,map<Node*,Node*>&opp){
       
    Node*root=new Node();
    root->val=node->val;
    vector<Node*>neigh;
    
    visited[node]=1;
    opp[node]=root;
    int s=node->neighbors.size();
    for(int i=0;i<s;i++){
        Node*temp=node->neighbors[i];
        if(!visited[temp] || visited[temp]==0)
        neigh.push_back(funct(visited,temp,opp));
        else neigh.push_back(opp[node]);
    } 
        root->neighbors=neigh;
    return root;    
    }

    Node* cloneGraph(Node* node) {
        map<Node*,int>visited;
        map<Node*,Node*>opp;
        return funct(visited,node,opp);
    }
