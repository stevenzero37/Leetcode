#include <iostream>
#include <vector>

class MyHashSet {
private:
    std::vector<int> list;
public:
    MyHashSet () {
    };
    
    void add (int key) {
        std::vector<int>::iterator it;
        for(it=list.begin(); it != list.end(); ++it) {
            if (*it == key) 
                return;
        }
        list.push_back(key);
    }
    
    void remove (int key) {
        std::vector<int>::iterator it;
        for(it=list.begin(); it != list.end(); ++it) {
            if (*it == key) {
               list.erase(it);
               return;
            }
        }
    }
    
    bool contains (int key) {
        std::vector<int>::iterator it;
        for(it=list.begin(); it != list.end(); ++it) {
            if (*it == key) 
                return true;
        }
        return false;
    }
    
};

int main() {
    MyHashSet *example = new MyHashSet();
    
    example->add(58);
    
    std::cout << example->contains(58);
    
    return 0;
}