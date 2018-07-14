#include <iostream>
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"

template <typename tCoste> double pseudoCentroGrafo(const GrafoP<tCoste> G) {
    
    typedef typename GrafoP<tCoste>::vertice vertice;
    vertice pseudoCentro = 0, nma = 0, nma2 = 0;
    const size_t n = G.numVert();
    double diametro = 0.0;
    
    for (size_t i = 0; i < n; i++) {
        nma = 0, nma2 = 0;
        for (size_t j = 0; j < n; j++) {
            if(G[i][j] != GrafoP<tCoste>::INFINITO && G[i][j] >= G[i][nma]) {
                nma = j;
            }
        }
        for (size_t k = 0; k < n; k++) {
            if(G[i][k] != GrafoP<tCoste>::INFINITO && G[i][k] >= G[i][nma2] && k != nma) {
                nma2 = k;
            }
        }
        tCoste sum = suma(G[i][nma], G[i][nma2]);
        if(sum != GrafoP<tCoste>::INFINITO && sum > diametro) {
            diametro = suma(G[i][nma], G[i][nma2]);
            pseudoCentro = i;
        }
    }
    std::cout << "El pseudo centro de este grafo es => " << pseudoCentro << ", con un diametro de " << diametro << std::endl;
    return diametro;
}
