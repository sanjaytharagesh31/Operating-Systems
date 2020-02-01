#include <bits/stdc++.h>
using namespace std;
double ans = INT64_MAX;
int n_j, n_p;
int job[100000]={};
int pro[100000]={};
int load[100000]={};
double total = 10000000.0;

void func(int pos) {
    if(pos < n_j) {
        for(int i=0; i<n_p; i++) {
            load[i] += job[pos];
            func(pos+1);
            load[i] -= job[pos];
        }
    }
    else {
        double time = 0.0;
        for(int i=0; i<n_p; i++)
            time = max(time, (double)load[i]/pro[i]);
        total = min(total, time);
    }
}

int main() {

    cout << "Number of jobs: ";
    cin >> n_j;
    for(int i=0; i<n_j; i++)
        cin >> job[i];
    cout << "Number of processors: ";
    cin >> n_p;
    for(int i=0; i<n_p; i++)
        cin >> pro[i];
    func(0);
    cout << total << endl;
    return 0;
}