#include <cstdio>
#include <random>
#include <chrono>
using namespace std;

int main(){
	auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
	mt19937 mt_rand(seed);
	if(mt_rand()%2) printf("Korea");
	else printf("Yonsei");
	return 0;
}
