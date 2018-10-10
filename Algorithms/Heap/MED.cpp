#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <math.h>
#define endl '\n'

using namespace std;

void arruma_minHeap(vector<int> &v, int pos_novo);
void arruma_maxHeap(vector<int> &v, int pos_novo);
void move_elemento(vector<int> &dest, vector<int> &orig, int tam_orig);
void rebaixa_elementoMaxHP(vector<int> &v, int raiz, int tam);
void rebaixa_elementoMinHP(vector<int> &v, int raiz, int tam);

int main() {
	string funcao;
	int tam_U = 0;
	int tam_L = 0;
	int min = -1;
	int max = -1;
	vector<int> U_minHeap;
	vector<int> L_maxHeap;
	while(cin >> funcao) {
		if( funcao ==  "ADD" ) {
			int num;
			cin >> num;
			// Estabelecendo se o novo valor eh minimo ou maximo global
			if( min == -1 && max == -1 ) {
				min = num;
				max = num;
			} else if(num < min) {
				min = num;
			} else if(num > max) {
				max = num;
			}
			// Adicionando o novo valor a U ou L
			if(tam_U == 0) {
				U_minHeap.push_back(num);
				arruma_minHeap(U_minHeap,tam_U);
				tam_U++;
			} else if( num < U_minHeap[0] ) {
				L_maxHeap.push_back(num);
				arruma_maxHeap(L_maxHeap,tam_L);
				tam_L++;
			} else {
				U_minHeap.push_back(num);
				arruma_minHeap(U_minHeap,tam_U);
				tam_U++;
			}
			// Verificando tamanhos de L e U
			if(tam_L > tam_U) {
				move_elemento(U_minHeap, L_maxHeap, tam_L);
				arruma_minHeap(U_minHeap, tam_U);
				rebaixa_elementoMaxHP(L_maxHeap,0,tam_L);
				tam_L--;
				tam_U++;
			} else if(tam_U >= (tam_L + 2)) {
				move_elemento(L_maxHeap, U_minHeap, tam_U);
				arruma_maxHeap(L_maxHeap,tam_L);
				rebaixa_elementoMinHP(U_minHeap,0,tam_U);
				tam_L++;
				tam_U--;
			}
			cout << min << " " << U_minHeap[0] << " " << max << endl;
		} else if( funcao == "MIN" ) {
			cout << min << endl;
		} else if( funcao == "MAX" ) {
			cout << max << endl;
		} else if( funcao == "MED" ) {
			if(tam_U == 0)
				cout << -1 << endl;
			else
				cout << U_minHeap[0] << endl;
		} else if( funcao == "RES" ) {
			cout << tam_U + tam_L << endl;
			U_minHeap.clear();
			tam_U = 0;
			L_maxHeap.clear();
			tam_L = 0;
			min = -1;
			max = -1;
		}
	}
	return 0;
}


void arruma_minHeap(vector<int> &v, int pos_novo) {
	int pos_pai;
	pos_pai = (pos_novo - 1) / 2;
	while((pos_novo > 0) && (v[pos_pai] >= v[pos_novo])) {
		int temp = v[pos_novo];
		v[pos_novo] = v[pos_pai];
		v[pos_pai] = temp;

		pos_novo = pos_pai;
		pos_pai = (pos_pai - 1) / 2;
	}
}

void arruma_maxHeap(vector<int> &v, int pos_novo) {
	int pos_pai;
	pos_pai = (pos_novo - 1) / 2;
	while((pos_novo > 0) && (v[pos_pai] <= v[pos_novo])) {
		int temp = v[pos_novo];
		v[pos_novo] = v[pos_pai];
		v[pos_pai] = temp;

		pos_novo = pos_pai;
		pos_pai = (pos_pai - 1) / 2;
	}
}

void rebaixa_elementoMaxHP(vector<int> &v, int raiz, int tam) {
	int noh = 2 * raiz + 1;
	while( noh < tam ) {
		if( noh < tam - 1 ) // pra ver se raiz tem 2 nohs
			if( v[noh] < v[noh+1] ) // comparando com o noh irmão
				noh++;
		// Se precisar trocar raiz pelo noh filho
		if( v[raiz] <= v[noh] ) {
			int temp = v[raiz];
			v[raiz] = v[noh];
			v[noh] = temp;

			raiz = noh;
			noh = 2 * raiz + 1;
		} else {
			noh = tam; // Eh pq ta tudo certo
		}
	}
}

void rebaixa_elementoMinHP(vector<int> &v, int raiz, int tam) {
	int noh = 2 * raiz + 1;
	while( noh < tam ) {
		if( noh < tam - 1 ) // pra ver se raiz tem 2 nohs
			if( v[noh] > v[noh+1] ) // comparando com o noh irmão
				noh++;
		// Se precisar trocar raiz pelo noh filho
		if( v[raiz] >= v[noh] ) {
			int temp = v[raiz];
			v[raiz] = v[noh];
			v[noh] = temp;

			raiz = noh;
			noh = 2 * raiz + 1;
		} else {
			noh = tam; // Eh pq ta tudo certo
		}
	}
}

void move_elemento(vector<int> &dest, vector<int> &orig, int tam_orig) {
	int temp = orig[0];
	orig[0] = orig[tam_orig - 1];
	orig.pop_back();
	dest.push_back(temp);
}