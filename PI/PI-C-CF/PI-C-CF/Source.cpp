#include<iostream>
#include<vector>
#include<map>
#define sz(A) int(A.size())

using namespace std;

int main(){
	long long int N, K;
	cin >> N >> K;
	vector<long long int>input(N);
	map<long long int, int>Al;
	map<long long int, int>Ar;
	long long int current = 0;
	for (int i = 0; i < sz(input); i++){
		cin >> input[i];
		Ar[input[i]]++;
	}
	current = 0;
	long long int leftCount = 0;
	long long int rightCount = 0;
	long long int totalCount = 0;
	for (int i = 0; i < sz(input); i++){		
		leftCount = 0;
		rightCount = 0;

		Ar[input[i]]--;
		if (Ar[input[i]] == 0)
			Ar.erase(input[i]);
		
		if (input[i] % K == 0 && Al.find(input[i] / K) != Al.end() && Ar.find(input[i]*K)!=Ar.end()){
			leftCount += Al[input[i] / K];
			rightCount += Ar[input[i] * K];
			totalCount += (leftCount*rightCount);
		}
		Al[input[i]]++;
	}
	cout << totalCount << endl;
	return 0;
}