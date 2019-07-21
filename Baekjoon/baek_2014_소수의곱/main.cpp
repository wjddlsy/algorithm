#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

const int INF=(1<<31)-1;
int N, K;
vector<long long> primes;
priority_queue<int> pq;
unordered_set<int> us;

void solve(long long n) {
    for(auto &prime:primes) {
        long long next=n*prime;
        if(next>INF)
            return;
        if(pq.size()==N) {
            if(pq.top()<next)
                return;
            if(us.find(next)==us.end())
                pq.pop();
        }
        if(us.find(next)==us.end()) {
            pq.push(next);
            us.insert(next);
            solve(next);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>K>>N;
    primes.resize(K);
    for(auto &prime:primes) {
        cin>>prime;
    }
    solve(1);
    cout<<pq.top();
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}