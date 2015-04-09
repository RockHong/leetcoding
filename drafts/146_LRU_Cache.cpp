/*
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 */

#include "gtest/gtest.h"
#include <iostream>

using namespace std;

struct Node {
    int key;
    int value;
    struct Node *prev;
    struct Node *next;

    Node():key(-1),value(0),prev(NULL),next(NULL) {}
};

class LRUCache{
public:
    LRUCache(int capacity):_capacity(capacity),_size(0),_head(NULL),_tail(NULL) {
        _table = new Node[_capacity];
    }

    ~LRUCache() {
        delete[] _table;
    }
    
    int get(int key) {
        int hash = key % _capacity;
        int next = hash;
        do {
            if (_table[next].key == key) {
                updateLRU(&(_table[next]));
                return _table[next].value;
            }
            ++next;
        } while (next % _capacity != hash);

        return -1;    
    }
    
    void set(int key, int value) {
        int hash = key % _capacity;
        if (_table[hash].key == -1) {
            _table[hash].key = key;
            _table[hash].value = value;
            ++_size;
            addToLRU(&(_table[hash]));
        } else if (_size == _capacity) {
            Node *slot = removeInLRU();
            slot->key = key;
            slot->value = value;
            addToLRU(slot);
        } else {
            int next = ++hash;
            while (_table[next].key != -1) {
                ++next;
            }
            _table[next].key = key;
            _table[next].value = value;
            ++_size;
            addToLRU(&(_table[next]));
        }
    }

    void printHash() {
        cout <<"hash content:" <<endl;
        for (int i = 0; i < _capacity; ++i) {
            cout <<_table[i].key <<"=>" <<_table[i].value <<", ";
        }
        cout <<endl;
    }

    void printLRU() {
        cout <<"LRU content:" <<endl;
        Node *n = _head;
        while (n != NULL) {
            cout <<n->key <<", ";
            n = n->next;
        }
        cout <<endl;
    }

private:
    void addToLRU(Node *node) {
        if (_head == NULL) {
            _head = _tail = node;
            node->prev = node->next = NULL;
        } else {
            _head->prev = node;
            node->next = _head;
            _head = node;
        }
    }

    void updateLRU(Node *node) {
        if (_head == _tail || _head == node) {
            return;
        } else if (_tail == node) {
            Node *n = removeInLRU();
            addToLRU(n);
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            addToLRU(node);
        }
    }

    Node * removeInLRU() {
        Node *node = NULL;
        if (_tail == _head) {
            node = _tail;
            _tail = _head = NULL;
            return node;
        } else {
            node = _tail;
            _tail->prev->next = NULL;
            _tail = _tail->prev;
        }
        return node;
    }

private:
    int _capacity;
    int _size;
    Node *_table;
    Node *_head;
    Node *_tail;
};


// tests begin
TEST(Problem146Test, Test1) {
    LRUCache c(1);
    c.printHash();
    c.printLRU();
    EXPECT_EQ(-1, c.get(999));
    c.set(666, 123);
    c.printHash();
    c.printLRU();
    EXPECT_EQ(123, c.get(666));
    c.set(555, 321);
    c.printHash();
    c.printLRU();
    EXPECT_EQ(321, c.get(555));

    // TODO: test 1) hash collision 2) get 3) set
    LRUCache c2(2);

    LRUCache c5(5);
}
