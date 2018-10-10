#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>


typedef struct MUSICA{

    std::string nomeMusica;
    struct MUSICA *proximoElmusica;

}MUSICA;


typedef struct PLAYLIST{

    std::string nomePlaylist;
    struct MUSICA *nome;
    struct PLAYLIST *proximoElplaylist;


}PLAYLIST;

typedef struct FILA{

    std::string musicaAtual;
    struct FILA *anteriorFila;
    struct FILA *proximoFila;

}FILA;

bool comando = false;

//void printaSong( MUSICA *song );
//void printaList( PLAYLIST *list );
//void printaFila( FILA *head );
MUSICA *alocaMusica();
PLAYLIST *alocaPlaylist();
FILA *alocaFila();
PLAYLIST *inicializa( PLAYLIST *list, FILA **queue, FILA **headFila );
PLAYLIST *initList(PLAYLIST *list);
int opcao( std::string op );
PLAYLIST *menu( PLAYLIST *list, FILA **queue, FILA **headFila);
PLAYLIST *adicionaSongToList( PLAYLIST *addList);
PLAYLIST *adiciona( PLAYLIST *list);
PLAYLIST *deletaSongFromList(PLAYLIST *curList);
void deleta( PLAYLIST **list);
PLAYLIST *swpPlaylist(PLAYLIST *list);
FILA *pls( FILA *queue, FILA **queueH);
FILA *plp( FILA *queue, FILA **queueH, PLAYLIST *list);
FILA *nxt( FILA *queue );
FILA *prv( FILA *queue, FILA *head);
FILA *clr( FILA *queue );
void inf( FILA *queue, FILA *head );



int main() {

    PLAYLIST *list = alocaPlaylist();
    FILA *queue = alocaFila();
    list->nome = alocaMusica();

    FILA *headFila = alocaFila();

    list = inicializa( list, &queue, &headFila);
    int N = 0;


    std::cin >> N;

    while(N>0){
        list = menu( list, &queue, &headFila);
        N--;
    }

    //delete list->nome;
    //delete list;
    //delete headFila;
    //delete queue;

    return 0;
}
/*
void printaSong( MUSICA *song ) {
	MUSICA *auxS = song->proximoElmusica;
	while( auxS != NULL ){
		std::cout << auxS->nomeMusica << std::endl;
		auxS = auxS->proximoElmusica;
	}
}

void printaList( PLAYLIST *list ) {
	PLAYLIST *aux = list->proximoElplaylist;
	if(aux==NULL){
		std::cout << "TEste\n";
	}
	while( aux != NULL ){
		std::cout << aux->nomePlaylist << std::endl;
		printaSong(aux->nome);
		aux = aux->proximoElplaylist;
	}
}

void printaFila( FILA *head ) {
	FILA *cur = head->proximoFila;
	std::cout << "-------------" << std::endl;
	while( cur != NULL ) {
		std::cout << cur->musicaAtual << std::endl;
		cur = cur->proximoFila;
	}
	std::cout << "-------------" << std::endl;
}
*/
MUSICA *alocaMusica() {
    MUSICA *nova = new(std::nothrow) MUSICA;
    if( nova == NULL ){
        std::cout << "Falha ao alocar nova song" << std::endl;
        exit(1);
    } else {
        return nova;
    }
}

PLAYLIST *alocaPlaylist() {
    PLAYLIST *nova = new(std::nothrow) PLAYLIST;
    if( nova == NULL ){
        std::cout << "Falha ao alocar nova playlist" << std::endl;
        exit(1);
    } else {
        return nova;
    }
}

FILA *alocaFila() {
    FILA *nova = new(std::nothrow) FILA;
    if( nova == NULL ){
        std::cout << "Falha ao alocar nova fila" << std::endl;
        exit(1);
    } else {
        return nova;
    }
}

PLAYLIST *inicializa( PLAYLIST *list, FILA **queue, FILA **headFila ) {
    MUSICA *aux = list->nome;
    aux->proximoElmusica = NULL;
    list->proximoElplaylist = NULL;


    (*queue)->proximoFila = NULL;
    (*queue)->anteriorFila = NULL;

    (*headFila)->proximoFila = NULL;
    (*headFila)->anteriorFila = NULL;

    return list;
}

PLAYLIST *initList(PLAYLIST *list) {
    list->nome = alocaMusica();

    MUSICA *aux = list->nome;
    aux->proximoElmusica = NULL;
    list->proximoElplaylist = NULL;
    return list;
}

int opcao( std::string op ) {

    if( op.compare(0,3,"ADD") == 0 ){
        return 1;
    } else if( op.compare(0,3,"DEL") == 0 ){
        return 2;
    } else if( op.compare(0,3,"SWP") == 0 ){
        return 3;
    } else if( op.compare(0,3,"PLS") == 0 ){
        return 4;
    } else if( op.compare(0,3,"PLP") == 0 ){
        return 5;
    } else if( op.compare(0,3,"NXT") == 0 ){
        return 6;
    } else if( op.compare(0,3,"PRV") == 0 ){
        return 7;
    } else if( op.compare(0,3,"CLR") == 0 ){
        return 8;
    } else if( op.compare(0,3,"INF") == 0 ){
        return 9;
    }
}

