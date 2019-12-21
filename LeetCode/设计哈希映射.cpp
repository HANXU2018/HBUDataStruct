class MyHashMap {
public:
    //拉链法，比用数组 省很多空间，利用hash函数 key%N  即最多N条链，相当于分类，这样其实如果分类得好，每条链都很短的
    const static int N = 20011; //%一个素数 比较好
    vector<list<pair<int, int>>> hash;
    /** Initialize your data structure here. */
    MyHashMap() {
        hash = vector<list<pair<int, int>>>(N);
    }
    
    list<pair<int, int>>::iterator find (int key) {
        int k = key % N; //定位到 k链
        auto it = hash[k].begin();
        for (; it != hash[k].end(); it++) {
            if (it->first == key)//存在
                break;
        }
        return it;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int k = key % N;
        auto it = find(key);
        //存在两种情况，一就是it就是k链的end()  即还不存在  二就是找到了
        if (it != hash[k].end())
            it->second = value;
        else 
            hash[k].push_back(make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int k = key % N;
        auto it = find(key);
        //其实对于链表，我找到了it 是可以O1删除的，不过我们也可以标记它 
        if (it == hash[k].end())
            return -1;
        return it->second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int k = key % N;
        auto it = find(key);
        if (it != hash[k].end())
            hash[k].erase(it);
    }
};

作者：liang-yi-wei
链接：https://leetcode-cn.com/problems/design-hashmap/solution/shu-zu-qu-qiao-la-lian-fa-da-shu-ju-kai-fang-xun-z/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。