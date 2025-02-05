#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>


#include <tela.hpp>
#include <gerente.hpp>
#include <atendente.hpp>
#include <personalTrainer.hpp>
#include <cliente.hpp>
#include <dados.hpp>

int main() {
    dados Dados;

    std::string id;
    std::string senha;

    tela telaSistema;
    
    telaSistema.telaInicial(id, senha);

    gerente Gerente = gerente(id, senha);
    atendente Atendente = atendente(id, senha);
    personalTrainer PersonalTrainer = personalTrainer(id, senha);

    Gerente.validarGerente();
    Atendente.validarAtendente();
    PersonalTrainer.validarPersonalTrainer();

    while(!Gerente.getAcesso() && !Atendente.getAcesso() && !PersonalTrainer.getAcesso()) {
        telaSistema.telaNegado(id, senha);


        Gerente = gerente(id, senha);
        Atendente = atendente(id, senha);
        PersonalTrainer = personalTrainer(id, senha);

        Gerente.validarGerente();
        Atendente.validarAtendente();
        PersonalTrainer.validarPersonalTrainer();
    }
    telaSistema.telaAcesso(Gerente, Atendente, PersonalTrainer, Dados);
    return 0;
}