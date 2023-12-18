#include <bits/stdc++.h> 
using namespace std;

int assignHoles(int mices[], int holes[], int n, int m){
	if(n != m){
		return -1;
	}
	sort(mices, mices+n);
	sort(holes, holes+m);
	
	int max = 0;
	for(int i = 0; i<n; ++i){
		if (max < abs(mices[i] - holes[i]))
			max = abs(mices[i] - holes[i]);
	}
	return max;
}
int main(){
	int mices[] = {4,2,5};
	int holes[] = {-5,-8,2};
	int n = sizeof(mices) / sizeof(mices[0]);
	int m = sizeof(holes) / sizeof(holes[0]);
	int minTime = assignHoles(mices,holes,n,m);
	cout << "Minimum time taken is " << minTime;

}
