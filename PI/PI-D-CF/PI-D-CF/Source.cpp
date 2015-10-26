#include<iostream>
#include<set>

#define tr(A,it) for(auto it=A.begin();it!=A.end();it++)



using namespace std;
typedef pair<int, int>pii;
typedef set<pii> spii;

int a, k, n;
int maxNumberOfShips = 0;

set<pii> myset;

unsigned int numberOfShipsInRegion(int L, int R){
	if (a != -1){
		return (R - L + 2) / (a + 1);
	}
	return 0;
}

bool shoot(int &x){

	auto it = myset.lower_bound(pii(x, -1));


	maxNumberOfShips -= numberOfShipsInRegion(it->second, it->first);
	if (it->second <= x - 1){
		myset.insert(pii(x - 1, it->second));
		maxNumberOfShips += numberOfShipsInRegion(it->second, x - 1);
	}
	if (x + 1 <= it->first){
		myset.insert(pii(it->first, x + 1));
		maxNumberOfShips += numberOfShipsInRegion(x + 1, it->first);
	}
	myset.erase(it);


	if (maxNumberOfShips < k){
		return false;
	}
	return true;
}

int main(){
	int  m;
	cin >> n >> k >> a>>m;
	maxNumberOfShips = (n + 1) / (a + 1);
	myset.insert(pair<int, int>(n, 1));
	int input = 0;

	for (int i = 0; i < m; i++){
		cin >> input;
		if (!shoot(input)){
			cout << (i+1) <<endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}