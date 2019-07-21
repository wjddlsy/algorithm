#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
bool decision(vector<int>& position, long long dist) {
    int installed=0;
    long long limit=-1;
    for(auto &pos:position){
        if(limit<=pos) {
            ++installed;
            limit=pos+dist;
        }
    }
    return installed>=C;
}

double optimize(vector<int>& position) {
    long long lo=0, hi=1000000000;
    while(lo<hi) {
        long long mid=(lo+hi)/2;
        if(decision(position, mid)) {
            lo=mid+1;
        }
        else {
            hi=mid;
        }
    }
    return lo-1;
}
int main() {
    cin>>N>>C;
    vector<int> position(N);
    for(auto &pos:position) {
        cin>>pos;
    }
    sort(position.begin(), position.end());
    cout<<optimize(position);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}