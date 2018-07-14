#include <iostream>
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"

template <typename tCoste> tCoste almacen(GrafoP<tCoste> G, vector<tCoste> subvencion,
                                          vector<int> capacidadAlmacenCiudad,
                                          typename GrafoP<tCoste>::vertice centroProduccion,
                                          tCoste cantidadProducto,
                                          vector<int>& cantidadAlmacenadaCiudad) {
    
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t n = G.numVert();
    
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if(G[i][j] != GrafoP<tCoste>::INFINITO && subvencion[j] > 0) {
                G[i][j] = (G[i][j] * subvencion[j]) / 100;
            }
        }
    }
    vector<vertice> dij;
    vector<tCoste> destinosOptimizados = Dijkstra<tCoste>(G, centroProduccion, dij);
    
    tCoste costeTotal = 0;
    while(cantidadProducto > 0) {
        size_t menor = GrafoP<tCoste>::INFINITO;
        size_t menor_indice = 0;
        for (size_t i = 0; i < n; i++) {
            if(i != centroProduccion && destinosOptimizados[i] < menor) {
                menor = destinosOptimizados[i];
                menor_indice = i;
            }
        }
        costeTotal += destinosOptimizados[menor_indice];
        destinosOptimizados[menor_indice] = GrafoP<tCoste>::INFINITO;
        
        if(cantidadProducto > capacidadAlmacenCiudad[menor_indice]) {
            cantidadAlmacenadaCiudad[menor_indice] = capacidadAlmacenCiudad[menor_indice];
        } else {
            cantidadAlmacenadaCiudad[menor_indice] = cantidadProducto;
        }
        cantidadProducto -= capacidadAlmacenCiudad[menor_indice];
    }
    
    return costeTotal;
}
