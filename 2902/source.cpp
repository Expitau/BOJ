#include <cstdio>
#include <cstring>
char str[150];

int main(){
	scanf("%s", str);
	printf("%c", str[0]);
	for(int i=1; i<strlen(str); i++){
		if(str[i] == '-')
			printf("%c", str[i+1]);
	}
	return 0;
}
