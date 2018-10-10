#include <bits/stdc++.h>

#define endl '\n'
#define MAX 101
#define MIN -2147483648
#define MAX_F(a,b) ( ((a) > (b) ? (a): (b) ))
using namespace std;

typedef struct TIPO{

	int M, N, S;
	int endI, endJ, endK;
}TIPO;

int SI[3] = {-1, 0, 0};
int SJ[3] = { 0, 1, 0};
int SK[3] = { 0, 0, 1};
int cubo[MAX][MAX][MAX];
int cuboAux[MAX][MAX][MAX];
TIPO jogo;

int caminho( int I, int J, int K);

int main() {

	int P = 0;
	cin >> jogo.M >> jogo.N >> jogo.S;

	cin >> jogo.endI >> jogo.endJ >> jogo.endK;

	//PEGANDO PESOS
	for( int i = 0; i < jogo.M; i++) {

		for( int j = 0; j < jogo.N; j++) {

			for( int k = 0; k < jogo.S; k++) {

				cin >> cubo[i][j][k];
				cuboAux[i][j][k] = MIN;
			}
		}
	}

	//ORIGENS
	cin >> P;
	while(P != 0) {

		int resposta = MIN;
		int beginI, beginJ, beginK;
		cin >> beginI >> beginJ >> beginK;

		if( cuboAux[beginI][beginJ][beginK] != MIN ) {

			resposta = cuboAux[beginI][beginJ][beginK];
		}
		else {

			resposta = caminho(beginI, beginJ, beginK);
		}

		if(resposta != MIN) {

			cout << resposta << endl;
		}

		P--;
	}

	return 0;
}

int caminho( int I, int J, int K) {

	int joao = MIN;
	int maria = MIN;
	int joseh = MIN;
	
	if( I == jogo.endI && J == jogo.endJ && K == jogo.endK ) {
		return cubo[jogo.endI][jogo.endJ][jogo.endK];
	}else if(I < jogo.endI || J > jogo.endJ || K > jogo.endK){
		return MIN;
	}
		
	if(  I - 1 >= 0 ) {

		if( cuboAux[I][J][K] != MIN ) {

			//Eh pq já foi alterado
			joao = cuboAux[I][J][K];
		}
		else {

			joao = cubo[I][J][K] + caminho( I - 1, J, K);
		}
	}

	if( J + 1 <= jogo.N-1 ) {

		if( cuboAux[I][J][K] != MIN ) {

			//Eh pq já foi alterado
			maria = cuboAux[I][J][K];
		}
		else {

			maria = cubo[I][J][K] + caminho( I, J + 1, K);
		}
	}

	if( K + 1 <= jogo.S-1) {

		if( cuboAux[I][J][K] != MIN ) {

			//Eh pq já foi alterado
			joseh = cuboAux[I][J][K];
		}
		else {

			joseh = cubo[I][J][K] + caminho( I, J, K + 1);
		}
	}

	if(MAX_F(MAX_F(joao, maria), joseh) == joao)
	{
		cuboAux[I][J][K] = joao;
		return joao;
	}
	else if(MAX_F(MAX_F(joao, maria), joseh) == maria)
	{
		cuboAux[I][J][K] = maria;
		return maria;
	}
	else
	{
		cuboAux[I][J][K] = joseh;
		return joseh;
	}
}

/*
bool caminho(int I, int J, int K) {

	bool flag = false;
	bool final = false;

	if( I == jogo.endI && J == jogo.endJ && K == jogo.endK ) {

		cuboAux[I][J][K] = cubo[jogo.endI][jogo.endJ][jogo.endK];
		flag = true;
	}
	else {
		for( int n = 0; n < 3; n++) {

			int auxI, auxJ, auxK;
			auxI = I + SI[n];
			auxJ = J + SJ[n];
			auxK = K + SK[n];
			if( auxI >= 0 && auxI <= jogo.M-1 && 
				auxJ >= 0 && auxJ <= jogo.N-1 && 
				auxK >= 0 && auxK <= jogo.S-1) {

				if( cuboAux[auxI][auxJ][auxK] == MIN ) {

					flag = caminho(auxI, auxJ, auxK);
				}
				else {

					flag = true;
				}

				if(flag){

					flag = false;
					final = true;
					cuboAux[I][J][K] = 1;
				}
			}
		}
	}

	if(flag){

		flag = false;
		final = true;
	}

	return final;
}
*/
/*
bool caminho( int I, int J, int K) {

	bool flag = false;
	bool final = false;

	if( I == jogo.endI && J == jogo.endJ && K == jogo.endK ) {

		cuboAux[I][J][K] = cubo[jogo.endI][jogo.endJ][jogo.endK];
		return true;
	}
	else {

		for( int n = 0; n < 3; n++) {

			int auxI = I + SI[n];
			int auxJ = J + SJ[n];
			int auxK = K + SK[n];
			if( auxI >= 0 && auxI <= (jogo.M-1) &&
				auxJ >= 0 && auxJ <= (jogo.N-1) &&
				auxK >= 0 && auxK <= (jogo.S-1) ) {

				if(cuboAux[auxI][auxJ][auxK] < 0) {

					flag = caminho(auxI, auxJ, auxK);
				}
				else if(cuboAux[auxI][auxJ][auxK] > 0) {

					flag = true;
				}
				else {

					flag = false;
				}

				if( flag == true ) {

					final = true;
					if( cuboAux[I][J][K] < (cuboAux[auxI][auxJ][auxK]+cubo[I][J][K]) ) {

						cuboAux[I][J][K] = cuboAux[auxI][auxJ][auxK]+cubo[I][J][K];
					}
				}
			}
		}
	}
	return final;
}
*/