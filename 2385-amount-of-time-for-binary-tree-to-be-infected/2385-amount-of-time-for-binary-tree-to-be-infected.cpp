class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* st = nullptr;
        unordered_map<TreeNode*, TreeNode*> m;
        queue<TreeNode*> q1;
        q1.push(root);
        while(!q1.empty()){
            TreeNode* temp = q1.front();
            q1.pop();
            if(temp->val == start) st = temp;
            if(temp->left){
                m[temp->left] = temp;
                q1.push(temp->left);
            }
            if(temp->right){
                m[temp->right] = temp;
                q1.push(temp->right);
            }
        }
        int time = 0;
        queue<pair<TreeNode*, int>> q2;
        unordered_set<TreeNode*> visited;
        q2.push({st, 0});
        visited.insert(st); 
        while(!q2.empty()){
            TreeNode* temp = q2.front().first;
            int current_time = q2.front().second;
            q2.pop();
            time = max(time, current_time);
            if(temp->left && visited.find(temp->left) == visited.end()){
                visited.insert(temp->left);
                q2.push({temp->left, current_time + 1});
            }
            if(temp->right && visited.find(temp->right) == visited.end()){
                visited.insert(temp->right);
                q2.push({temp->right, current_time + 1});
            }
            if(m.find(temp) != m.end() && visited.find(m[temp]) == visited.end()){
                visited.insert(m[temp]);
                q2.push({m[temp], current_time + 1});
            }
        }
        return time;
    }
};