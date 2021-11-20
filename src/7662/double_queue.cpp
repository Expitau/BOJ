#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

// Heap
typedef struct _Heap{
	ll * arr;
	int size;
	int isMax;
}Heap;

Heap * new_heap(int isMax){
	Heap * H = (Heap *)malloc(sizeof(Heap));
	H->arr = (ll *)malloc(sizeof(ll)*1000010);
	H->isMax = isMax;
	H->size = 0;
	return H;
}

void free_heap(Heap * H){
	free(H->arr);
	free(H);
}

void Insert_heap(Heap * hp, ll num){

	int isMax = hp->isMax;
	int pos = ++(hp->size);

	hp->arr[pos] = num;
	
	while(pos != 1){
		int next_pos = pos/2;

		if(hp->arr[next_pos] < hp->arr[pos] == isMax){
			ll temp = hp->arr[next_pos];
			hp->arr[next_pos] = hp->arr[pos];
			hp->arr[pos] = temp;
		}else break;
		pos = next_pos;
	}
}

void Delete_heap(Heap * hp){
	if(hp->size == 0) return;

	int isMax = hp->isMax;
	int size = --(hp->size); // size dim

	hp->arr[1] = hp->arr[size+1];
	hp->arr[size+1] = 0;

	int pos = 1;
	while(pos*2 <= size){
		int next_pos = pos*2;
		if(next_pos+1 <= size && hp->arr[next_pos] < hp->arr[next_pos+1] == isMax)
			next_pos = next_pos + 1;

		if(hp->arr[next_pos] > hp->arr[pos] == isMax){
			ll temp = hp->arr[next_pos];
			hp->arr[next_pos] = hp->arr[pos];
			hp->arr[pos] = temp;
		}else break;

		pos = next_pos;
	}
}

void Clear_buff(Heap * hp, Heap * buff){
	while(hp->size > 0 && buff->size > 0 && hp->arr[1] == buff->arr[1]){
		Delete_heap(hp);
		Delete_heap(buff);
	}
}

int main(){
	int T;

	scanf("%d", &T);

	while(T--){
		Heap * Max_heap = new_heap(1), * Max_buff = new_heap(1);
		Heap * Min_heap = new_heap(0), * Min_buff = new_heap(0);

		int k;
		scanf("%d", &k);
		while(k--){
			char ch;
			ll num;
			scanf(" %c %lld", &ch, &num);
			
			if(ch == 'I'){
				Insert_heap(Max_heap, num);
				Insert_heap(Min_heap, num); 
			}else{ // ch == 'D'
				if(num == 1){
					if(Max_heap->size > 0){
						Insert_heap(Min_buff, Max_heap->arr[1]);
						Delete_heap(Max_heap);
					}
				}else{ // num == -1
					if(Min_heap->size > 0){
						Insert_heap(Max_buff, Min_heap->arr[1]);
						Delete_heap(Min_heap);
					}
				}
			}
			Clear_buff(Max_heap, Max_buff);
			Clear_buff(Min_heap, Min_buff);
		}
		if(Max_heap->size)
			printf("%lld %lld\n", Max_heap->arr[1], Min_heap->arr[1]);
		else
			printf("EMPTY\n");

		free_heap(Max_heap); free_heap(Max_buff);
		free_heap(Min_heap); free_heap(Min_buff);
	}
	return 0;
}
