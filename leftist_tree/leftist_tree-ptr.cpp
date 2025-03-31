#include "bits/stdc++.h"

using namespace std;

class Heap{
private:
    class Node{
    public:
        unique_ptr<Node> son[2];
        int val, dist;
        Node(int val=0){
            this->son[0]=nullptr;
            this->son[1]=nullptr;
            this->val=val;
            this->dist=0;
        }
    };
    unique_ptr<Node> root;
public:
    Heap(unique_ptr<Node> &&root){
        this->root=move(root);
    }
    int top() const{
        return root->val;
    }
    void push(int x){
        this->merge(unique_ptr<Node>(new Node(x)));
    }
    Heap& merge(Heap &&other){
        if(root==nullptr){
            root=move(other.root);
        }
        else if(other.root==nullptr){

        }
        else{
            if(root->val > other.root->val){
                swap(this->root, other.root);
            }
            root->son[1] = move(Heap(move(root->son[1])).merge(move(other.root)).root);
            if(root->son[0] == nullptr || 
                (root->son[1] != nullptr && root->son[0]->dist < root->son[1]->dist)){
                swap(root->son[0], root->son[1]);
            }
            if(root->son[1] != nullptr)
                root->dist = root->son[1]->dist + 1;
            else
                root->dist = 0;
        }
        return *this;
    }
    int pop(){
        this->root = move(Heap(move(root->son[0])).merge(move(root->son[1])).root);
        // 当 merge 函数返回时, 它返回的是临时对象的左值引用, 临时对象在生命周期内可以被左值引用.
        return top();
    }
};

int main(){
    Heap h(nullptr);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int tp, x;
        cin >> tp;
        switch (tp){
            case 1:
                cin >> x;
                h.push(x);
                break;
            case 2:
                cout << h.top() << endl;
                break;
            case 3:
                h.pop();
                break;
            default:
                throw "unsupported operation";
        }
    }
    return 0;
}