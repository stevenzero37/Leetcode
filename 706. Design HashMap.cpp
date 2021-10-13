#include <iostream>
#include <map>

class hashMap {
private:
    std::map<int, int> table;

public:
    
    void put (int key, int value) {
        if (table.find(key) == table.end())
            table.insert(std::pair<int, int> (key, value));
        else
            table.at(key) = value;
    }
    
    void printList() {
        std::map<int, int>::iterator it;
        for(it=table.begin();it!=table.end();++it)
            std::cout << it->first << " " << it->second << std::endl;
    }
    
    int get(int key) {
        if (table.find(key) == table.end())
            return -1;
        else
            return table[key];
    }
    
    void erase(int key) {
        if(table.find(key) != table.end())
            table.erase(key);
    }
};


int main() {
    hashMap *example = new hashMap();
    
    example->put(1,1);
    example->put(1,2);
    std::cout << example->get(1) << std::endl;
    example->printList();
}