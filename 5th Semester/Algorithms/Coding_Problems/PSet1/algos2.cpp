#include <iostream>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <chrono>
#include <fstream>
#include <iomanip>

using namespace std::chrono;
using namespace std;
#define LL long long int
#define FOR(i,k,n,j) for(long long int i=k;i<n;i+=j)
#define MAXN 20002
#define MAXK 1000002

LL leftSums[MAXK];
LL s[MAXN];
LL a[MAXN];

int main(){


//	auto start = high_resolution_clock::now();
//	ofstream out ("example.txt");
//	ifstream fin ("input25.txt");
    LL n,k;
    cin >> n >> k;
    FOR(ii, 0, n, 1) {
        cin >> a[ii];
        if(ii==0)s[0]=a[0];
        else{
        	s[ii]=s[ii-1]+a[ii];
        }
    }
    FOR(ii,0,MAXK+1,1){
    	leftSums[ii] = MAXN;
    }
    leftSums[0]=0;
    LL answer =n;
    if(a[0]==k){
        cout << 1 << endl;
    }
    else{
        leftSums[a[0]] = 1;
        FOR(i,1,n,1){
        	if(s[i]<= k){
        		if(leftSums[s[i]]>i+1)leftSums[s[i]]=i+1;
        	}
            FOR(j,0,i,1){
            	if(s[i]-s[j]<=k){
            		if(leftSums[s[i]-s[j]]>i-j)leftSums[s[i]-s[j]]=i-j;
            	}
            	//cout << i << " " << j << " LeftSums " << leftSums[s[i]-s[j]]<<endl;
            }
            FOR(j,i+1,n,1){
            	//cout << "ok2 " << j  << endl;
            	LL rightSum = s[j]-s[i];
            	if (i == 2){
            		//cout << rightSum << endl;
            	}
            	if(rightSum > k) break;
            	else{
            		//cout << answer << "  "<< j-i << " "  << leftSums[k-rightSum]<<endl;
            		answer = min(answer , j-i + leftSums[k - rightSum]);

            	}
            }
        }
        if (answer == n && s[n-1]!=k)answer = -1;
        cout << answer << endl;
    }
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);
//
//        out << "Time taken by function: "
//             << duration.count() << " microseconds" << endl;

    //cout << "kalispera " << m[2][2]<<endl;
    return 0;
}