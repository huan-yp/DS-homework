#include <bits/stdc++.h>

using namespace std;

template<typename T>
T find_pivot(T *a, int first, int last){
    int mid = (first + last) / 2;
    if(a[first] > a[mid]){
        if(a[mid] > a[last]){

        }else if(a[first] > a[last]){
            swap(a[mid], a[last]);
        }else{
            swap(a[first], a[mid]);
        }
    }else{
        if(a[first] > a[last]){
            swap(a[first], a[mid]);
        }else if(a[mid] > a[last]){
            swap(a[mid], a[last]);
        }
    }
    return a[mid];
}

template<typename T>
int find_next(T pivot, T *a, int low){
    int i = low;
    while(a[i] < pivot){
        i++;
    }
    return i;
}

template<typename T>
int find_previous(T pivot, T *a, int high){
    int i = high;
    while(a[i] > pivot){
        i--;
    }
    return i;
}

template<typename T>
void insertion_sort(T *a, int first, int last){
    for(int i=first+1; i<last; i++){
        for(int j=first; j<i; j++){
            if(a[i] < a[j]){
                int temp = a[i];
                memmove(a + j + 1, a + j, (i - j) * sizeof(T));
                a[j] = temp;
                break;
            }
        }
    }
}

template<typename T>
void quicksort(T *a, int first, int last){
    // cerr << "S:" << first << ' ' << last << '\n';
    if(last - first < 6){
        return insertion_sort(a, first, last);
    }
    T pivot = find_pivot(a, first, last - 1); // last SUB 1
    int low = first, high = last - 1; // last SUB 1
    do{
        int nxt = find_next(pivot, a, low);
        int prv = find_previous(pivot, a, high);
        if(nxt < prv){
            swap(a[nxt], a[prv]);
            low = nxt + 1, high = prv - 1;
        }
        else{
            quicksort(a, first, nxt); // the right end is open so it should be nxt
            quicksort(a, nxt, last);
            break;
        }
    }while(1);

}

template<typename T>
void quicksort_p(T *a, int first, int last){
    // cerr << "S:" << first << ' ' << last << '\n';
    if(last - first < 6){
        return insertion_sort(a, first, last);
    }
    T pivot = find_pivot(a, first, last - 1); // last SUB 1
    int low = first - 1, high = last; // last SUB 1
    while(low < high){
        low++, high--;
        while(a[low] < pivot){
            low++;
        }
        while(a[high] > pivot){
            high--;
        }
        if(low < high){
            swap(a[low], a[high]);
        }
    }
    quicksort(a, first, low);
    quicksort(a, low, last);
}

void test_ins(){
    int a[10] = {5, 2, 3, 1, 4, 6, 7, 8, 9, 0};
    insertion_sort(a, 0, 10);
    for(int i=0; i<10; i++){
        cout << a[i] << " ";
    }
}

int main(){
    // test_ins();
    // quicksort(a, 0, 10);
    // for(int i=0; i<10; i++){
    //     cout << a[i] << " ";
    // }
    // int a[10] =  {5, 2, 3, 1, 4, 6, 7, 8, 9, 0};
    // for(int i=1;i<=100;i++){
    //     cerr <<"T: " << i << '\n';
    //     quicksort_p(a, 0, 10);
    //     for(int i=0; i<10; i++){
    //         if(a[i] != i){
    //             cout << "Error\n";
    //             return 0;
    //         }
    //     }
    //     random_shuffle(a, a + 10);
    // }

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    quicksort_p(a.data(), 0, n);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;
}