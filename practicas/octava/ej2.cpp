#include <iostream>
#include <cmath>
#include <set>
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

#ifndef EJ2
#define EJ2

template <typename tCoste> struct LineaAerea {
    typedef typename Grafo::vertice vertice;
    vertice origen_, destino_;
    vertice r_origen_, r_destino_;
    tCoste coste_;
    LineaAerea(vertice origen = vertice(), vertice destino = vertice(), tCoste coste = tCoste(),
               vertice r_origen = vertice(), vertice r_destino = vertice()) :
               origen_(origen), destino_(destino), coste_(coste),
               r_origen_(r_origen), r_destino_(r_destino) {}
    bool operator == (const LineaAerea& l) const {
        return ((l.r_origen_ == r_origen_ && l.r_destino_ == r_destino_) ||
               (l.r_origen_ == r_destino_ && l.r_destino_ == r_origen_));
    }
    bool operator < (const LineaAerea& l) const {
        return coste_ < l.coste_;
    }
};

template <typename tCoste> std::set<LineaAerea<tCoste>> tombuctu2(vector<ciudad<tCoste>> ciudades, Grafo G) {
    typedef typename Grafo::vertice vertice;
    const size_t n = G.numVert();
    Particion islas(n);
    GrafoP<tCoste> m(n);
    size_t numIslas = n;
    
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if(G[i][j] && i != j) {
                islas.unir(islas.encontrar(i), islas.encontrar(j));
                numIslas--;
            }
        }
    }
    
    std::set<LineaAerea<tCoste>> lineasAereas;
    typename std::set<LineaAerea<tCoste>>::iterator it;
    
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if(islas.encontrar(i) != islas.encontrar(j)) {
                double c1 = ciudades[i].x_ - ciudades[j].x_;
                double c2 = ciudades[i].y_ - ciudades[j].y_;
                double distancia = sqrt((c1*c1) + (c2*c2));
                m[i][j] = distancia;
                
                LineaAerea<tCoste> l(i, j, distancia, islas.encontrar(i), islas.encontrar(j));
                
                for (it = lineasAereas.begin(); it != lineasAereas.end(); ++it) {
                    if(*it == l) break;
                }
                if(it != lineasAereas.end()) {
                    if(distancia < it->coste_) {
                        lineasAereas.erase(it);
                        lineasAereas.insert(l);
                    }
                } else {
                    lineasAereas.insert(l);
                }
            }
        }
    }
    return lineasAereas;
}
#endif
