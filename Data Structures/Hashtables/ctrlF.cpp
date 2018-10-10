#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define endl '\n'
#define FCMAX 0.5

using namespace std;


typedef struct CONTROL {

	int tam_K; // tamanho dos kmers
	int qtd; // Espaços ocupados
	int tam_tab;
}CONTROL;

typedef struct HASH {

	int ocupado;
	string kmers;
	int* pos; //posição no txt
	int* locais;
	uint32_t key;
}HASH;

char texto[30000000] = {'\0'};
CONTROL controle;

void iniciaControle();
bool fator_carga();
uint32_t gerador_chave(string str);
int gerador_indice( uint32_t chave, int j);
bool comp_string( string str1, int tam1, int begin1, string str2, int begin2);
HASH* hashing(HASH *ptr, string kmer, int pos_txt, int indice, uint32_t chave);
HASH *rehashing(HASH* ptr, int tam_last);
//void verTab(HASH* tabela);
void busca(HASH* ptr, char consulta[1000]);
void seq_rep(HASH* ptr);



int main() {

	iniciaControle();
	HASH* tabela = (HASH*) calloc(controle.tam_tab, sizeof(HASH));
	tabela[0].locais = (int*) malloc(1*sizeof(int));

	string lixo;
	int Y;
	cin >> lixo >> Y;
	getline(cin,lixo); //limpar buffer

	int chico = 0;
	int chica = 0;

	// Pegando texto
	while( chico != Y ) {

		char treloso;
		treloso = getchar();
		chica++;
		texto[chica-1] = treloso;
		texto[chica] = '\0';
		if(treloso == '\n')
			chico++;
	}

	// Distribuindo kmers
	int tam_string = chica - controle.tam_K;
	string kmer;
	kmer.resize(controle.tam_K);
	for( int i = 0; i < tam_string; i++) {

		for( int k = 0; k < controle.tam_K; k++)
			kmer[k] = texto[k+i];

		uint32_t chave = gerador_chave(kmer);
		int indice = gerador_indice(chave, 0);
		tabela = hashing(tabela, kmer, i, indice, chave);

		if( fator_carga() ) {

			//int tam_last = controle.tam_tab;
			int qtd_last = controle.qtd;
			controle.tam_tab = ( 2 * controle.tam_tab ) + 1;
			controle.qtd = 0;
			tabela = rehashing(tabela, qtd_last);
		}

	}
	//cout << "TABELA\n";
	//verTab(tabela);

	// Consultas
	cin >> lixo >> Y;
	getline(cin,lixo); //limpar buffer

	for( int i = 0; i < Y; i++ ) {

		//string consulta;
		//getline(cin,consulta);
		char consulta[1000] = {'\0'};
		int num = scanf(" %[^\n]", consulta);
		num++;
		cout << i << ":" << " ";
		busca(tabela, consulta);
		cout << endl;
	}

	cout << controle.qtd << " " << controle.tam_tab << " ";
	seq_rep(tabela);
	cout << endl;

	free(tabela[0].locais);
	free(tabela);
	return 0;
}
/*
void verTab(HASH* tabela) {

	for( int i = 0; i < controle.tam_tab; i++) {

		cout << "[" << tabela[i].kmers << "]:";
		for( int j = 0; j < tabela[i].ocupado; j++)
			cout << " " << tabela[i].pos[j];
		cout << endl;
	}
}
*/
void iniciaControle() { //OK

    int K,tam_inicial;
    cin >> K >> tam_inicial;
	controle.tam_K =  K;
	controle.qtd = 0;
	controle.tam_tab = tam_inicial;
}

bool fator_carga() { //OK

	float result = (float)(controle.qtd)/(float)(controle.tam_tab);
	if( result >= FCMAX )
		return true;
	else
		return false;
}

uint32_t gerador_chave(string str) { //OK

    int B = 128;
    uint32_t C = 0;
    for( int i = 0; i < controle.tam_K; i++) {

        C = ( ( C * B ) + (int)str[i] );
    }
    return C;
}

int gerador_indice( uint32_t chave, int j) { //OK

	return ( chave + j ) % controle.tam_tab;
}

bool comp_string( string str1, int tam1, int begin1, string str2, int begin2) {

	for( int i = 0; i < tam1; i++) {

		if(str1[i+begin1] != str2[i+begin2])
			return false;
	}
	return true;
}

