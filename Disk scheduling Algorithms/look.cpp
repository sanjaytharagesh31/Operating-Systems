#include <bits/stdc++.h>
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
sort(arr, arr+n);
int pos;
for(int i=0; i<n; i++) {
	if(head>=arr[i])
		pos=i;
}
int r=n-pos-1;
int l=n-r;
cout << pos << " " <<l << " " << r<<endl;
if(l<=r){
int diff;
for(int i=pos; i>=0; i--) {
	diff=abs(head-arr[i]);
	printf("R/W moving from cylinder %d to cylinder %d\n", head, arr[i]);
	printf("Seek is %d\n\n", diff);
	head = arr[i];
	total += diff;
}
for(int i=pos+1; i<n; i++) {
	diff=abs(head-arr[i]);
	printf("R/W moving from cylinder %d to cylinder %d\n", head, arr[i]);
	printf("Seek is %d\n\n", diff);	
	head = arr[i];
	total += diff;
}
}
else {
int diff;

for(int i=pos+1; i<n; i++) {
	diff=abs(head-arr[i]);
	printf("R/W moving from cylinder %d to cylinder %d\n", head, arr[i]);
	printf("Seek is %d\n\n", diff);	
	head = arr[i];
	total += diff;
}
for(int i=pos; i>=0; i--) {
	diff=abs(head-arr[i]);
	printf("R/W moving from cylinder %d to cylinder %d\n", head, arr[i]);
	printf("Seek is %d\n\n", diff);
	head = arr[i];
	total += diff;
}
}
printf("Total seek time is %d\n", total);
float ave=(float)total/n;
printf("Average seeking time is %f\n", ave);
return 0;
}
