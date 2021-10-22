#include <bits/stdc++.h>
using namespace std;

void print(int *o, vector<vector<string>> map, int size){
  for(int i = 0; i<size; i++){
    for(int j = 0; j<size; j++){
      if(o[0]==j&&o[1]==i){
        cout<<map[i][j];
      }else{
        cout<<map[i][j];
      }
    }
    cout<<"\n";
  }
}

//FILL BLANKS ---------------------
void fill(int x, int y, 
vector<vector<string>>& map, int size,
string wall){
  for(int i = 0; i < size; i++) {
    map[0][i] = wall;
    map[size-1][i] = wall;
    map[i][0] = wall;
    map[i][size-1] = wall;
  }
}

//FILL WALLS ----------------------
tuple<int, int> fil(int size, 
vector<vector<string>>& map,int *o,
string wall, string blank){
  int tempts = 0;
  int limit = 0;
  int i = 0;
  int wallLimit = 0.32*((size-2)*(size-2));
  int tempLimit = ((size-2)*(size-2))*2;
  while(!(i > wallLimit || limit > tempLimit)){
       
    tempts++;
    int x=1+rand()%(size-2);
    int y=1+rand()%(size-2);
    
    if(map[y][x] == wall){
      continue;
    }
    
    int temp = i;
    
    int l = x-1;
    int r = x+1;
    int d = y+1;
    int u = y-1;
    
    bool lw = l==0;
    bool uw = u==0;
    bool rw = r==size-1;
    bool dw = d==size-1;
  
    bool vv = !(
    (map[u][l]==wall&&map[d][r]==wall) ||
    (map[d][l]==wall&&map[u][r]==wall)
    ); 
    bool cc = !(
    (map[u][x]==wall&&map[d][x]==wall)||
    (map[y][l]==wall&&map[y][r]==wall)
    );
  
    bool vc = !(
    (map[u][l]==wall&&map[u][x]==blank
    &&map[y][r]==wall
    &&!((rw)&&(uw || lw))
    )||
  
    (map[y][l]==wall&&map[u][x]==blank
    &&map[u][r]==wall
    &&!((lw)&&(uw || rw))
    )||
  
    (map[u][r]==wall&&map[y][r]==blank
    &&map[d][x]==wall
    &&!((dw)&&(uw || rw))
    )||
  
    (map[u][x]==wall&&map[y][r]==blank
    &&map[d][r]==wall
    &&!((uw)&&(dw || rw))
    )||
  
    (map[d][r]==wall&&map[d][x]==blank
    &&map[y][l]==wall
    &&!((lw)&&(dw || rw))
    )||
  
    (map[y][r]==wall&&map[d][x]==blank
    &&map[d][l]==wall
    &&!((rw)&&(dw || lw))
    )||
  
    (map[d][l]==wall&&map[y][l]==blank
    &&map[u][x]==wall
    &&!((uw)&&(dw || lw))
    )||
  
    (map[u][l]==wall&&map[y][l]==blank
    &&map[d][x]==wall
    &&!((dw)&&(uw || lw))
    ));
  
    bool uu = !(
    (map[u][l]==wall&&map[u][x]==blank
    &&map[u][r]==wall
    &&!((lw && rw)||(uw))
    )||
  
    (map[u][r]==wall&&map[y][r]==blank
    &&map[d][r]==wall
    &&!((uw && dw)||(rw))
    )||
  
    (map[d][r]==wall&&map[d][x]==blank
    &&map[d][l]==wall
    &&!((lw && rw)||(dw))
    )||
  
    (map[d][l]==wall&&map[y][l]==blank
    &&map[u][l]==wall
    &&!((dw && uw)||(lw))
    ));
    
    bool oo = !(
    (map[u][x]=="O ")||(map[d][x]=="O ")||
    (map[y][l]=="O ")||(map[y][r]=="O "));
    
    if(vv && uu && cc && vc && oo) {
      map[y][x] = wall;
      i++;
    }
    
    if(temp == i){
      limit++;
    }
  }
  
  return make_tuple(i, tempts);
}

//FILL CHARCTERS -----------
int fill3(vector<vector<string>>& map, int size, 
string wall, string c, int max, int i=0){
  int x = 1 + rand()%(size-2);
  int y = 1 + rand()%(size-2); 
  if(map[y][x]==wall){
    return fill3(map, size, wall, c, max, i);
  }
  i++;
  map[y][x]=c;
  if(i<max){
    return fill3(map, size, wall, c, max, i);
  }
  return i;
}

int main(){
  srand (time(NULL));
  int o[2];
  int size;
//---------[LOOP]-----------
  while(true){
  cout<<"insert size\n";
  cin>>size;
  if(size<4){
    cout<<"insira um número maior q 3\n";
    continue;
  }
  
  o[0] = 1 + (rand()%(size -2));
  o[1] = 1 + (rand()%(size -2));
  
  if(rand()%2){
    o[0]=(rand()%2)*(size-1);
  }else{
    o[1]=(rand()%2)*(size-1);
  }
  
  string wall = "| ", blank = ". ";
  
  vector<vector<string>> map(size,
  vector<string>(size, ". "));
  
  fill(o[0], o[1], map, size, wall);
  
  map[o[0]][o[1]] = "O ";
  
  int i;
  int tempts;
  tie(i, tempts) = fil(size, map, o, wall, blank);
  int c = fill3(map, size, wall, "x ", 
  0.1*pow(size-2,2));
  fill3(map, size, wall, "P ", 1);
  fill3(map, size, wall, "M ", 1);
  print(o, map, size);
  cout<<"tempts: "<<tempts<<"\n";
  cout<<"i: "<<i<<"\n";
  cout<<"c: "<<c<<"\n";
  }
}
