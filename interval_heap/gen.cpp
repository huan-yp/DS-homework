#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int rand(int l, int r){
    return rng() % (r - l + 1) + l;
}

int sz = 0;
multiset<int> s;

void remove_max(){
    s.erase(s.find(*s.rbegin()));
    sz--;
}

void remove_min(){
    s.erase(s.begin());
    sz--;
}

int get_max(){
    return *s.rbegin();
}

int get_min(){
    return *s.begin();
}

void insert_element(int x){
    s.insert(x);
    sz++;
}

int main(){
    ofstream fout("data.in");
    ofstream fans("data.ans");
    int k = 1000;
    int level = rand(1, 10);
    fout << k << endl;
    while(k--){
        int op = rand(1, 5), val = rand(1, 1 << level);
        if(op == 1 || sz == 0){
            fout << 1 << " " << val << endl;
            insert_element(val);
            continue;
        }
        if(op == 2){
            fout << op << endl;
            fans << get_min() << endl;
        }
        if(op == 3){
            fout << op << endl;
            remove_min();
        }
        if(op == 4){
            fout << op << endl;
            fans << get_max() << endl;
        }
        if(op == 5){
            fout << op << endl;
            remove_max();
        }
    }
}

