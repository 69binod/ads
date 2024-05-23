#include<iostream>
#include<list>
#include<iterator>
using namespace std;

int vertArr[20][20]; //the adjacency matrix initially 0

// function to display the adjacency matrix
void displayMatrix(int v) {
    cout << "Adjacency Matrix:" << endl;
    cout << "   ";
    for (int i = 0; i < v; ++i) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < v; ++i) {
        cout << i << "  ";
        for (int j = 0; j < v; ++j) {
            cout << vertArr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// function to display the adjacency list
void displayAdjList(list<int> adj_list[], int v) {
    cout << "Adjacency List:" << endl;
    for(int i = 0; i < v; i++) {
        cout << i << "--->";
        list<int>::iterator it;
        for(it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
}


void add_edge(int u, int v) {   //function to add edge into the matrix
    vertArr[u][v] = 1;
    vertArr[v][u] = 1;
}

int main() {
    int v; // number of vertices in the graph
    cout << "Enter the number of vertices in the graph: ";
    cin >> v;

    // Initialize adjacency matrix with all zeroes
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            vertArr[i][j] = 0;
        }
    }

    int e; // number of edges in the graph
    cout << "Enter the number of edges in the graph: ";
    cin >> e;

    // Adding edges based on user input
    cout << "The graph is zero based" << endl << "Enter the edges (vertex pairs separated by space):" << endl;
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    // create an array of lists whose size is 'v'
    list<int> adj_list[v];

    // Adding edges to the adjacency list
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            if (vertArr[i][j] == 1) {
                adj_list[i].push_back(j);
            }
        }
    }

    displayMatrix(v);
    displayAdjList(adj_list, v);

    return 0;
}
