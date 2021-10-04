#include <bits/stdc++.h>
using namespace std;

void printTable(string **table, int size){
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      cout<<table [i][j];
    }
    cout<<"\n";
  }
}
 
set<int> compMove(int x, int y, int size,
 string **table, bool print = true){
  vector<string> moves={"esquerda", "direita",
  "cima", "baixo"};
  set<int> i;
  if(x-1>-1&& table[y][x-1]!="| "){
    i.insert(1);
  }
  if(x+1<size&&table[y][x+1]!="| "){
    i.insert(2);
  }
  if(y-1>-1&& table[y-1][x]!="| "){
    i.insert(3);
  }
  if(y+1<size&& table[y+1][x]!="| "){
    i.insert(4);
  }
  if(print){
    for(auto temp : i){
      cout<<temp<<" "<<moves[temp-1]<<"\n";
    }
  }
  return i;
}

int move(string c, int move, int *pos,
 string **table){
  int x = pos[0], y = pos[1], out =0;
  table[y][x] = ". ";
  switch(move){
    case 3:
      if(table[y-1][x] == "x "){out = 1;}
      table[y-1][x]=c;
      pos[1] = y-1;
      break;
    case 4:
      if(table[y+1][x] == "x "){out = 1;}
      table[y+1][x]=c;
      pos[1] = y+1;
      break;
    case 1:
      if(table[y][x-1] == "x "){out = 1;}
      table[y][x-1]=c;
      pos[0] = x-1;
      break;
    case 2:
      if(table[y][x+1] == "x "){out = 1;}
      table[y][x+1]=c;
      pos[0] = x+1;
  }
  if(out == 1){
    table[pos[1]][pos[0]][0] = tolower(c[0]);
  }
  return out;
}

int moveM(int m[], int size, string **table,
int input = 0){
  if(input!=0){
    return move("M ", input, m, table);
  }
  set<int> moves =
    compMove(m[0], m[1], size, table, false);
  while(moves.find(input)==moves.end()){
    input = (rand()%4)+1;
  }
  return move("M ", input, m, table);
}

int moveMHard(int *m, int *p, int size,
string **table){
  set<int> moves = compMove(m[0], m[1], 
  size, table, false);
  if(m[0]<p[0] && moves.find(2)!=moves.end()){
    return moveM(m, size, table, 2);
  }
  if(m[0]>p[0] && moves.find(1)!=moves.end()){
    return moveM(m, size, table, 1);
  }
  if(m[1]<p[1] && moves.find(4)!=moves.end()){
    return moveM(m, size, table, 4);
  }
  if(m[1]>p[1] && moves.find(3)!=moves.end()){
    return moveM(m, size, table, 3);
  }
  return moveM(m, size, table);
}

int moveP(int *p, int size, string **table){
  int input;
  cout<<"Escolha uma direção\n";
  set<int> moves = 
    compMove(p[0], p[1], size, table);
  cin>>input;
  if(moves.find(input)!=moves.end()){
    return move(table[p[1]][p[0]], input, p, table);
  }else{
    cout<<"entrada inválida\n\
    insira entrada válida\n";
    return moveP(p, size, table);
  }
}

int main(){
  srand (time(NULL));
  string map= "\
| | | | | | | | | | \n \
| . | . . . | | M | \n \
| P . . | . . | . | \n \
| . | . | . . | . | \n \
| . . x | . . . . | \n \
| . | . . . x | . | \n \
| . . . | | . | | | \n \
| . | x . . . | . O \n \
| . . . | | . . . | \n \
| | | | | | | | | | \n ";
  int size=10, test=(size+1)*2;
  int p[2], m[2], o[2];
  int bip=0, mip=0, stun = 2;
  bool bombP = false, bombM = false;
  string **table;
  int difficulty;
  table = new string *[size];
  for(int j=0;j<size;j++){
    table[j] = new string [size];
  }
  for(int i=0;i<map.length();i+=2){
    int y=i/test, x=((i%test)/2)%10;
    if(map[i]!='\n'){
      if(map[i]=='P'){
        p[0]=x;
        p[1]=y;
      }
      if(map[i]=='O'){
        o[0]=x;
        o[1]=y;
      }
      if(map[i]=='M'){
        m[0]=x;
        m[1]=y;
      }
      table[y][x] = map.substr(i, 2);
    }
  }
  cout<<"Bem vindo ao labirinto do minotauro\n";
  cout<<"Escolha uma dificuldade\n\
1 fácil\n2 médio\n3 difícil\n";
  cin>>difficulty;
  while(p[0]!=o[0] || p[1]!=o[1]){
    if(!bombM && p[0] == m[0] && p[1] == m[1]){
      printTable(table, size);
      cout<<"Acabou meu repertório";
      return 0;
    }
    if(mip < 0) {
      bombM = false;
      table[m[1]][m[0]] = "M ";
    }
    if(bip < 0) {
      bombP = false;
      table[p[1]][p[0]] = "P ";
    }
    printTable(table, size);
    if(bombM){
      cout<<"Minotaur is stunned\n";
    }
    if(bombP){
      cout<<"You're stunned\n";
      int temp;
      cout<<"1 Ok\n";
      cin>>temp;
    }
    
    if(!bombP){
      bombP = moveP(p, size, table);
      bip = bombP*stun;
    }
    if(!bombM){if(difficulty==1){
      bombM = moveM(m, size, table);
      mip = bombM*stun;
    }
    else if(difficulty==2){
      bombM = moveM(m, size, table);
      mip = bombM*stun;
      //printTable(table, size);
      if(!bombM){
        bombM = moveM(m, size, table);
        mip = bombM*stun;
      }
    }else{
      bombM = moveMHard(m, p, size, table);
      mip = bombM*stun;
    }
    }
    mip--;
    bip--;
  }
  printTable(table, size);
  cout<<"Eu acho q tenho habilidade\n pra fazer as coisa q eu não sei";
}
