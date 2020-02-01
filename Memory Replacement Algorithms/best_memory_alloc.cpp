#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, sz;
	cout << "Enter number of partitions: ";
	cin >> n;
	int part[n], sum=0;
	cout << "Enter total memory size: ";
	cin >> sz;
	cout << "Enter the partitions: " << endl;;
	for(int i=0; i<n; i++) {
		cin >> part[i];
		sum += part[i];
	}
	if(sum > sz) {
		cout << "Error!! you have exceede the memory size" << endl;
		exit(0);
	}
	int pn;
	cout << "Number of processes: ";
	cin >> pn;
	int pro[pn];
	cout << "Enter the process requirement" << endl;
	for(int i=0; i<pn; i++) {
		cin >> pro[i];
	}
	int ind = -1, diff;
	int acc[pn];
	int partal[n]={};
	for(int i=0; i<pn; i++) {
		ind = -1;
		diff = 10000;
		for(int j=0; j<n; j++) {
			if(part[j]-pro[i]>=0 && part[j]-pro[i]<diff && partal[j]==0) {
				ind = j;
				diff = part[j]-pro[i];
			}
		}
		if(ind>=0) {
			partal[ind] = 1;
		}
		acc[i] = ind;
	}

	for(int i=0; i<pn; i++) {
		if(acc[i] != -1)
			cout << " Process " << i << ": "<< acc[i] << endl;
		else
			cout << " Process " << i << ": "<< "Wait" << endl;
	}
	return 0;
}