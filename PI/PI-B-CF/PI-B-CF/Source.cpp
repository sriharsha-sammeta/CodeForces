#include<iostream>
#include<map>

using namespace std;

int main(){

	int N;
	char inout;
	int regNum;
	
	map<int,int>input;
	int roomSize = 0;
	int tempRoomSize = 0;
	cin >> N;
	while (N-- != 0){
		cin >> inout >> regNum;

		if (inout == '+'){
			input.insert(pair<int, int>(regNum, 1));
						
			tempRoomSize++;
			
		}
		else{
			if (input.find(regNum) == input.end()){				
				roomSize++;
			}
			else{
				tempRoomSize--;
				input.erase(regNum);
			}
			
		}
		if (tempRoomSize > roomSize)
			roomSize++;
		
	}
	cout << roomSize << endl;
	return 0;
}