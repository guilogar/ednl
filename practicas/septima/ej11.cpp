#include <iostream>
#include "../grafos/grafoPMC.h"
#include "../grafos/alg_grafoPMC.h"
#include <map>
#include <vector>

template <typename tCoste> matriz<tCoste> huries(GrafoP<tCoste> isla1, GrafoP<tCoste> isla2, GrafoP<tCoste> isla3,
                                                 vector<std::map<typename GrafoP<tCoste>::vertice, tCoste>> puentes)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t n = isla1.numVert() + isla2.numVert() + isla3.numVert();
    
    GrafoP<tCoste> archipielago(n);
    size_t i = 0;
    
    for (i = i; i < isla1.numVert(); i++) {
        for (size_t j = 0; j < n; j++) {
            if(j >= isla1.numVert())
                archipielago[i][j] = GrafoP<tCoste>::INFINITO;
            else
                archipielago[i][j] = isla1[i][j];
        }
    }
    for (size_t j = 0; i < isla1.numVert() + isla2.numVert(); i++, j++) {
        for (size_t k = isla1.numVert(), h = 0; k < n; k++, h++) {
            if(h >= isla2.numVert())
                archipielago[i][k] = GrafoP<tCoste>::INFINITO;
            else
                archipielago[i][k] = isla2[j][h];
        }
    }
    for (size_t j = 0; i < n; i++, j++) {
        for (size_t k = isla1.numVert() + isla2.numVert(), h = 0; k < n; k++, h++) {
            if(h >= isla3.numVert())
                archipielago[i][k] = GrafoP<tCoste>::INFINITO;
            else
                archipielago[i][k] = isla3[j][h];
        }
    }
    for (size_t i = 0; i < puentes.size(); i++) {
        if(!puentes[i].empty()) {
            for (auto ciudad : puentes[i]) {
                archipielago[i][ciudad.first] = ciudad.second;
                archipielago[ciudad.first][i] = ciudad.second;
            }
        }
    }
    matriz<vertice> flo(n);
    return Floyd<tCoste>(archipielago, flo);
}
