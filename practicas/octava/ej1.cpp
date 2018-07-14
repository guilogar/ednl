#include <iostream>
#include <cmath>
#include "../grafos/grafoMA.h"
#include "../grafos/alg_grafoMA.h"
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"
#include "../grafos/particion.h"

#ifndef Ciudad
#define Ciudad
template <typename tCoste> struct ciudad {
    tCoste x_, y_;
    ciudad(tCoste x = tCoste(), tCoste y = tCoste()) : x_(x), y_(y) {}
};
#endif

#ifndef EJ1
#define EJ1

template <typename tCoste> matriz<tCoste> tombuctu(vector<ciudad<tCoste>> ciudades, Grafo G, Particion& P) {
    typedef typename Grafo::vertice vertice;
    const size_t n = G.numVert();
    Particion pc(n);
    GrafoP<tCoste> m(n);
    
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if(G[i][j]) {
                pc.unir(pc.encontrar(i), pc.encontrar(j));
                double c1 = ciudades[i].x_ - ciudades[j].x_;
                double c2 = ciudades[i].y_ - ciudades[j].y_;
                double distancia = sqrt((c1*c1) + (c2*c2));
                
                m[i][j] = distancia;
            }
        }
    }
    P = pc;
    
    matriz<vertice> flo;
    return Floyd(m, flo);
}
#endif
