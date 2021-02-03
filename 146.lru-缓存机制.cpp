/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
struct DLinkedNode{
    int key , value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0) , value(0), prev(nullptr) , next(nullptr) {}
    DLinkedNode(int _key , int _value ): key(_key), value(_value), prev(nullptr),next(nullptr) {}
};//构造函数

class LRUCache {
private:
    int size ;
    int capacity;
    unordered_map<int,DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail; 
 
public:
    LRUCache(int _capacity) : capacity(_capacity) , size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }//首先建立头尾节点（非数据节点）
    
    int get(int key) {
        if(!cache.count(key)){//找不到就返回-1
            return -1;
        }
        //找到的话就取这个值，移动Node到最开始
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if( !cache.count(key) ){//如果找不到，new一个新的并放在Head；同时判断size大小是否超过阈值
            DLinkedNode* node =  new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if(size > capacity){//若超过阈值则删除tail数据节点，和cache的数据；
            //注意delete和--size;
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }

        }else{
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
    void addToHead( DLinkedNode* node ){//移动四根指针
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    void removeNode(DLinkedNode* node){//只需要将其前一个指向后一个即可
    //双链表可以直接remove node，因为前驱和后继可方便定位
    //单链表必须要双指针才能实现tmp交换
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node){
        //先删除再移动到头
        removeNode(node);
        addToHead(node);
    }
    DLinkedNode* removeTail(){
        //找到tail的前一个。remove就行；
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

