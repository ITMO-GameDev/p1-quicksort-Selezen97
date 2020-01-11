#ifndef LAB3_DICTIONARY_HPP
#define LAB3_DICTIONARY_HPP
#include<iostream>

using namespace std;
template <typename K, typename V>
class Dictionary final {
private:
    struct Node
    {
        K key;
        V value;
        int height;//высота поддерева с корнем в данном узле
        Node *left;
        Node *right;
    };

    Node* root;

    void makeEmpty(Node* t)
    {
        if(t == nullptr)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    };

    Node* insert(const K& k, const V& v, Node* t)
    {
        if(t == nullptr)
        {
            t = new Node;
            t->key = k;
            t->value = v;
            t->height = 0;
            t->left = t->right = nullptr;
        }
        else if(k < t->key)
        {
            t->left = insert(k, v , t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(k < t->left->key)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(k > t->key)
        {
            t->right = insert(k,v, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(k > t->right->key)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right))+1;
        return t;
    };

    Node* singleRightRotate(Node* &t)
    {
        Node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;
    };

    Node* singleLeftRotate(Node* &t)
    {
        Node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(t->right), t->height)+1 ;
        return u;
    };

    Node* doubleLeftRotate(Node* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    };

    Node* doubleRightRotate(Node* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    };

    Node* findMin(Node* t)
    {
        if(t == nullptr)
            return nullptr;
        else if(t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    };

    Node* findMax(Node* t)
    {
        if(t == nullptr)
            return nullptr;
        else if(t->right == nullptr)
            return t;
        else
            return findMax(t->right);
    };

    Node* remove(const K& x, Node* t)
    {
        Node* temp;

        // Element not found
        if(t == nullptr)
            return nullptr;

            // Searching for element
        else if(x < t->key)
            t->left = remove(x, t->left);
        else if(x > t->key)
            t->right = remove(x, t->right);

            // Element found
            // With 2 children
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->key = temp->key;
            t->right = remove(t->key, t->right);
        }
            // With one or zero child
        else
        {
            temp = t;
            if(t->left == nullptr)
                t = t->right;
            else if(t->right == nullptr)
                t = t->left;
            delete temp;
        }
        if(t == nullptr)
            return t;

        t->height = max(height(t->left), height(t->right))+1;

        // If node is unbalanced
        // If left node is deleted, right case
        if(height(t->left) - height(t->right) == 2)
        {
            // right right case
            if(height(t->left->left) - height(t->left->right) == 1)
                return singleLeftRotate(t);
                // right left case
            else
                return doubleLeftRotate(t);
        }
            // If right node is deleted, left case
        else if(height(t->right) - height(t->left) == 2)
        {
            // left left case
            if(height(t->right->right) - height(t->right->left) == 1)
                return singleRightRotate(t);
                // left right case
            else
                return doubleRightRotate(t);
        }
        return t;
    };

    int height(Node* t)
    {
        return (t == nullptr ? -1 : t->height);
    };

    int getBalance(Node* t)
    {
        if(t == nullptr)
            return 0;
        else
            return height(t->left) - height(t->right);
    };

    void inorder(Node* t)
    {
        if(t == nullptr)
            return;
        inorder(t->left);
        cout << t->key << " ";
        inorder(t->right);
    };
public:
    Dictionary()
    {
        root= nullptr;
    };

    void put(const K& x, const V& y)
    {
        root = insert(x, y, root);
    };
    void remove(const K& x)
    {
        root = remove(x, root);
    };
    void display()
    {
        inorder(root);
        cout << endl;
    };
};


#endif //LAB3_DICTIONARY_HPP
