#include <iostream>
#include <algorithm>
#include <vector>
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

class Node{
public:
  int cnt;
  Node * next[2];

  Node(int _cnt, Node *_l, Node *_r){
    cnt = _cnt; next[0] = _l; next[1] = _r;
  }

  ~Node(){
    if(next[0] != nullptr) delete next[0];
    if(next[1] != nullptr) delete next[1];
  }
};

Node * tri;

void add(int x){
  Node * head = tri;
  for(int i=0; i<=30; i++){
    int now = (bool)(x&(1<<(30-i)));
    if(head->next[now] == nullptr){
      head->next[now] = new Node(0, nullptr, nullptr);
    }
    head->next[now]->cnt++;
    head = head->next[now];
  }
}

void remove(int x){
  Node * head = tri;
  for(int i=0; i<=30; i++){
    int now = (bool)(x&(1<<(30-i)));

    if(head->next[now] == nullptr) break;

    head->next[now]->cnt--;

    if(head->next[now]->cnt == 0){
      delete head->next[now];
      head->next[now] = nullptr;
      break;
    }
    
    head = head->next[now];
  }
}

int query(int x){
  Node * head = tri;

  int res = 0;
  for(int i=0; i<=30; i++){
    int now = (bool)(x&(1<<(30-i)));
    if(head->next[1-now] != nullptr){
      res += (1<<(30-i));
      head = head->next[1-now];
    }else{
      head = head->next[now];
    }
  }
  return res;
}

void solve(){
  int q, m, x;
  cin >> q;
  while(q--){
    cin >> m >> x;
    switch(m){
    case 1: 
      add(x); break;
    case 2:
      remove(x); break;
    case 3:
      cout << query(x) << "\n"; break;
    default:
      break;
    }
  }
}

int main(){
  FASTIO;
  tri = new Node(0, nullptr, nullptr);
  add(0);

  solve();

  return 0;
}