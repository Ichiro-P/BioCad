#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>


#include <tela.hpp>
#include <gerente.hpp>
#include <atendente.hpp>
#include <cliente.hpp>
#include <hashes.hpp>

int main() {
    std::string id;
    std::string senha;

    tela telaSistema;
    
    telaSistema.telaInicial(id, senha);

    gerente Gerente = gerente(id, senha);
    atendente Atendente = atendente(id, senha);

    Gerente.validarGerente(hashGerente);
    Atendente.validarAtendente(hashesAtendente);

    while(!Gerente.getAcesso() && !Atendente.getAcesso()) {
        telaSistema.telaNegado(id, senha);


        Gerente = gerente(id, senha);
        Atendente = atendente(id, senha);

        Gerente.validarGerente(hashGerente);
        Atendente.validarAtendente(hashesAtendente);
    }
    telaSistema.telaAcesso(Gerente, Atendente);
}