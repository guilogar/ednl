#include <iostream>
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"
#include "../grafos/pilaenla.h"

template <typename tCoste> double laberinto(int n, Pila<typename GrafoP<tCoste>::arista> paredes,
                                            typename GrafoP<tCoste>::vertice entrada,
                                            typename GrafoP<tCoste>::vertice salida,
                                            typename GrafoP<tCoste>::tCamino& cam)
{
    GrafoP<tCoste> G(n*n);
    typedef typename GrafoP<tCoste>::vertice vertice;
    typedef typename GrafoP<tCoste>::arista arista;
    const size_t n_vertices = G.numVert();
    
    for (size_t i = 0; i < n_vertices; i++) {
        for (size_t j = 0; j < n_vertices; j++) {
            if(i == j) G[i][j] = 0;
            else {
                if(i >= n && i < ((n-1)*n)) {
                    G[i][i-n] = 1;
                    G[i][i+n] = 1;
                } else if(i < n) {
                    G[i][i+n] = 1;
                } else if(i >= ((n-1)*n)) {
                    G[i][i-n] = 1;
                }
                
                if(i % n > 0 && i % n < (n - 1)) {
                    G[i][i+1] = 1;
                    G[i][i-1] = 1;
                } else if(i % n == 0) {
                    G[i][i+1] = 1;
                } else if(i % n == (n - 1)) {
                    G[i][i-1] = 1;
                }
            }
        }
    }
    while(!paredes.vacia()) {
        arista a = paredes.tope();
        paredes.pop();
        G[a.orig][a.dest] = GrafoP<tCoste>::INFINITO;
    }
    
    vector<vertice> dij;
    vector<tCoste> sol = Dijkstra(G, entrada, dij);
    
    cam = camino<tCoste>(entrada, salida, dij);
    
    return sol[salida];
}
