/*Developed by Alexandre da Silva */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int>fila;

class Grafo{
        public:
        int cor;
        int **mat;
        int v;
       Grafo(int v);
        void add_aresta(int x,int y);
        void imprimir();
    };

void bfs(Grafo *);
void bfs_recursivo(Grafo *,int *, int *, int *,int);

int main(){

    Grafo G(8);


    G.add_aresta(1,2);
    G.add_aresta(1,3);
    G.add_aresta(3,4);
    G.add_aresta(4,2);
    G.imprimir();
    bfs(&G);
    return 0;
}

Grafo::Grafo(int v){
    this->v = v;
    this->mat = (int**)malloc((v+1)*sizeof(int*));
    for(int c = 0;c <= v;c++){
        this->mat[c] = (int*)malloc((v+1)*sizeof(int));
    }

    for(int c = 0;c <= v;c++){
        for(int b = 0;b <= v;b++){
            this->mat[c][b] = 0;
        }
    }


}

void Grafo::add_aresta(int x,int y){
        this->mat[x][y] = 1;
        this->mat[y][x] = 1;
}

void Grafo::imprimir(){
     for(int c = 1;c <= this->v;c++){
        for(int b = 1;b <= this->v;b++){
            cout << this->mat[c][b];
        }
        cout << endl;
}
}

void bfs(Grafo *G){
    int cor[G->v+1];
    for(int c=0;c <= G->v;c++) cor[c] = 0;
    int dist[G->v+1];
    int ant[G->v+1];
    int u =1;
    fila.push(u);
    cor[u] = 1;
    dist[u] = 0;
  
   bfs_recursivo(G,cor,ant,dist,u);
   int ctd = 0;
   for(int c=1;c <= G->v;c++) if(cor[c] != 0) ctd++;

    if(ctd == G->v) cout << "Grafo Conexo!" << endl;
   }

void bfs_recursivo(Grafo *G,int *cor, int *ant, int *dist,int u){
        fila.pop();
        cout << u << " ";
        for(int c=1;c <= G->v;c++){
            if(G->mat[u][c] == 1 && cor[c] == 0){
                cor[c] = 1;
                dist[c] = dist[u] + 1;
                ant[c] = u;
                fila.push(c);
            }
        }
        cor[u] = 2;
        if(!fila.empty())
        bfs_recursivo(G,cor,ant,dist,fila.front());
}