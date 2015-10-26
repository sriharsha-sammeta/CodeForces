#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<set>

#define mp make_pair
#define sz(A) int(A.size())


using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;

void applyDijkstraAlgorithm(const vector<vpii>&G, vi &d, const int &sourceName){
	priority_queue<pii, vpii, greater<pii>> Q;

	Q.push(mp(0, sourceName));

	while (!Q.empty()){
		pii currentNode = Q.top();
		Q.pop();
		if (currentNode.second >0 && currentNode.second <sz(d) && d[currentNode.second] < 0){
			d[currentNode.second] = currentNode.first;

			vpii adjacentNodes = G[currentNode.second];
			for (pii adjacentNode : adjacentNodes)
			{
				Q.push(mp(adjacentNode.second + currentNode.first, adjacentNode.first));
			}
		}
	}
}

void solve(){
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	vector<vpii>G1(n + 1);
	vector<vpii>G2(n + 1);
	vector<pair<int, pii> >store;
	while (m-- != 0){
		int startCity, endCity, cost;
		cin >> startCity >> endCity >> cost;
		G1[startCity].push_back(mp(endCity, cost));
		G2[endCity].push_back(mp(startCity, cost));

		store.push_back(mp(startCity, mp(endCity, cost)));
	}

	// d1 should initially have values less than 0
	vi d1(G1.size(), -1);
	applyDijkstraAlgorithm(G1, d1, s);
	vi d2(G2.size(), -1);
	applyDijkstraAlgorithm(G2, d2, t);


	for (auto it1 = store.begin(); it1 != store.end(); it1++){
		int i = it1->first;
		pii adjNode = it1->second;

		bool isPartOfShortesPath = false;
		if (d1[i] >= 0 && d2[adjNode.first] >= 0){
			isPartOfShortesPath = d1[i] + d2[adjNode.first] + adjNode.second == d1[t];
		}
		bool foundDuplicate = false;
		if (isPartOfShortesPath){
			// first edge is part of shortest path				
			for (auto it2 = store.begin(); it2 != store.end(); it2++){
				int j = it2->first;
				pii adjNode2 = it2->second;
				if (it1 != it2){
					if (d1[j] + d2[adjNode2.first] + adjNode2.second == d1[t]){
						if ((d1[j] <= d1[i] && d1[adjNode.first] <= d1[adjNode2.first]) || (d1[i] <= d1[j] && d1[adjNode2.first] <= d1[adjNode.first])){
							foundDuplicate = true;
							break;
						}
					}
				}
			}

		}
		if (isPartOfShortesPath && !foundDuplicate){
			cout << "YES" << endl;
		}
		else{
			if (d1[i] >= 0 && d2[adjNode.first] >= 0){
				int repairCost = d1[i] + d2[adjNode.first] + adjNode.second - d1[t] + 1;
				if (adjNode.second - repairCost > 0){
					cout << "CAN " << repairCost << endl;
				}
				else{
					cout << "NO" << endl;
				}
			}
			else{
				cout << "NO" << endl;
			}
		}
	}

}

int main(){
	solve();
	return 0;
}