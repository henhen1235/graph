#include <iostream>
#include <vector>
#include <cstring>
#include <vector>


using namespace std;

void displays(int graph[20][20], int size, char templeter[20]);
void addnode(char name, char templeter[20], int& size);
int searcher(char search, int size, char templeter[20]);
void runner(int graph[20][20], char templeter[20], int size, vector<int>& visited, vector<int>& unvisited, vector<int>& shortest, vector<int>& previous, int pos, int distance);

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
	cout << "Node 1 (intial node): ";
	cin >> firstn;
	cout << "Node 2 (connection node): ";
	cin >> secondn;
	cout << "Value: ";
	cin >> value;
	int pos1 = searcher(firstn, size, templeter);
	int pos2 = searcher(secondn, size, templeter);
	if(pos1 == -1 || pos2 == -1){
	  cout << "That Node does not exist" << endl;
	}
	graph[pos1][pos2] = value;
	//	graph[pos2][pos1] = value;
	
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
        cout << "Which two nodes vertex would you like to delete? Give the name(it is a single char)" << endl;
        cout << "Node 1 (inital node): ";
        cin >> firstn;
        cout << "Node 2 (connection node): ";
        cin >> secondn;
        int pos1 = searcher(firstn, size, templeter);
        int pos2 = searcher(secondn, size, templeter);
        if(pos1 == -1 || pos2 == -1){
          cout << "That Node does not exist" << endl;
        }
        graph[pos1][pos2] = -1;
	//        graph[pos2][pos1] = -1;
	
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
	  graph[x][size-1] = -1;
	  graph[size-1][x] = -1;
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
      char name;
      cout << "What node do you want to search from?(it can only be a single char): " << endl;
      cin >> name;
      int pos = searcher(name, size, templeter);
      cout << "starting search" << endl;
      vector<int> visited;
      vector<int> unvisited;
      vector<int> shortest;
      vector<int> previous;

      for(int x = 0; x < size; x++){
	unvisited.push_back(x);
	shortest.push_back(-1);
	previous.push_back(-1);
	visited.push_back(-1);
      }
      cout << "initilization done"<< endl;
      shortest[pos] = 0;
      int distance = 0;
      cout << "starting runner" << endl;
      runner(graph, templeter, size, visited, unvisited, shortest, previous, pos, distance);

      for(int x = 0; x< size; x++){
	cout << shortest[x] << endl;
	
      }
      }      
      else{
        cout << "Invalid input options are: (addvertex, addnode, deletevertex, deletenode, qu\
it, print, find): ";
      }
    }
    return 0;
}

void runner(int graph[20][20], char templeter[20], int size, vector<int>& visited, vector<int>& unvisited, vector<int>& shortest, vector<int>& previous, int pos, int distance){
  cout << "running: " << pos << endl;

  visited[pos] = pos;
  unvisited[pos] = -1;

  vector<int> storage;
  for(int x = 0; x< size; x++){
    if(graph[pos][x] != -1 && visited[x] == -1 && (shortest[x] == -1 || shortest[x] > distance + graph[pos][x])){
      cout << "found path: " << x << endl;
      shortest[x] = graph[pos][x] + distance;
      previous[x] = pos;
      storage.push_back(x);
      }
    }    
  
  cout << "number of paths found: " << storage.size() << endl; 
  for(int x = 0; x< storage.size(); x++){
    if(graph[pos][storage[x]] != -1){
      cout << "running from: " << pos << " going to: " << storage[x] << endl;
      runner(graph, templeter, size, visited, unvisited, shortest, previous, storage[x], distance + graph[pos][x]);
    }
    }
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
