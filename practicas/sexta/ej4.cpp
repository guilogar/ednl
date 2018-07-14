#include <iostream>
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"
#include "../grafos/pilaenla.h"
#include "./ej1.cpp"

template <typename tCoste> GrafoP<tCoste> zuelandia(GrafoP<tCoste> G,
                                          vector<bool> ciudadesTomadas,
                                          vector<vector<bool>> carreterasTomadas,
                                          typename GrafoP<tCoste>::vertice capital) {
    
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t n = G.numVert();
    
    for (size_t i = 0; i < n; i++) {
        if(ciudadesTomadas[i]) {
            for (int j = 0; j < n; j++) {
                G[i][j] = GrafoP<tCoste>::INFINITO;
                G[j][i] = GrafoP<tCoste>::INFINITO;
            }
        }
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if(carreterasTomadas[i][j])
                G[i][j] = GrafoP<tCoste>::INFINITO;
        }
    }
    vector< GrafoP<int>::vertice > dij, dijInv;
    vector<tCoste> costeMinimoHastaCapital = DijkstraInv<tCoste>(G, capital, dij);
    vector<tCoste> costeMinimoDesdeCapital = Dijkstra<tCoste>(G, capital, dijInv);
    
    GrafoP<tCoste> sol(n);
    
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if(i == j)
                sol[i][j] = 0;
            else
                sol[i][j] = suma(costeMinimoHastaCapital[i], costeMinimoDesdeCapital[j]);
        }
    }
    return sol;
}
