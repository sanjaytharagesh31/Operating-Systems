#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
int n;
cout<<"Enter number of requests: ";
cin>>n;
int arr[n];
cout<<"Enter the cylinders"<<endl;
for(int i=0; i<n; i++)
cin>>arr[i];
int head;
cout<<"Where is head initially: ";
cin>>head;
int total=0;
for(int i=0; i<n; i++) {
	int ind;
	int dif = 99999;
	for(int j=0; j<n; j++) {
		if(arr[j]!=-1 && dif>abs(head-arr[j])){
			dif = abs(head-arr[j]);
			ind = j;
		}
	}
	printf("R/W moving from cylinder %d to cylinder %d\n", head, arr[ind]);	
	printf("Seek is %d\n\n", dif);
	total+=dif;
	head = arr[ind];
	arr[ind]=-1;
}
printf("Total seek time is %d\n", total);
float ave=(float)total/n;
printf("Average seeking time is %f\n", ave);
return 0;
}
