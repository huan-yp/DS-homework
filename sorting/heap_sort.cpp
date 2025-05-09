#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int a[20];
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    auto access = [&a](int x){
        while(x!=1){
            if(a[x] > a[x >> 1]){
                swap(a[x], a[x >> 1]);
            }
            x >>= 1;
        }
    };
    auto put = [&](int x, int len){
        while((x << 1) <= len){
            int next=x;
            if(a[x << 1] > a[x]){
                swap(a[x << 1], a[x]);
                next = x << 1;
            }
            if( (x << 1) + 1 <= len && a[x] < a[(x << 1) + 1]){
                swap(a[(x << 1) + 1], a[x]);
                next = (x << 1) + 1;
            }
            if(next == x){
                break;
            }
            x = next;
        }
    };

    for(int i=n; i>=1; i--){
        access(i);
    }
    for(int i=n; i>=1; i--){
        swap(a[1], a[i]);
        put(1, i - 1);
    }
    for(int i=1; i<=n; i++){
        cout << a[i] << " ";
    }
    return 0;
}