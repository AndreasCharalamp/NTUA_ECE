#include <iostream>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>
#include <chrono>

using namespace std::chrono;

using namespace std;
#define LL long long int
#define FOR(i,k,n,j) for(long long int i=k;i<n;i+=j)
#define MAXN 1000000


LL parent[MAXN+2];
LL a[MAXN+2];
LL edges[1000002][3];
LL size[MAXN+2];


void initialize(LL n)
{
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

LL find(LL v) {
    if (v != parent[v])
        parent[v] = find(parent[v]);
    return parent[v];
}


void _union(LL a, LL b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (size[a] < size[b]){
        	LL t = a;
        	a = b;
        	b = t;
        }
        parent[b] = a;
        size[a] += size[b];
    }
}
int main()
{


//	auto start = high_resolution_clock::now();
//	ofstream out ("example.txt");
//	ifstream myfile ("input33.txt");

    LL n,m;
    scanf("%lld %lld",&n,&m);
    FOR(ii, 0, n, 1) {
    	scanf("%lld",&a[ii]);
        a[ii]--;
    }

    FOR(ii,0,m,1){
        LL x,y,z;
        scanf("%lld %lld %lld",&x,&y,&z);
        edges[ii][0]=z;
        edges[ii][1]=x-1;
        edges[ii][2]=y-1;
    }
    if(m<100001){
    	qsort(edges, m, sizeof(*edges),
    	        [](const void *arg1, const void *arg2)->int
    	        {
    	            int const *lhs = static_cast<int const*>(arg1);
    	            int const *rhs = static_cast<int const*>(arg2);
    	            return (lhs[0] < rhs[0]) ? -1
    	                :  ((rhs[0] < lhs[0]) ? 1
    	                :  (lhs[1] < rhs[1] ? -1
    	                :  ((rhs[1] < lhs[1] ? 1 : 0))));
    	        });
    }
    initialize(n);
//    auto stop = high_resolution_clock::now();
    LL index = 0;
    bool done = false;
    LL answer = -1;
    FOR(i,0,m,1){
        //cout << edges [m-1-dummy][2]<< endl;
    	//cout << find(index) <<endl;
        _union(edges[m-1-i][1], edges[m-1-i][2]);
        //cout << find(index) << " " << find(a[index]) << " " << find(1) <<endl;
        LL w = find(index);
        LL q = find(a[index]);
        while(find(index) == find(a[index]) ){
            if (index == n-1){
            	done = true;
                break;
            }
            index++;
        }
        answer = edges[m-1-i][0];
        if(done){
        	break;
        }
        //cout << answer << endl;
    }

    // Get ending timepoint
    //auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to
    // get durarion. To cast it to proper unit
    // use duration cast method
//    auto duration = duration_cast<microseconds>(stop - start);
//
//    out << "Time taken by function: "
//         << duration.count() << " microseconds" << endl;
    cout << answer << endl;
    return 0;
}
