#include <iostream>
#include <array>

#include <tela.hpp>
#include <gerente.hpp>
#include <atendente.hpp>
#include <personalTrainer.hpp>
#include <dados.hpp>

void tela::telaInicial(std::string& id, std::string& senha) {
    std::cout << mensagemInicio;
    std::getline(std::cin, id);
    std::cout << mensagemSenha;
    std::getline(std::cin, senha);
}

void tela::telaAcesso(const gerente& eGerente, const atendente& eAtendente, const personalTrainer& ePersonalTrainer, dados& eDados) {
    int entrada;
    std::cout << mensagemSucesso << mensagemTela;
    if(eGerente.getAcesso()) {
        do {
            for(const auto& msg: mensagemTelaGerente) std::cout << msg;
            std::cin >> entrada;
            switch(entrada) {
                case 1:
                eDados.listarClientes();
                break;
                case 2:
                eDados.cadastrarCliente();
                break;
                case 3:
                eDados.atualizarCliente();
                break;
                case 4:
                eDados.removerCliente();
                break;
                case 5:
                eDados.listarAtendentes();
                break;
                case 6:
                eDados.cadastrarAtendente();
                break;
                case 7:
                eDados.atualizarAtendente();
                break;
                case 8:
                eDados.removerAtendente();
                break;
                case 9:
                eDados.listarPersonalTrainers();
                break;
                case 'a':
                eDados.cadastrarPersonalTrainer();
                break;
                case 'b':
                eDados.atualizarPersonalTrainer();
                break;
                case 'c':
                eDados.removerPersonalTrainer();
                break;
                case 0:
                break;
            }
        } while (entrada != 'a' && entrada < 0 && entrada > 9);
    } else if (eAtendente.getAcesso()) {
        do {
            for(const auto& msg: mensagemTelaAtendente) std::cout << msg;
            std::cin >> entrada;
            switch(entrada) {
                case 1:
                eDados.listarClientes();
                break;
                case 2:
                eDados.cadastrarCliente();
                break;
                case 3:
                eDados.atualizarCliente();
                break;
                case 4:
                eDados.removerCliente();
                break;
                case 0:
                break;
            }
        } while (entrada < 0 && entrada > 4);
    } else if (ePersonalTrainer.getAcesso()){
        do {
            for(const auto& msg: mensagemTelaPersonalTrainer) std::cout << msg;
            std::cin >> entrada;
            switch(entrada) {
                case 1:
                eDados.listarClientes();
                break;
                case 0:
                break;
            }
        } while (entrada < 0 && entrada > 1);
    }
}

void tela::telaNegado(std::string& id, std::string& senha) {
    std::cout << mensagemNegado;
    std::getline(std::cin, id);
    std::cout << mensagemSenha;
    std::getline(std::cin, senha);
}
