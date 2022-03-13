#include <memory>
#include <list>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*
    get(key) -
        if (hash_table[key] != hash_table.end())
            cache.splice(cache.begin(), cache, it->second)
            return key
        else
            return -1
        

    put() -
    auto it = hash_table[key]  
    if it == hash_table.end()
        if (cache.size == max_size)
            auto last = cache.back()
            cache.push_front(pair<int, int>(key,value))
            hash_table[key] = cache.begin();
            hash_table.erase(last);
        else
            cache.push_front(pair<int, int>(key,value))
            hash_table[key] = cache.begin();
    else
        hash_table->second->second = value
        cache.splice(cache.begin(), cache, it->second)
        
*/

class LRUCache {
public:
    LRUCache(int capacity) {
        max_size = capacity;
    }
    
    int get(int key) {
        auto it = hash_table.find(key);
        if (it != hash_table.end()) {
            cache.splice(cache.begin(), cache, it->second);
            return it->second->second;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        auto it = hash_table.find(key);
        if (it == hash_table.end()) {
            if(cache.size() == max_size) {
                auto last = cache.back().first;
                cache.push_front(pair<int, int>(key,value));
                cache.pop_back();
                hash_table[key] = cache.begin();
                hash_table.erase(last);
            }
            else {
                cache.push_front(pair<int,int>(key, value));
                hash_table[key] = cache.begin();
            }
        } else {
            it->second->second = value;
            cache.splice (cache.begin(), cache, it->second);
        }
    }
    
    void display () {
        list<pair<int,int>>::iterator it;
        for(it=cache.begin();it!=cache.end();++it)
            cout << "<" << it->first << "," << it->second << ">";
        cout << endl;
    }
    
private:
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hash_table;
    int max_size;
};


int main() {
    unique_ptr<LRUCache> Cache = make_unique<LRUCache>(2);
    Cache->put(1,1);
    Cache->put(2,2);
    cout << Cache->get(1) << endl;
    
    Cache->display();
}