#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

class Grafo{
private:
	vector< pair<int,int> >* Lista;
	vector<int> vizinhos;
	int tam;
public:
	Grafo(int set){
		this->Lista = new vector< pair<int,int> >[set];
		this->vizinhos.resize(set);
		for(int i = 0; i < set; i++)
		    this->vizinhos[i] = 0;
		this->tam = set;
	}
	void atualizaGrafo(int, int, int);
	void djkstra(int);
	void clear();
};

void Grafo::clear(){
	delete[] this->Lista;
}

void Grafo::atualizaGrafo(int x, int y, int dist){
	this->Lista[x].push_back(make_pair(y, dist));
	this->vizinhos[x]++;
	this->Lista[y].push_back(make_pair(x, dist));
	this->vizinhos[y]++;
}

void Grafo::djkstra(int caso){
	int i = 0, origem;
	while(this->Lista[i].size() == 2)
		i++;
	origem = i;

	int distancia[this->tam];
	for(int i = 0; i < this->tam; i++)
		distancia[i] = 100000;

	distancia[origem] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > heap_hour;
	//min_heap.emplace(0,origem);
	heap_hour.emplace(0, origem);
	while(!heap_hour.empty()){
		pair<int,int> Painho;
        Painho = heap_hour.top();
		heap_hour.pop();
        int peso = Painho.second;

		for(auto cursor: this->Lista[peso]) {
			int v, w;
			v = cursor.first;
			w = cursor.second;
			if( (distancia[peso] + w) < distancia[v] ) {
				distancia[v] = distancia[peso] + w;
				heap_hour.emplace(distancia[v], v);
			}
		}
	}
	cout << "caso " << caso << endl;
	i = 0;
	while(this->vizinhos[i] == 2)
	    i++;
	cout << distancia[i];
	for(int j = i+1; j < this->tam; j++) {
		if(this->vizinhos[j] != 2)
		    cout << " " << distancia[j];
	}
	cout << endl;
}

int main() {
	int N, M;
	int caso = 0;

	while( scanf("%d %d", &N, &M) != EOF ) {
		Grafo mainha(N);

		for( int i = 0; i < M; i++) {
			int u, v, d;
			cin >> u >> v >> d;
			mainha.atualizaGrafo( u, v, d);
		}
		mainha.djkstra(caso);
		cout << endl;
		caso++;
		mainha.clear();
	}
	
	return 0;
}
