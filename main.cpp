#include <iostream>
#include <vector>
#include <cstring>
#include <vector>


using namespace std;

void displays(int graph[20][20], int size, char templeter[20]);
void addnode(char name, char templeter[20], int& size);
int searcher(char search, int size, char templeter[20]);
int paths(vector<int> vistedn, vector<int> unvistedn, int shortest[20], int previous[20], int size, char templeter[20], int graph[20][20], int current, int add);


int main(){
int size = 0;
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
	char firstn;
	char secondn;
	int value;
	cout << "Which two nodes would you like to link? Give the name(it is a single char)" << endl;
	cout << "Node 1: ";
	cin >> firstn;
	cout << "Node 2: ";
	cin >> secondn;
	cout << "Value: ";
	cin >> value;
	int pos1 = searcher(firstn, size, templeter);
	int pos2 = searcher(secondn, size, templeter);
	if(pos1 == -1 || pos2 == -1){
	  cout << "That Node does not exist" << endl;
	}
	graph[pos1][pos2] = value;
	graph[pos2][pos1] = value;
	
      }
      else if(strcmp(i2n, console) == 0){ // add node
	char name;
	cout << "What do you want to name this node?(it can only be a single char): " << endl;
	cin >> name;
	addnode(name, templeter, size);
      }
      else if(strcmp(i2n, display) == 0){// delete vertex
	char firstn;
        char secondn;
        int value;
        cout << "Which two nodes would you like to delete? Give the name(it is a single char)" << endl;
        cout << "Node 1: ";
        cin >> firstn;
        cout << "Node 2: ";
        cin >> secondn;
        int pos1 = searcher(firstn, size, templeter);
        int pos2 = searcher(secondn, size, templeter);
        if(pos1 == -1 || pos2 == -1){
          cout << "That Node does not exist" << endl;
        }
        graph[pos1][pos2] = -1;
        graph[pos2][pos1] = -1;
	
      }
      else if(strcmp(i2n, sear) == 0){// print
	displays(graph, size, templeter);
      }
      else if(strcmp(i2n, deletes) == 0){// delete node
	char name;
        cout << "What node do you want to delete?(it can only be a single char): " << endl;
        cin >> name;
	int pos = searcher(name, size, templeter);
	cout << "size: " << size << endl;
	if(pos == -1){
	  cout << "Node DNE" << endl;
	}
	else{
	  int diff = size - pos;
	for(int x = 0; x < size; x++){
	  graph[x][pos] = graph[x][size - 1];
	  graph[pos][x] = graph[size -1][x];
	}
      	char tem1 = templeter[size-1];
	templeter[pos] = tem1;
	
	templeter[size-1] = '|';
	
	size = size - 1;
	}
	}
      else if(strcmp(i2n, quit) == 0){// quit
	break;
      }
      else if(strcmp(i2n, path) == 0){// find 
        char firstn;
        char secondn;
        int value;
        cout << "Which two nodes would you like to find the path? Give the name(it is a single char)" << endl;
        cout << "Node 1: ";
        cin >> firstn;
        cout << "Node 2: ";
        cin >> secondn;
        int pos1 = searcher(firstn, size, templeter);
        int pos2 = searcher(secondn, size, templeter);
        if(pos1 == -1 || pos2 == -1){
          cout << "That Node does not exist" << endl;
        }
        int current = pos1;
        int end = pos2;
        vector<int> vistedn;
        vector<int> unvistedn;
        int shortest[20];
        int previous[20];
        for(int x = 0; x< 20; x++){
          shortest[x] = 9999999999;
          previous[x] = 9999999999;
        }
        for(int x = 0; x < size; x++){
          vistedn.push_back(x);
        }
        shortest[current] = 0;
        int add = 0;
        paths(vistedn, unvistedn, shortest, previous, size, templeter, graph, current, add);

        shortest[]
      }
      else{
        cout << "Invalid input options are: (addvertex, addnode, deletevertex, deletenode, qu\
it, print, find): ";
      }
    }
    return 0;
}
//use later
 // vistedn.erase(remove(vistedn.begin(), vistedn.end(), current), vistedn.end()); // stack over flow code. This is not mine
  // unvistedn.push_back(current);

int paths(vector<int> vistedn, vector<int> unvistedn, int shortest[20], int previous[20], int size, char templeter[20], int graph[20][20], int current, int add){
 
  int shorttemp = -1;
  int shortpos = -1;
  for(int x = 0; x < size; x++){
    if(graph[x][current] != -1){
      shortest[x] = graph[x][current] + add;
      previous[x] = current;
      if(graph[x][current] < shorttemp){
        shorttemp = graph[x][current];
        shortpos = x;
      }
    }
  }

  vistedn.erase(remove(vistedn.begin(), vistedn.end(), current), vistedn.end()); // stack over flow code. This is not mine
  unvistedn.push_back(current);
  if(shorttemp == -1){
    return;
  }
  add = add + shorttemp;
  current = shortpos;
  paths(vistedn, unvistedn, shortest, previous, size, templeter, graph, current, add);

}

int searcher(char search, int size, char templeter[20]){
  for(int x = 0; x < size; x++){
    if(templeter[x] == search){
      return x;
    }
  }
  return -1;
}

void addnode(char name, char templeter[20], int& size){
  templeter[size] = name;
  size++;
}

void displays(int graph[20][20], int size, char templeter[20]){
  cout << "Legend:" << endl;
  for(int x = 0; x < size; x++){
    cout << "Value: "<< x<< " - " << "Name: "<<templeter[x] << endl;
  }
  cout<< endl << "Vertex:"<< endl;

  
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
