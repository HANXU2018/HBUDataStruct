struct Node{
    int val;
    Node *next;
    Node(int val): val(val),next(nullptr){}
};
const int len = 100;
class MyHashSet {
    
public:
    vector<Node*> arr; //本题题点
    /** Initialize your data structure here. */
    MyHashSet() {
        arr = vector<Node*>(len, new Node(-1));
    }
    
    void add(int key) {
        int haval = key % len;
        Node* temp = arr[haval];
        if(temp -> val != -1){
            while(temp){
                if(temp -> val == key)  return;
                if(!(temp -> next)){
                    Node *node = new Node(key);
                    temp -> next = node;
                    return;
                }
                temp = temp -> next;
            }
        }
        else{
            temp -> val = key;
            return;
        }
    }
    
    void remove(int key) {
        int haval = key % len;
        Node* temp = arr[haval];
        if(temp -> val != -1){
            while(temp){
                if(temp -> val == key){
                    temp -> val = -1;
                    return;
                }
                temp = temp -> next;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int haval = key % len;
        Node* temp = arr[haval];
            while(temp){
                if(temp -> val == key)    return true;
                temp = temp -> next;
            }
        return false;
    }
};

作者：youlookdeliciousc
链接：https://leetcode-cn.com/problems/design-hashset/solution/cxiang-xi-ti-jie-by-youlookdeliciousc-18/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

void add(int key) {
        int n = key % len;
        
        Node* pre = data[n];
        while(pre->next != nullptr){
            if(pre->next->val == key) return;
            pre = pre->next;
        }
        pre->next = new Node(key);
    }
    
    void remove(int key) {
        int n = key % len;
        Node* pre = data[n];
        while(pre->next != nullptr) {
            if(pre->next->val == key) {
                pre->next = pre->next->next;
                return;
            }
            pre = pre->next;
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int n = key %len;
        Node* cur = data[n]->next;
        while(cur != nullptr) {
            if(cur->val == key) return true;
            cur = cur->next;
        }
        return false;
    }