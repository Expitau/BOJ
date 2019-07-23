#include <cstdio>
#include <cstring>
using namespace std;
char str[505];
int main(){
	while(1){
		scanf(" %[^\n]s", str);
		if(!strcmp(str, "END")) break;
		int len = strlen(str);
		for(int i=len-1; i>=0; i--) printf("%c", str[i]);
		printf("\n");
	}
	return 0;
}
