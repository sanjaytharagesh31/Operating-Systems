#include <bits/stdc++.h>
using namespace std;

int main()
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
				    //
				    int check[blk];
				    for(int p=0; p<blk; p++) {
				        check[p]=arr[p][j-1];
				        //cout << "j = " << j << " " << "check " << p << " " << check[p] << endl;
				    }
				    int last=-1, cnt=0;
				    for(int p=j; p<n; p++) {
				        for(int q=0; q<blk; q++) {
				            if(req[p]==check[q]) {    
				                check[q]=-1;
				                cnt++;
				                break;
				            }
				        }
				        if(cnt == blk-1) 
				            break;
				    }
                    queue<int> newq;
                    vector<int> v;
                    while(!q.empty()) {
                        int temp = q.front();
                        q.pop();
                        int flag=0;
                        for(int d=0; d<blk; d++) {
                            if(check[d]==temp){
                                newq.push(check[d]);
                                flag = 1;
                            }
                        }
                        if(flag==0) {
                            v.push_back(temp);
                        }
                    }
                    for(int d=0; d<v.size(); d++) {
                        newq.push(v[d]);
                    }
                    q = newq;
				    //
					//else{
    					int f = q.front();
    					q.pop();
    					q.push(req[j]);
    					for(int i=0; i<blk; i++) {
    						if(arr[i][j-1] == f) {
    							gh = i;
    							break;
    						}
    					}
					//}
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
	cout << "Percentage of page faults :" << ((float)pl/n)*100 << "\%" << endl;

	return 0;
}
