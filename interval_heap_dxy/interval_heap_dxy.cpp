#include <bits/stdc++.h>
using namespace std;
#define re int

struct interval_heap {
    int val[2]; //[1,MAXINT],value of node(val[0]->left_value, val[1]->right_value). 0 represent empty.
    void init(){
        val[0]=val[1]=0;
    }
};

interval_heap a[2000005];
/*
a is the arry of inerval_heap.
node i's son : leftson = i*2, rightson = i*2+1
node i's father : floor(i/2)
*/

int tot;//the last not full node

void heap_swap(int &x,int &y) {
    if(x>y)swap(x,y);
}

void insert_element(int x) {

    int now=tot,k=0;
    if(a[now].val[k]==0) {
        a[now].val[k]=x; //left_son ins
    }
    else { // right_son ins
        a[now].val[1]=x;
        if(a[now].val[0]>a[now].val[1]) swap(a[now].val[0],a[now].val[1]);
        else k=1;
        tot++;a[tot].init();
    }

    while(now!=1) {
        //cout<<a[now].val[k]<<" "<<a[now].val[k^1]<<" "<<k<<" "<<now<<endl;
        if(k==0)heap_swap(a[now].val[k],a[now/2].val[k^1]);
        //cout<<a[now].val[k]<<" "<<a[now/2].val[k]<<endl;
        heap_swap(a[now].val[1],a[now/2].val[1]); //right_value swap
        heap_swap(a[now/2].val[0],a[now].val[0]); //left_value swap
        now/=2;
    }
    //cout<<a[1].val[1]<<endl;
}

void remove_min() {

    int now=tot,l,r;
    if(a[now].val[0]==0)tot--,now--;

    if(tot==1) { // corner case
        if(a[1].val[1]==0) {
            a[1].val[0]=0;return;
        }
        a[1].val[0]=a[1].val[1];
        a[1].val[1]=0;return;
    }
    
    a[1].val[0]=a[now].val[0];
    if(a[now].val[1]) //right_value exsist
        a[now].val[0]=a[now].val[1],a[now].val[1]=0;
    else a[now].val[0]=0;

    now=1;
    heap_swap(a[now].val[0],a[now].val[1]);
    while(23333) { // maintain heap structure
        l=now<<1;r=now<<1|1;
        if(a[l].val[0]==0)break;
        if(a[r].val[0]==0){
            heap_swap(a[now].val[0],a[l].val[0]);
            if(a[l].val[1])heap_swap(a[l].val[0],a[l].val[1]);
            break;
        }
        if(a[l].val[0]<a[r].val[0]) {
            if(a[now].val[0]<=a[l].val[0])break;
            swap(a[now].val[0],a[l].val[0]);
            now=l;
        }
        else {
            if(a[now].val[0]<=a[r].val[0])break;
            swap(a[now].val[0],a[r].val[0]);
            now=r;
        }
        heap_swap(a[now].val[0],a[now].val[1]);
    }
}

//nearly the same as remove_min
void remove_max() {

    int now=tot,l,r;
    if(a[now].val[0]==0){
        if(now==2){
            a[1].val[1]=0;tot--;return;
        }
        else {
            a[1].val[1]=a[now-1].val[1];
            a[now-1].val[1]=0;
            tot--;
        }
    }
    else {
        a[1].val[1]=a[now].val[0];
        a[now].val[0]=0;
        if(now==1){
            a[now].val[1]=0;return;
        }
    }

    now=1;
    heap_swap(a[now].val[0],a[now].val[1]);
    while(23333) {
        l=now<<1;r=now<<1|1;
        if(a[l].val[1]==0)break;
        if(a[r].val[1]==0){
            heap_swap(a[l].val[1],a[now].val[1]);
            heap_swap(a[l].val[0],a[l].val[1]);
            break;
        }
        if(a[l].val[1]>a[r].val[1]) {
            if(a[now].val[1]>=a[l].val[1])break;
            swap(a[l].val[1],a[now].val[1]);
            now=l;
        }
        else {
            if(a[now].val[1]>=a[r].val[1])break;
            swap(a[r].val[1],a[now].val[1]);
            now=r;
        }
        heap_swap(a[now].val[0],a[now].val[1]);
    }
}

int val[2000005];
void init(int n) {
    tot=1; // node 1 is the root of heap.
    a[1].init();
    for(re i=1;i<=n;i++) {
        scanf("%d",val+i);
    }
    sort(val+1,val+n+1); // can do or not. in order to minimize the number of swap left_value and right_value.

    for(re i=1;i<=n/2;i++) {
        insert_element(val[i]);
        if(n-i!=i)insert_element(val[n-i]);
    }
}

// the function main is just for test on luogu P3378.
int main() {
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    int n;scanf("%d",&n);
    init(0);
    int t,x;
    while(n--){
        scanf("%d",&t);
        if(t==1){
            scanf("%d",&x);
            insert_element(x);
        }
        if(t==2){
            printf("%d\n",a[1].val[0]);
        }
        if(t==3){
            remove_min();
        }
        if(t==4){
            printf("%d\n", max(a[1].val[1], a[1].val[0]));
        }
        if(t==5){
            remove_max();
        }
    }
    return 0;
}
// can solve https://www.luogu.com.cn/problem/P3378