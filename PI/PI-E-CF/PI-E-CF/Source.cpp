#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<functional>

#define tr(V,it) for(auto it=V.begin();it!=V.end();it++)

using namespace std;
typedef pair<int, int>pii;
typedef vector<pii> vpii;
typedef map<int, int>mii;
typedef map<int,vpii> mvpii;

void applyDijkstraAlgo(mvpii &G, mii &shortestDistFromSource, int nameOfSource){
	priority_queue<pii,vpii,greater<pii> > pri_Q;
	if (G.find(nameOfSource) != G.end()){
		pri_Q.push(make_pair(0,nameOfSource));
	}
	while (!pri_Q.empty()){
		auto selectedNode = pri_Q.top();
		pri_Q.pop();
		if (shortestDistFromSource.find(selectedNode.second) == shortestDistFromSource.end()){
			shortestDistFromSource[selectedNode.second] = selectedNode.first;
			vpii adjacentNodes = G[selectedNode.second];
			for each ( auto adjacentNode in adjacentNodes)
			{				
				pri_Q.push(make_pair(selectedNode.first + adjacentNode.second, adjacentNode.first));
			}
		}
	}

}


int main(){
	mvpii G;
	mii shortestDistanceFromSource;
	vpii temp;

	temp.push_back(make_pair(2,2));
	temp.push_back(make_pair(3, 10));
	G[1] = temp;
	temp.clear();
	
	temp.push_back(make_pair(4, 8));
	temp.push_back(make_pair(3, 7));
	G[2] = temp;
	temp.clear();

	temp.push_back(make_pair(5, 3));
	G[3] = temp;
	temp.clear();


	temp.push_back(make_pair(5, 2));
	G[4] = temp;
	temp.clear();

	temp.push_back(make_pair(6, 1));	
	G[5] = temp;
	temp.clear();

	applyDijkstraAlgo(G, shortestDistanceFromSource, 1);

	tr(shortestDistanceFromSource, it){
		cout << it->first << " : " << it->second << endl;
	}
	return 0;
}

