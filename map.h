#ifndef MAP_H
#define MAP_H

#include <stdexcept> // For std::runtime_error

template<typename KeyType, typename ValueType>
class Map {
private:
    struct Node {
        KeyType key;
        ValueType value;
        Node* next;

        Node(const KeyType& k, const ValueType& v) : key(k), value(v), next(nullptr) {}
    };

    Node* head;

public:
    Map() : head(nullptr) {}

    ~Map() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(const KeyType& key, const ValueType& value) {
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
    }

    // Non-const version of operator[]
    ValueType& operator[](const KeyType& key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        throw std::runtime_error("Key not found in map");
    }

    // Const version of operator[]
    const ValueType& operator[](const KeyType& key) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        throw std::runtime_error("Key not found in map");
    }

    bool contains(const KeyType& key) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

#endif // MAP_H
