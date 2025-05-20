#include <iostream>
#include <vector>
#include <cstring>


using namespace std;

void displays(int graph[20][20], int size, char templeter[20]);


int main(){
int size = 2;
char templeter[20];
  for(int x = 0; x < 20; x++){
      templeter[x] = '|';
  }

  int graph[20][20];
  for(int x = 0; x < 20; x++){
    for(int y = 0; y < 20; y++){
      graph[x][y] = -1;
    }
  }

  while(true){
      char i2n[50]; // ask user for what they want to do
      char add[50] = "addvertex";
      char console[50] = "addnode";
      char display[50] = "deletevertex";
      char deletes[50] = "deletenode";
      char quit[50] = "quit";
      char sear[50] = "print";
      char path[50] = "find";
      cout << endl << "What would you like to do? (addvertex, addnode, deletevertex, deletenode, quit, print, find): ";
      cin >> i2n;
      if(strcmp(i2n, add) == 0){ // add vertex
      }
      else if(strcmp(i2n, console) == 0){ // add node
      }
      else if(strcmp(i2n, display) == 0){// delete vertex
      }
      else if(strcmp(i2n, sear) == 0){// print
	displays(graph, size, templeter);
      }
      else if(strcmp(i2n, deletes) == 0){// delete node
      }
      else if(strcmp(i2n, quit) == 0){// quit
      }
      else if(strcmp(i2n, path) == 0){// find 
      }
      else{
        cout << "Invalid input options are: (addvertex, addnode, deletevertex, deletenode, qu\
it, print, find): ";
      }
    }
    return 0;
}


void displays(int graph[20][20], int size, char templeter[20]){
  for(int x = 0; x < size; x++){
    cout << templeter[x] << "   " << x << endl;
  }
  cout<< endl << endl;

  
  cout << "  ";
  for(int x = 0; x < size; x++){
    cout << " ";
    if(x < 10){
      cout << "   " << x;
    }else{
      cout << "  " << x;
    }
    
    }
  cout << endl;
  for(int x = 0; x < size; x++){
    if(x < 10){
      cout << x << " ";
    }
    else{
      cout << x;
    }
    for(int y = 0; y < size; y++){
      if(graph[x][y] == -1){
	cout << "    _";
      }
      else if(graph[x][y] < 10){
	cout << "    " << graph[x][y];
      }
      else if(graph[x][y] < 100){
        cout << "   " << graph[x][y];
      }
      else{
        cout << "  " << graph[x][y];
	}
    }
    cout << endl;
  }
}