HASH* hashing(HASH *ptr, string kmer, int pos_txt, int indice, uint32_t chave) {

	if(ptr[indice].ocupado == 0) {
		ptr[indice].ocupado = 1;
		ptr[indice].kmers = kmer;
		ptr[indice].pos = (int*) calloc(1, sizeof(int));
		ptr[indice].pos[0] = pos_txt;
		ptr[indice].key = chave;
		controle.qtd++;
		ptr[0].locais = (int*) realloc(ptr[0].locais, controle.qtd*sizeof(int));
		ptr[0].locais[controle.qtd-1] = indice;
	}
	else if(comp_string(kmer, controle.tam_K, 0, ptr[indice].kmers, 0)) {
		ptr[indice].ocupado++;
		ptr[indice].pos = (int*) realloc(ptr[indice].pos, ptr[indice].ocupado*sizeof(int));
		ptr[indice].pos[ptr[indice].ocupado-1] = pos_txt;
	}
	else {
		bool flag = true;
		while(flag) {

			indice++;
			if( indice >= controle.tam_tab )
				indice = 0;
			if(ptr[indice].ocupado == 0){

				ptr[indice].ocupado = 1;
				ptr[indice].kmers = kmer;
				ptr[indice].pos = (int*) calloc(1, sizeof(int));
				ptr[indice].pos[0] = pos_txt;
				controle.qtd++;
				flag = false;
				ptr[0].locais = (int*) realloc(ptr[0].locais, controle.qtd*sizeof(int));
				ptr[0].locais[controle.qtd-1] = indice;
				ptr[indice].key = chave;
			}
			else if(comp_string(kmer, controle.tam_K, 0, ptr[indice].kmers, 0)) {

				ptr[indice].ocupado++;
				ptr[indice].pos = (int*) realloc(ptr[indice].pos, ptr[indice].ocupado*sizeof(int));
				ptr[indice].pos[ptr[indice].ocupado-1] = pos_txt;
				flag = false;
			}
		}
	}
/*
	if(ptr[indice].ocupado != 0) {
		if( comp_string(kmer, controle.tam_K, 0, ptr[indice].kmers, 0) ) {

			ptr[indice].pos.push_back(pos_txt);
			ptr[indice].ocupado++;
		}
		else {

			indice++;
			if( indice >= controle.tam_tab )
				indice = 0;
			ptr = hashing(ptr,kmer,pos_txt, indice);
		}
	}
	else {

		ptr[indice].ocupado = 1;
		ptr[indice].kmers = kmer;
		ptr[indice].pos.push_back(pos_txt);
		controle.qtd++;
	}
*/
	return ptr;
}

HASH *rehashing(HASH* ptr, int tam_last) {

	HASH* aux = (HASH*) calloc(controle.tam_tab, sizeof(HASH));
	for( int i = 0; i < tam_last; i++) {

		if(ptr[ptr[0].locais[i]].ocupado != 0) {

			int indice = gerador_indice(ptr[ptr[0].locais[i]].key, 0);
			for( int j = 0; j < ptr[ptr[0].locais[i]].ocupado; j++) {

				aux = hashing(aux, ptr[ptr[0].locais[i]].kmers, ptr[ptr[0].locais[i]].pos[j], indice, ptr[ptr[0].locais[i]].key);
			}
		}
	}
	return aux;
}

void busca(HASH* ptr, char consulta[1000]) {

	bool flag = true, ota_flag = true;
	//int count = 0;
	//int tam_consulta = consulta.size();
	int tam_consulta = strlen(consulta);
	//string kmer_consulta;
	char kmer_consulta[1000] = {'\0'};
	//kmer_consulta.resize(controle.tam_K);
	for( int i = 0; i < controle.tam_K; i++) {

		kmer_consulta[i] = consulta[i];
	}
	kmer_consulta[controle.tam_K] = '\0';
	uint32_t chave = gerador_chave((char*)kmer_consulta);
	int indice = gerador_indice(chave, 0);
	while( (ptr[indice].ocupado != 0) && !comp_string((char*)kmer_consulta, controle.tam_K, 0, ptr[indice].kmers, 0) ) {
		indice++;
	}
	int tam_pos = ptr[indice].ocupado;
	for( int i = 0; i < tam_pos; i++) {
/*
		int j = 0;

		for(j = controle.tam_K; (j < tam_consulta) && (consulta[j] == texto[j+ptr[indice].pos[i]]); j++) {}

		if(j == tam_consulta)
			flag = true;

		if(comp_string((char*)consulta, tam_consulta, controle.tam_K, (char*)texto, (controle.tam_K+ptr[indice].pos[i]))) {

			//count++;
			if( flag )
				cout << ptr[indice].pos[i];
			else
				cout << " " << ptr[indice].pos[i];
			flag = false;
		}
*/
		flag = true;
		for(int k = 0; k < tam_consulta; k++){
			if(texto[ptr[indice].pos[i] + k] != consulta[k]){
				flag = false;
			}
		}
		if(flag){
			if(ota_flag){
				cout << ptr[indice].pos[i];
				ota_flag = false;
			}
			else
				cout << " " << ptr[indice].pos[i];
		}
	}
}

void seq_rep(HASH* ptr) {
	int seq = 0;
	int aux = seq;
	for( int i = 0; i < controle.tam_tab; i++) {
		if( ptr[i].ocupado != 0 )
			seq++;
		else {
			seq = 0;
		}
		if( seq > aux ) 
			aux = seq;
	}

	if( seq > aux )
		aux = seq;
	cout << aux;
}