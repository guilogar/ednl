#include <iostream>
#include <cmath>
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"

template <typename tCoste> tCoste taxi(GrafoP<tCoste> tren, GrafoP<tCoste> autobus,
                                       typename GrafoP<tCoste>::vertice origen,
                                       typename GrafoP<tCoste>::vertice destino,
                                       typename GrafoP<tCoste>::tCamino& cam,
                                       tCoste taxi = tCoste())
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t n = tren.numVert();
    
    GrafoP<tCoste> G(n);
    
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if(tren[i][j] < autobus[i][j]) {
                G[i][j] = tren[i][j];
            } else {
                G[i][j] = autobus[i][j];
            }
        }
    }
    
    vector<vertice> dij(n);
    vector<tCoste> sol = Dijkstra<tCoste>(G, origen, dij);
    
    cam = camino<tCoste>(origen, destino, dij);
    
    tCoste total = 0;
    typename GrafoP<tCoste>::tCamino::posicion p = cam.primera();
    vertice v = origen;
    vertice w;
    bool utilizaTren = false;
    
    while(p != cam.fin()) {
        w = cam.elemento(p);
        if(tren[v][w] < autobus[v][w]) {
            total += tren[v][w];
            utilizaTren = true;
        } else {
            total += autobus[v][w] + ((utilizaTren) ? taxi : 0);
            utilizaTren = false;
        }
        p = cam.siguiente(p);
        v = w;
    }
    
    vector<tCoste> solTren = Dijkstra(tren, origen, dij);
    vector<tCoste> solAutobus = Dijkstra(autobus, origen, dij);
    total = std::min(total, std::min(solTren[destino], solAutobus[destino]));
    
    return total;
}
