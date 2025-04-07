#include <bits/stdc++.h>

using namespace std;

// string down_right="└";
// string right="-";
// string down="|";

class AVL{
    static int count;
    class AVL_NODE{
    public:
        unique_ptr<AVL_NODE> left, right;
        int val, size; // val of cur node; size of subtree
        AVL_NODE(int val): val(val), size(1){left = nullptr; right = nullptr;}
        void make_tree(int h){
            if(h == 0)return ;
            if(h == 1){
                left = make_unique<AVL_NODE>(count++);
                return ;
            }
            left = make_unique<AVL_NODE>(count++);
            left->make_tree(h - 1);
            right = make_unique<AVL_NODE>(count++);
            right->make_tree(h - 2);
        }
        void print() const{
            cout << "node: " << val << ", left: " << (left == nullptr? -1 : left->val) << ", right: " << (right == nullptr? -1 : right->val) << endl;
            if(left != nullptr)left->print();
            if(right != nullptr)right->print();
        }
    };
    unique_ptr<AVL_NODE> root;
public:
    AVL(){
        root = nullptr;
    }
    AVL(int h){
        // construct avl tree with fewest nodes of height h
        root = make_unique<AVL_NODE>(count++);
        root->make_tree(h);
    }
    bool insert_val(int x); // insert x into the tree, if exist, return false and do nothing, else true
    bool delete_val(int x); // return true if deleted, false if not exist
    int get_size() const; // get size of the tree
    int kth_smallest(int k) const; // find kth smallest element in the tree, if not exist, throw exception
    // void print(int x, int y) const{ // rows: x, cols: y
    void print() const{ 
        // print the tree
        // visualizing is so time-consuming, I give up
        root->print();
    }
};

int AVL::count = 0;

int main(){
    AVL T(3);
    T.print();
    return 0;
}