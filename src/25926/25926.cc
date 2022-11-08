#include <iostream>
#include <string>

using namespace std;

string input_arr[2020];
int arr[1010][1010];
int trans_log[1010][1010], trans_sum[1010][1010];

int n, m, k;
int ANS;

/*
    1  2  3
0 : 3  5  6
3 : 0  6  5
5 : 6  0  3
6 : 5  3  0

    0 1 2
0 : 1 2 3
1 : 0 3 2
2 : 3 0 1
3 : 2 1 0
*/

int transition[4][3] = {
  {1, 2, 3}, {0, 3, 2}, {3, 0, 1}, {2, 1, 0}
};

void fill_cell(int i, int j){
  arr[i][j] = (int)(input_arr[i][j] != input_arr[n-i-1][j]) + 
              ((int)(input_arr[i][j] != input_arr[n-i-1][m-j-1]) << 1) +
              ((int)(input_arr[i][j] != input_arr[i][m-j-1]) << 2);
  
  switch(arr[i][j]){
    case 0: arr[i][j] = 0; break;
    case 3: arr[i][j] = 1; break;
    case 5: arr[i][j] = 2; break;
    case 6: arr[i][j] = 3; break;
    default: arr[i][j] = -1; break;
  }
}

void add_trans(int i, int j, int t){// [i, i+k-1]*[j, j+k-1] -> add transition.
  trans_log[i][j] ^= t;
  trans_log[i+k][j] ^= t;
  trans_log[i][j+k] ^= t;
  trans_log[i+k][j+k] ^= t;
}

void renew_trans(int i, int j){
  trans_sum[i][j] = trans_log[i][j];
  if(i != 0) trans_sum[i][j] ^= trans_sum[i-1][j];
  if(j != 0) trans_sum[i][j] ^= trans_sum[i][j-1];
  if(i != 0 && j != 0) trans_sum[i][j] ^= trans_sum[i-1][j-1];
}

void apply_trans(int i, int j, int t){
  if(t & 1) arr[i][j] = transition[arr[i][j]][0];
  if(t & 2) arr[i][j] = transition[arr[i][j]][1];
  if(t & 4) arr[i][j] = transition[arr[i][j]][2];
}

void print_status(int i, int j){
  cout << "\nstatus : " << i << " " << j << "\n\n";
  

  cout << "arr\n";
  for(int i=0; i<(n>>1); i++){
    for(int j=0; j<(m>>1); j++) cout << arr[i][j];
    cout << "\n";
  }

  cout << "\ntrans_log\n";
  for(int i=0; i<(n>>1); i++){
    for(int j=0; j<(m>>1); j++) cout << trans_log[i][j];
    cout << "\n";
  }

  cout << "\ntrans_sum\n";
  for(int i=0; i<(n>>1); i++){
    for(int j=0; j<(m>>1); j++) cout << trans_sum[i][j];
    cout << "\n";
  }
}

bool process_cell(int i, int j){
  renew_trans(i, j);
  apply_trans(i, j, trans_sum[i][j]);

  //print_status(i, j);

  if(arr[i][j] == 0) return true;
  if(i+k-1 >= (n>>1) || j+k-1 >= (m>>1)) return false;

  int trans = 1<<(arr[i][j]-1);
  apply_trans(i, j, trans);
  add_trans(i, j, trans);
  renew_trans(i, j);
  ANS++;

  return true;
}

int main(){
  cin >> n >> m >> k;

  for(int i=0; i<n; i++){
    cin >> input_arr[i];
  }
  
  for(int i=0; i<(n>>1); i++){
    for(int j=0; j<(m>>1); j++){
      fill_cell(i, j);
      if(arr[i][j] == -1 || !process_cell(i, j)){ // terminate
        cout << -1;
        return 0;
      }
    }
  }

  cout << ANS;

  return 0;
}