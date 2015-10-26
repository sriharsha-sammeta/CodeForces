#include<iostream>
#include<vector>

using namespace std;

long long int absol(long long x){
	return (x < 0) ? -x : x;
}

long long int findDist(long long int &x, long long int &y){
	
	return absol(x - y);
}


int main(){
	vector<long long int> input;
	int N;
	int ip;
	cin >> N;
	input.reserve(N);
	while (N-- != 0){
		cin >> ip;
		input.push_back(ip);
	}

	long long int min1 = 0,min2=0, max1 = 0,max2=0;
	for (int i = 0; i < int(input.size()); i++){
		min1 = 0;
		min2 = 0;
		if (i != 0){
			min1 = findDist(input[i], input[i - 1]);
			if (min2 == 0)
				min2 = min1;
		}
		if (i != input.size() - 1){
			min2 = findDist(input[i], input[i + 1]);
			if (min1 == 0)
				min1 = min2;
		}
		
		max1 = findDist(input[i], *(input.begin()));
		max2 = findDist(input[i], *(input.end() - 1));

		cout << ((min1 < min2) ? min1 : min2) <<" "<<((max1>max2) ? max1 : max2) << endl;
	}

	return 0;
}