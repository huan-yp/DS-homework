#include <bits/stdc++.h>
using namespace std;

class IntervalHeap {
private:
    vector<array<int, 2>> a;
    int cnt;
    bool swap_node(int son, int fa){
        // do swap if intersection
        son--, fa--; // real index
        if(a[son][0] < a[fa][0])
            return swap(a[son][0], a[fa][0]), true;
        
        // max value cross are two cases
        if(is_full_node(son + 1)){
            if(a[son][1] > a[fa][1])
                return swap(a[son][1], a[fa][1]), true;
        }
        else{
            if(a[son][0] > a[fa][1])
                return swap(a[son][0], a[fa][1]), true;
        }
        return false;
    }
    bool exist(int x){
        return x <= (cnt + 1) / 2;
    }
    bool is_last_node(int rk){
        return rk == (cnt + 1) / 2;
    }
    bool is_full_node(int rk){
        return !is_last_node(rk) || cnt % 2 == 0;
    }
    void access(int rk){
        // call for any node
        // access to root to make the path validated
        while(rk != 1){
            swap_node(rk, rk >> 1);
            rk >>= 1;
        }
    }
    int get_min(int rk){
        return a[rk - 1][0];
    }
    int get_max(int rk){
        return is_full_node(rk) ? a[rk - 1][1] : a[rk - 1][0];
    }
    void set_min(int rk, int val){
        a[rk - 1][0] = val;
    }
    void set_max(int rk, int val){
        a[rk - 1][1] = val;
    }
    void validate_node(int rk){
        // DO NOT CALL THIS FOR THE LAST NODE
        // when replace the value from the last node, we need to validate it
        rk--;
        if(a[rk][0] > a[rk][1])
            swap(a[rk][0], a[rk][1]);
    }
    int pop_back(){
        int rk = (cnt + 1) / 2;
        // perserve val before do delete because get_min depends on cnt
        if(cnt % 2){
            int val = get_min(rk);
            return cnt--, a.pop_back(), val;
        }
        else{
            int val = get_max(rk);
            return cnt--, val;
        }
    }
public:
    IntervalHeap(){
        cnt = 0;
    }
    void Init(const vector<int> &other){
        a.clear(); cnt=0;
        for(auto x:other)
            insert_element(x);
    }
    void remove_min(){
        int rk=1;
        while(exist(rk << 1)){
            if(exist(rk << 1 | 1) && get_min(rk << 1 | 1) < get_min(rk << 1)){
                rk = rk << 1 | 1;
            }else{
                rk <<= 1;
            }
            set_min(rk >> 1, get_min(rk));
        }
        if(is_last_node(rk)){
            int val = pop_back();
            if(cnt % 2) // if it's interval, max_value will be set as the min_value
                set_min(rk, val);
        }
        else{
            set_min(rk, pop_back());
            validate_node(rk);
            access(rk);
        }
        
    }
    void remove_max(){
        int rk=1;
        while(exist(rk << 1)){
            if(exist(rk << 1 | 1) && get_max(rk << 1 | 1) > get_max(rk << 1)){
                rk = rk << 1 | 1;
            }else{
                rk <<= 1;
            }
            set_max(rk >> 1, get_max(rk));
        }
        if(is_last_node(rk)){
            pop_back(); // max_value is moved(pop_back it safely either it's interval or single value)
        }
        else{
            // normal case
            set_max(rk, pop_back());
            validate_node(rk); // validate interval
            access(rk);
        }
    }
    void insert_element(int x){
        if(++cnt % 2)a.push_back({0, 0}); // expand
        int rk = (cnt + 1) / 2 - 1; // get real index
        if(cnt % 2){
            a[rk][0] = x;
        }
        else{
            a[rk][1] = max(a[rk][0], x);
            a[rk][0] = min(a[rk][0], x);
        }
        access(rk + 1);
    }
    int get_min(){
        return get_min(1);
    }
    int get_max(){
        return get_max(1);
    }
    void validate(){
        // only for debug
        for(int i=1; exist(i); i++){
            if(exist(i << 1)){
                if(get_min(i) > get_min(i << 1) || get_max(i) < get_max(i << 1))
                    cout << "error" << endl;
            }
            if(exist(i << 1 | 1)){
                if(get_max(i) < get_max(i << 1 | 1) || get_min(i) > get_min(i << 1 | 1))
                    cout << "error" << endl;
            }
        }
    }
};

int main(){
    int n;
    IntervalHeap heap;
    cin >> n;
    while(n--){
        int op, x;
        cin >> op;
        if(op == 1){
            cin >> x;
            heap.insert_element(x);
        }
        if(op == 2){
            cout << heap.get_min() << endl;
        }
        if(op == 3){
            heap.remove_min();
        }
        if(op == 4){
            cout << heap.get_max() << endl;
        }
        if(op == 5){
            heap.remove_max();
        }
    }
    return 0;
}