PLAYLIST *menu( PLAYLIST *list, FILA **queue, FILA **headFila) {

    int op;
    std::string stringOp;
    std::cin >> stringOp;
    op = opcao(stringOp);

    switch(op){
        case 1:
            list = adiciona(list);
            //printaList(list);
            break;
        case 2:
            deleta(&list);
            //printaList(list);
            break;
        case 3:
            list = swpPlaylist(list);
            //printaList(list);
            break;
        case 4:
            (*queue) = pls((*queue), &(*headFila));
            //printaFila((*headFila));
            break;
        case 5:
            (*queue) = plp((*queue), &(*headFila), list);
            //printaFila((*headFila));
            break;
        case 6:
            (*queue) = nxt((*queue));
            //printaFila((*headFila));
            break;
        case 7:
            (*queue) = prv((*queue), (*headFila));
            //printaFila((*headFila));
            break;
        case 8:
            (*headFila) = clr((*headFila));
            //printaFila((*headFila));
            break;
        case 9:
            inf((*queue), (*headFila));
            break;
    }
    return list;
}

PLAYLIST *adicionaSongToList( PLAYLIST *addList) {
    MUSICA *novaSong = alocaMusica();
    std::string op;
    std::cin >> op;
    novaSong->nomeMusica = op;

    MUSICA *curSong = addList->nome;

    while( curSong->proximoElmusica != NULL ){
        curSong = curSong->proximoElmusica;
    }
    curSong->proximoElmusica = novaSong;
    novaSong->proximoElmusica = NULL;
    return addList;
}

PLAYLIST *adiciona( PLAYLIST *list) {
    std::string listName;
    std::cin >> listName;
    size_t acha = listName.find("\0");
    //Procura pela qual quer add song, se ela não existir, cria
    PLAYLIST *curList = list;
    while( (curList->proximoElplaylist != NULL) && (listName.compare(0,(acha-1),curList->nomePlaylist) != 0) ){
        curList = curList->proximoElplaylist;
    }
    if( listName.compare(0,(acha-1),curList->nomePlaylist) == 0 ){
        curList = adicionaSongToList(curList);
    } else {
        PLAYLIST *novaPlaylist = alocaPlaylist();
        novaPlaylist->nomePlaylist = listName;
        novaPlaylist = initList(novaPlaylist);
        curList->proximoElplaylist = novaPlaylist;
        curList = curList->proximoElplaylist;
        curList = adicionaSongToList(curList);
    }
    return list;
}

PLAYLIST *deletaSongFromList(PLAYLIST *curList) {
    std::string op;
    std::cin >> op;
    size_t acha = op.find("\0");

    MUSICA *ant = curList->nome;
    MUSICA *cur = ant->proximoElmusica;
    //Procurar a musica a ser deletada
    while( (cur != NULL) && (op.compare(0,(acha-1),cur->nomeMusica)!=0) ){
        ant = ant->proximoElmusica;
        cur = cur->proximoElmusica;
    }
    //Se for no inicio
    if( ant == curList->nome ){
        (curList->nome)->proximoElmusica = cur->proximoElmusica;
    } else {//Se for em qlqr canto
        ant->proximoElmusica = cur->proximoElmusica;
    }
    delete cur;
    return curList;
}

void deleta( PLAYLIST **list) {
    std::string listName;
    std::cin >> listName;
    size_t acha = listName.find("\0");

    //procurar a lista da musica q quer deletar
    PLAYLIST *cur = (*list);
    while( (cur->proximoElplaylist != NULL) && (listName.compare(0,(acha-1),cur->nomePlaylist)!=0) ){
        cur = cur->proximoElplaylist;
    }
    if( listName.compare(0,(acha-1),cur->nomePlaylist) == 0 ){
        //Se achar, deleta musica da playlist
        cur = deletaSongFromList(cur);
    }
}

PLAYLIST *swpPlaylist(PLAYLIST *list) {
    std::string listName;
    std::string Song1;
    std::string Song2;
    size_t acha;
    size_t acha2;
    size_t acha3;

    //Separando o nome da playlist
    std::cin >> listName;
    acha = listName.find("\0");

    std::cin >> Song1;
    std::cin >> Song2;

    //Procura pela qual song quer add, se ela não existir, cria
    PLAYLIST *curList = list;
    while( (curList->proximoElplaylist != NULL) && (listName.compare(0,(acha-1),curList->nomePlaylist) != 0) ){
        curList = curList->proximoElplaylist;
    }
    if( listName.compare(0,(acha-1),curList->nomePlaylist) == 0 ) {
        MUSICA *curSong = curList->nome;
        MUSICA *antCur = curSong;
        MUSICA *curSong2 = curList->nome;
        MUSICA *antCur2 = curSong2;
        //Separando nome da musica 1
        acha2 = Song1.find("\0");
        //Encontrando musica 1
        curSong = curSong->proximoElmusica;
        while( Song1.compare(0,(acha2-1),curSong->nomeMusica) != 0 ) {
            curSong = curSong->proximoElmusica;
            antCur = antCur->proximoElmusica;
        }
        //Encontrando musica 2
        curSong2 = curSong2->proximoElmusica;
        acha3 = Song2.find("\0");
        while( Song2.compare(0,(acha3-1),curSong2->nomeMusica) != 0 ) {
            curSong2 = curSong2->proximoElmusica;
            antCur2 = antCur2->proximoElmusica;
        }
        std::string aux = curSong->nomeMusica;
        //Trocando posições
        curSong->nomeMusica = curSong2->nomeMusica;
        curSong2->nomeMusica = aux;
    }
    return list;
}

