#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, blk=3;
	cout << "Number of page requests: ";
	cin >> n;
	int req[n], fault[n];
	cout << "Enter the  sequence of page requests" << endl;
	for(int i=0; i<n; i++) {
		cin >> req[i];
		fault[i]=0; //0 is nofault, 1 is page fault
	}	
	int arr[blk][n];
	for(int i=0; i<blk; i++)
		for(int j=0; j<n; j++)
			arr[i][j] = -1;

	queue<int> q; //push pop front 
	for(int j=0; j<n; j++) {
		if(j==0) {
			arr[0][j] = req[j];
			q.push(req[j]);
			fault[j] = 1;
		}
		else {
			int flg=0;
			for(int i=0; i<blk; i++) {
				if(arr[i][j-1] == req[j])
					flg = 1;
			}
			if(flg==1) {
				for(int i=0; i<blk; i++) {
					arr[i][j] = arr[i][j-1];
				}			
			}
			else {
				fault[j] = 1;
				if(q.size()==3) {
					int gh;
					int f = q.front();
					q.pop();
					q.push(req[j]);
					for(int i=0; i<blk; i++) {
						if(arr[i][j-1] == f) {
							gh = i;
							break;
						}
					}
					//cout << "G:" << gh << "F:" << f << endl;
					for(int i=0; i<blk; i++) {
						if(i!=gh) {
							arr[i][j] = arr[i][j-1];
						}
						else {
							arr[i][j] = req[j];
						}
					}
				}
				else {
					for(int i=0; i<blk; i++) {
						if(arr[i][j-1]!=-1)
							arr[i][j] = arr[i][j-1];
						else {
							arr[i][j] = req[j];
							q.push(req[j]);
							break;
						}
					}
				}
			}
		}
		
	}
	for (int i = 0; i < n; ++i)
	{
		cout << i << "\t";
	}
	cout << endl;
	for(int i=0; i<blk; i++) {
		for(int j=0; j<n; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}int pl=0;
	for(int i=0; i<n; i++) {
		cout << fault[i] << "\t";
		if(fault[i]==1)
			pl++;
	}
	cout << endl;
	cout << "Memory block size         :" << blk << endl;;
	cout << "Number of page faults     :" << pl << endl;
	cout << "Percentage of page faults :" << (float)(pl/n)*100 << "\%" << endl;

	return 0;
}