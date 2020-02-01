#include <bits/stdc++.h>
int main() {
	int n;
	printf("Number of requests: ");
	scanf("%d", &n);
	int req[n+1];
	printf("Enter the cylinder numbers\n");
	int i, total=0;
	for(i=1; i<=n; i++)
		scanf("%d", &req[i]);
	printf("Where is the head initially? ");
	scanf("%d", &req[0]);
	for(i=0; i<n; i++){
		printf("R/W moving from cylinder %d to cylinder %d\n", req[i], req[i+1]);
		int time=abs(req[i+1]-req[i]);
		printf("Seek is %d\n\n", time);
		total+=time;
	}
	printf("Total seek time is %d\n", total);
	float ave=(float)total/n;
	printf("Average seeking time is %f\n", ave);
	return 0;
}