FILA *pls( FILA *queue, FILA **queueH) { // adiciona a música SONG ao final da fila de reprodução e a reproduz se a fila estava anteriormente vazia
    bool status = false;
    std::string op;
    std::cin >> op;
    FILA *novaFila = alocaFila();
    novaFila->musicaAtual = op;
    if( (*queueH)->proximoFila == NULL ) {
        (*queueH)->proximoFila = novaFila;
        novaFila->anteriorFila = NULL;
        novaFila->proximoFila = NULL;
        status = true;
    } else {
        FILA *curFila = (*queueH);
        while( curFila->proximoFila != NULL ) {
            curFila = curFila->proximoFila;
        }
        curFila->proximoFila = novaFila;
        novaFila->anteriorFila = curFila;
        novaFila->proximoFila = NULL;
    }
    if( comando || status ) {
        comando = false;
        return novaFila;
    } else {
        return queue;
    }
}

FILA *plp( FILA *queue, FILA **queueH, PLAYLIST *list) { //limpa a fila de reprodução, adiciona cada uma das músicas da lista de reprodução, em seu estado atual, à fila de reprodução, reproduzindo sua primeira música
    size_t acha;
    std::string op;
    std::cin >> op;
    acha = op.find("\0");
    //Procura a lista
    PLAYLIST *curList = list;
    while( (curList->proximoElplaylist != NULL) && (op.compare(0,(acha-1),curList->nomePlaylist) != 0) ){
        curList = curList->proximoElplaylist;
    }
    //Limpar fila de reprodução
    (*queueH) = clr(*queueH);
    //adicionar as musicas
    MUSICA *curSong = curList->nome;
    while( curSong->proximoElmusica != NULL ){
        FILA *novaFila = alocaFila();
        curSong = curSong->proximoElmusica;
        novaFila->musicaAtual = curSong->nomeMusica;
        if((*queueH)->proximoFila == NULL){
            (*queueH)->proximoFila = novaFila;
            novaFila->anteriorFila = NULL;
            novaFila->proximoFila = NULL;
            queue = (*queueH)->proximoFila;
        }else{
            FILA *curFila2 = (*queueH);
            while( curFila2->proximoFila != NULL ) {
                curFila2 = curFila2->proximoFila;
            }
            curFila2->proximoFila = novaFila;
            novaFila->anteriorFila = curFila2;
            novaFila->proximoFila = NULL;
        }
    }
    comando = false;
    return queue;
}

FILA *nxt( FILA *queue ) {
    if( queue->proximoFila != NULL ) {
        queue = queue->proximoFila;
    } else {
        comando = true;
    }
    return queue;
}

FILA *prv( FILA *queue, FILA *head) {
    if( comando == true ) {
        FILA *cur = head;
        while( cur->proximoFila != NULL ) {
            cur = cur->proximoFila;
        }
        queue = cur;
        comando = false;
    } else if( queue->anteriorFila != NULL ) {
        queue = queue->anteriorFila;
    }
    return queue;
}

FILA *clr( FILA *queue ) {
    //Limpar fila de reprodução
    FILA *curFila = queue;
    while( curFila->proximoFila != NULL ) {
        if( curFila == queue ) {
            FILA *aux = curFila->proximoFila;
            curFila->proximoFila = NULL;
            if( aux->proximoFila != NULL )
                curFila = aux->proximoFila;
            aux->proximoFila = NULL;
            aux->anteriorFila = NULL;
            delete aux;
        } else {
            FILA *aux = curFila;
            if( aux->proximoFila != NULL )
                curFila = aux->proximoFila;
            //curFila = aux->proximoFila;
            aux->proximoFila = NULL;
            aux->anteriorFila = NULL;
            delete aux;
        }
    }
    if( curFila != queue ) {
        curFila->anteriorFila = NULL;
        delete curFila;
    }
    return queue;
}

void inf( FILA *queue, FILA *head ) { //INF, imprime qual o nome da música sendo reproduzida no momento
    FILA *cur = queue;
    if( head->proximoFila == NULL ){
        std::cout << "UNKNOWN" << std::endl;
        return;
    } else if( comando ) {
        std::cout << "UNKNOWN" << std::endl;
        return;
    } else {
        std::cout << cur->musicaAtual << std::endl;
        return;
    }
}