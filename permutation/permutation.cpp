#include<bits/stdc++.h>
using namespace std;
mt19937 m_rand(time(0));
int Rand(int l, int r){
    return m_rand()%(r-l+1)+l;
}
const int ct = 100;
void gen_1(int n){
    static int r=0;
    vector<int> a(n);
    int cnt = 0;
    for(int i=0;i<n;i++){
        bool flag;
        do{
            flag = false;
            a[i] = Rand(1, n);
            for(int j=0;j<i;j++){
                cnt ++;
                if(a[i] == a[j]){
                    flag = true;
                }
            }
        }while(flag);
        // cout<<a[i]<<' ';
    }
    if(++r==ct)cout<<"oper:"<<1. * cnt / n / n <<' ', r=0;
}
void gen_2(int n){
    static int r=0;
    vector<int> a(n), used(n, 0);
    int cnt=0;
    for(int i=0;i<n;i++){
        do{
            cnt ++;
            a[i] = Rand(1, n);
        }while(used[a[i]-1]);
        used[a[i]-1] = true;
    }
    if(++r==ct)cout<<"oper:"<<1. * cnt / n <<' ', r=0;
}
void gen_3(int n){
    vector<int> a(n);
    for(int i=0;i<n;i++){
        a[i] = i+1;
    }
    for(int i=0;i<n;i++){
        swap(a[i], a[Rand(0, n-1)]);
    }
    // cout<<"oper:"<<2*n<<' ';
}
void time_run(int n, function<void(int)> func){
    auto start = chrono::high_resolution_clock::now();
    for(int _=0;_<ct;_++){
        func(n);
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Elapsed time: " << elapsed.count() << " s\n";
}
int main()
{
    int cases[][10] = {
        {250, 500, 1000, 2000},
        {25000, 50000, 100000, 200000, 400000, 800000},
        {100000, 200000, 400000, 800000, 1600000, 3200000, 6400000}
    };
    function<void(int)> funcs[3] = {gen_1, gen_2, gen_3};
    for(int i=1;i<=1;i++){
        cout << "Func Case:" << i << endl;
        for(int j=0;j<6&&cases[i-1][j];j++){
            cout << "n = " << cases[i-1][j] << ',';
            time_run(cases[i-1][j], funcs[i-1]);
        }
        cout << endl << endl;
    }
    return 0;
}