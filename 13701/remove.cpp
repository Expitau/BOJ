#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;
vector<pii> arr;

int main(){
	int temp;
	for(int i=0; scanf("%d", &temp) != EOF; i++)
		arr.push_back({temp, i});

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end(), [](pii & A, pii & B)->bool{return A.first == B.first;}), arr.end());
	sort(arr.begin(), arr.end(), [](pii & A, pii &B)->bool{return A.second < B.second;});
	for(auto it : arr)
		printf("%d ", it.first);

	return 0;
}

