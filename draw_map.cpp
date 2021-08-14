#include <bits/stdc++.h>
using namespace std;

void print(int *o, string **map, int size){
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

/*int compD(int *start, int x, int y, 
string **map, string wall, string blank,
int size, int i, bool change);

int compU(int *start, int x, int y, 
string **map, string wall, string blank,
int size, int i, bool change);

int compR(int *start, int x, int y, 
string **map, string wall, string blank,
int size, int i, bool change);

int compL(int *start, int x, int y, 
string **map, string wall, string blank,
int size, int i, bool change);*/

int compD(int x, int y, 
string **map, string wall, string blank,
int size, int i =0){
  int walls = 0;
  if(i>size) {return 0;}
  
  
  if(map[y][x]==blank&&i>0){
   //cout<<map[y][x];
   //cout<<i<<' '<<x<<' '<<y<<"\n";
    return 0;
  }
  //cout<<i<<' '<<x<<' '<<y<<"\n";
  //if(map[y][x]=="x ")map[y][x]="o ";
  //cout<<map[y][x];
  vector<int> temp={0};
  i++;
  if(y+1<size&&x>0&&x<size-1){
    temp.insert(temp.end(), compD(x, y+1, map,
      wall, blank, size, i));
  }
  if(x-1>-1&&y+1<size&&x-1>0&&x-1<size-1){
    temp.insert(temp.end(), compD(x-1, y+1, map,
      wall, blank, size, i));
  }
  if(x+1<size&&y+1<size&&x+1>0&&x+1<size-1){
    temp.insert(temp.end(),compD(x+1, y+1, map,
      wall, blank, size, i));
  }
  //cout<<out<<'\n';
  sort(temp.begin(), temp.end());
  return temp[temp.size()-1]+1;
}

int compU(int x, int y, 
string **map, string wall, string blank,
int size, int i = 0){
  int walls = 0;
  if(i>size) {return 0;}
  if(map[y][x]==blank&&i>0){
    return 0;
  }
  vector<int> temp={0};
  i++;
  if(y-1>-1&&x>0&&x<size-1){
    temp.insert(temp.end(), compU(x, y-1, map,
      wall, blank, size, i));
  }
  if(x-1>-1&&y-1>-1&&x>0&&x<size-1){
    temp.insert(temp.end(), compU(x-1, y-1, map,
      wall, blank, size, i));
  }
  if(x+1<size&&y-1>-1&&x>0&&x<size-1){
    temp.insert(temp.end(), compU(x+1, y-1, map,
      wall, blank, size, i));
  }
  sort(temp.begin(), temp.end());
  return temp[temp.size()-1]+1;
}

int compL(int x, int y, 
string **map, string wall, string blank,
int size, int i =0){
  int walls = 0;
  if(i>size) {return 0;}
  if(map[y][x]==blank&&i>0){
    return 0;
  }
  vector<int> temp={0};
  i++;
  if(x-1<size&&y>0&&y<size-1){
    temp.insert(temp.end(), compL(x-1, y, map,
      wall, blank, size, i));
  }
  if(x-1>-1&&y+1<size&&y>0&&y<size-1){
    temp.insert(temp.end(), compL(x-1, y+1, map,
      wall, blank, size, i));
  }
  if(x-1<size&&y-1>-1&&y>0&&y<size-1){
    temp.insert(temp.end(), compL(x-1, y-1, map,
      wall, blank, size, i));
  }
  sort(temp.begin(), temp.end());
  return temp[temp.size()-1]+1;
}

int compR(int x, int y, 
string **map, string wall, string blank,
int size, int i=0){
  int walls = 0;
  if(i>size) {return 0;}
  if(map[y][x]==blank&&i>0){
    return 0;
  }
  vector<int> temp={0};
  i++;
  if(x+1<size&&y>0&&y<size-1){
    temp.insert(temp.end(), compD(x, y+1, map,
      wall, blank, size, i));
  }
  if(x+1>-1&&y+1<size&&y>0&&y<size-1){
    temp.insert(temp.end(), compD(x-1, y+1, map,
      wall, blank, size, i));
  }
  if(x+1<size&&y-1>-1&&y>0&&y<size-1){
    temp.insert(temp.end(), compD(x+1, y+1, map,
      wall, blank, size, i));
  }
  sort(temp.begin(), temp.end());
  return temp[temp.size()-1]+1;
}

/*int compD(int *start, int x, int y, 
string **map, string wall, string blank,
int size, int i=0, bool change = false){
  int walls = 0, out = 0;
  if(i>1000) {return 0;}
  if(map[y][x]==blank&&i>0){
    if(start[0]==x&&start[1]==y){
      return 1;
    }else{
      return 0;
    }
  }
  i++;
  if(y+1<size){
    out += compD(start, x, y+1, map,
      wall, blank, size, i);
      if(map[y+1][x]!=blank){
        walls++;
      }
    //if(out>0) return out;
  }
  if(x-1>-1&&y+1<size){
    out += compD(start, x-1, y+1, map,
      wall, blank, size, i);
      if(map[y+1][x-1]!=blank){
        walls++;
      }
    //if(out>0) return out;
  }
  if(x+1<size&&y+1<size){
    out += compD(start, x+1, y+1, map,
      wall, blank, size, i);
      if(map[y+1][x+1]!=blank){
        walls++;
      }
    //if(out>0) return out;
  }
  if(walls==0&&!change){
    out += compL(start, x, y, map,
      wall, blank, size, i, true);
    out += compR(start, x, y, map,
      wall, blank, size, i, true);
  }
  return out;
}
  
int compL(int *start, int x, int y, 
string **map, string wall, string blank,
int size, int i=0, bool change = false){
  int walls = 0, out = 0;
  if(i>1000) {return 0;}
  if(map[y][x]==blank&&i>0){
    if(start[0]==x&&start[1]==y){
      return 1;
    }else{
      return 0;
    }
  }
  i++;
  if(x-1>-1){
    out += compL(start, x-1, y, map,
      wall, blank, size, i);
      if(map[y][x-1]!=blank){
        walls++;
      }
    //if(out>0) return out;
  }
  if(x-1>-1&&y-1>-1){
    out += compL(start, x-1, y-1, map,
      wall, blank, size, i);
      if(map[y-1][x-1]!=blank){
        walls++;
      }
    //if(out>0) return out;
  }
  if(x-1>-1&&y+1<size){
    out += compL(start, x-1, y+1, map,
      wall, blank, size, i);
      if(map[y+1][x-1]!=blank){
        walls++;
      }
    //if(out>0) return out;
  }
  if(walls==0&&!change){
    out += compU(start, x, y, map,
      wall, blank, size, i, true);
    out += compD(start, x, y, map,
      wall, blank, size, i, true);
  }
  return out;
}

int compR(int *start, int x, int y, 
string **map, string wall, string blank,
int size, int i=0, bool change = false){
  int walls = 0, out = 0;
  if(i>1000) {return 0;}
  if(map[y][x]==blank&&i>0){
    if(start[0]==x&&start[1]==y){
      return 1;
    }else{
      return 0;
    }
  }
  i++;
  if(x+1<size){
    out += compR(start, x+1, y, map,
      wall, blank, size, i);
      if(map[y][x+1]!=blank){
        walls++;
      }
    //if(out>0) return out;
  }
  if(x+1<size&&y-1>-1){
    out += compR(start, x+1, y-1, map,
      wall, blank, size, i);
      if(map[y-1][x+1]!=blank){
        walls++;
      }
    //if(out>0) return out;
  }
  if(x+1<size&&y+1<size){
    out += compR(start, x+1, y+1, map,
      wall, blank, size, i);
      if(map[y+1][x+1]!=blank){
        walls++;
      }
    //if(out>0) return out;
  }
  if(walls==0&&!change){
    out += compU(start, x, y, map,
      wall, blank, size, i, true);
    out += compD(start, x, y, map,
      wall, blank, size, i, true);
  }
  return out;
}
int compU(int *start, int x, int y, 
string **map, string wall, string blank,
int size, int i=0, bool change = false){
  int walls = 0, out = 0;
  if(i>1000) {return 0;}
  if(map[y][x]==blank&&i>0){
    if(start[0]==x&&start[1]==y){
      return 1;
    }else{
      return 0;
    }
  }
  i++;
  if(y-1>-1){
    out += compU(start, x, y-1, map,
      wall, blank, size, i);
      if(map[y-1][x]!=blank){
        walls++;
      }
    //if(out>0) return out;
  }
  if(x-1>-1&&y-1>-1){
    out += compU(start, x-1, y-1, map,
      wall, blank, size, i);
      if(map[y-1][x-1]!=blank){
        walls++;
      }
    //if(out>0) return out;
  }
  if(x+1<size&&y-1>-1){
    out += compU(start, x+1, y-1, map,
      wall, blank, size, i);
      if(map[y-1][x+1]!=blank){
        walls++;
      }
    //if(out>0) return out;
  }
  if(walls==0&&!change){
    out += compL(start, x, y, map,
      wall, blank, size, i, true);
    out += compR(start, x, y, map,
      wall, blank, size, i, true);
  }
  return out;
}*/
/*int comp(int *start, int x, int y, string **map,
string wall, string blank, int size, int i=0,
int limit = 0){
  if(limit>size*size*2){return 0;}
  int out=0;
  limit++;
  
  if(map[y][x]==blank){
    return 0;
  }
  if(start[0]==x&&start[1]==y){
    return 0;
  }
  if(i==0)i++;
  if(x-1>-1){
    out += comp(start, x-1, y, map,
wall, blank, size, i, limit);
    if(out>0) return out;
  }
  if(x+1<size){
    out += comp(start, x+1, y, map,
wall, blank, size, i, limit);
    if(out>0) return out;
  }
  if(y-1>-1){
    out += comp(start, x, y-1, map,
wall, blank, size, i, limit);
    if(out>0) return out;
  }
  if(y+1<size){
    out += comp(start, x, y+1, map,
wall, blank, size, i, limit);
    if(out>0) return out;
  }
  if(x-1>-1&&y-1>-1){
    out += comp(start, x-1, y-1, map,
wall, blank, size, i, limit);
    if(out>0) return out;
  }
  if(x-1>-1&&y+1<size){
    out += comp(start, x-1, y+1, map,
wall, blank, size, i, limit);
    if(out>0) return out;
  }
  if(x+1<size&&y-1>-1){
    out += comp(start, x+1, y-1, map,
wall, blank, size, i, limit);
    if(out>0) return out;
  }
  if(x+1<size&&y+1<size){
    out += comp(start, x+1, y+1, map,
wall, blank, size, i, limit);
    if(out>0) return out;
  }
  return out;
}*/
  
void fill(int x, int y, string **map, int size,
string blank){
  bool h =  (y<size-1&&y>0);
  bool v =  (x<size-1&&x>0);
  if(h&&x-1 > 0&&map[y][x-1]!=blank){
    map[y][x-1]=blank;
    fill(x-1, y, map, size, blank);
  }
  if(h&&x+1<size-1&&map[y][x+1]!=blank){
    map[y][x+1]=blank;
    fill(x+1, y, map, size, blank);
  }
  if(v&&y-1>0&&map[y-1][x]!=blank){
    map[y-1][x]=blank;
    fill(x, y-1, map, size, blank);
  }
  if(v&&y+1<size-1&&map[y+1][x]!=blank){
    map[y+1][x]=blank;
    fill(x, y+1, map, size, blank);
  }
}

int fill2(int size, string **map,int *o,
string wall, string blank,
 int i = 0, int limit = 0){
  if(i>0.32*((size-2)*(size-2))
     || limit>((size-2)*(size-2))*2){
    return i;
  }
  int x=1+rand()%(size-2);
  int y=1+rand()%(size-2);
  if(map[y][x] == wall){
    return 
     fill2(size, map, o, wall, blank, i, limit);
  }
  int temp = i;
  int l = x-1;
  int r = x+1;
  int d = y+1;
  int u = y-1;
  
  int round[4]={0, 1, 0, -1};
  int side[4]={1, 1, -1, -1};
  int dotA[2]={l, u};
  int dotB[2]={r, y};
  int dotC[2]={x, u};
  
  int ay=0, ax=2, bx=5, by=3, cx=1, cy=0;
  bool test = true, test2 = true;
  for(int i=0; i<8; i++){
    if(map[dotA[1]][dotA[0]]==wall&&
    map[dotB[1]][dotB[0]]==wall&&
    map[dotC[1]][dotC[0]]==blank){
      test=false;
    }
    /*if((x==0||x==size-1||y==0||y==size-1)&&
      dotA[0]>0&&dotA[1]>0&&
    dotA[0]<size-1&&dotA[1]<size-1&&
    map[dotA[1]][dotA[0]]==wall){
      test2=false;
    }*/
    
    dotA[0] += round[(ax%8)/2];
    dotA[1] += round[ay/2];
    dotB[0] += round[(bx%8)/2];
    dotB[1] += round[(by%8)/2];
    dotC[0] += side[cx%4];
    dotC[1] += side[cy%4];
    ay++; ax++; bx++; by++; cx++; cy++;
  }
  
  /*bool test = !(
  (map[u][l]==wall&&map[u][x]==blank
  &&map[y][r]==wall)||
  (map[y][l]==wall&&map[u][x]==blank
  &&map[u][r]==wall)||
  (map[u][r]==wall&&map[y][r]==blank
  &&map[d][x]==wall)||
  (map[u][x]==wall&&map[y][r]==blank
  &&map[d][r]==wall)||
  (map[d][r]==wall&&map[d][x]==blank
  &&map[y][l]==wall)||
  (map[y][r]==wall&&map[d][x]==blank
  &&map[d][l]==wall)||
  (map[d][l]==wall&&map[y][l]==blank
  &&map[u][x]==wall)||
  (map[u][l]==wall&&map[y][l]==blank
  &&map[d][x]==wall));
  */
  
  if(!
  (
  (map[u][l]==wall&&map[u][x]==blank
  &&map[u][r]==wall)||
  (map[u][r]==wall&&map[y][r]==blank
  &&map[d][r]==wall)||
  (map[d][r]==wall&&map[d][x]==blank
  &&map[d][l]==wall)||
  (map[d][l]==wall&&map[y][l]==blank
  &&map[u][l]==wall))
  &&!(
  (map[u][x]=="O ")||(map[d][x]=="O ")||
  (map[y][l]=="O ")||(map[y][r]=="O "))&&
  /*!((map[u][l]==wall&&map[d][r]==wall)||
    (map[u][r]==wall&&map[d][l]==wall))
  && */
  /*!(
  (u>0&&map[u][l]==wall&&map[u][x]==wall
  &&map[u][r]==wall)||
  (r<size-1&&map[u][r]==wall&&map[y][r]==wall
  &&map[d][r]==wall)||
  (d<size-1&&map[d][r]==wall&&map[d][x]==wall
  &&map[d][l]==wall)||
  (l>0&&map[d][l]==wall&&map[y][l]==wall
  &&map[u][l]==wall))&&*/
  !(
   (x==1&&(map[y][r]==wall||map[u][r]==wall
   ||map[d][r]==wall))||
  (x==size-2&&(map[y][l]==wall||map[u][l]==wall
   ||map[d][l]==wall))||
  (y==1&&(map[d][r]==wall||map[d][x]==wall
   ||map[d][l]==wall))||
  (y==size-2&&(map[u][r]==wall||map[u][x]==wall
   ||map[u][l]==wall)))&&
   
  !(
  (x==2&&(map[y][l]==wall||map[u][l]==wall
   ||map[d][l]==wall))||
  (x==size-3&&(map[y][r]==wall||map[u][r]==wall
   ||map[d][r]==wall))||
  (y==2&&(map[u][r]==wall||map[u][x]==wall
   ||map[u][l]==wall))||
  (y==size-3&&(map[d][r]==wall||map[d][x]==wall
   ||map[d][l]==wall)))&&
   
  test){
    /*int cv=0, ch=0;
    cv += compD(x, y, map, wall, blank, size);
    //cout<<cv<<"\n";
    ch += compL(x, y, map, wall, blank, size);
    cv += compU(x, y, map, wall, blank, size);
    ch += compR(x, y, map, wall, blank, size);
    if(cv-2<size&&ch-2<size){*/
      map[y][x] = wall;
      i++;
    
    
    /*print(o, map, size);
    cout<<'\n';
    int yu;
    cin>>yu;*/
  }
  /*int jk[2]={x, y};
  int out=0;
  out += compD(jk, x, y, map, wall, blank, size);
  out += compL(jk, x, y, map, wall, blank, size);
  out += compU(jk, x, y, map, wall, blank, size);
  out += compR(jk, x, y, map, wall, blank, size);
  if(out==0){
    map[y][x] = wall;
    i++;
    /*print(o, map, size);
    cout<<'\n';
    int yu;
    cin>>yu;
  }*/
  if(temp == i){
    limit++;
  }
  fill2(size, map, o, wall, blank, i, limit);
}

int fill3(string **map, int size, string wall, 
string c, int max, int i=0){
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
  int o1= rand()% 2;
  int o2= abs(o1-1);
  o[o1] = rand()%size;
  if(o[o1]<(size-1)&&o[o1]>0){
    o[o2]=(rand()%2)*(size-1);
  }else{
    o[o2] = 1+rand()%(size-2);
  }
  string wall = "| ", blank = ". ";
  string **map;
  map = new string *[size];
  for(int i = 0; i<size; i++){
    map[i] = new string [size];
  }
  for(int i = 0; i<size; i++){
    for(int j = 0; j<size; j++){
      if(o[0]==j&&o[1]==i){
        map[i][j]="O ";
      }else{
        map[i][j]=wall;
      }
    }
  }
  fill(o[0], o[1], map, size, blank);
  int i = fill2(size, map, o, wall, blank);
  int c = fill3(map, size, wall, "x ", 
  0.1*pow(size-2,2));
  fill3(map, size, wall, "P ", 1);
  fill3(map, size, wall, "M ", 1);
  print(o, map, size);
  cout<<"i: "<<i<<"\n";
  cout<<"c: "<<c<<"\n";
  }
}
  
