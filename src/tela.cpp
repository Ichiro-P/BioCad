#include <iostream>
#include <array>

#include <tela.hpp>
#include <gerente.hpp>
#include <atendente.hpp>
#include <dados.hpp>

void tela::telaInicial(std::string& id, std::string& senha) {
    std::cout << mensagemInicio;
    std::getline(std::cin, id);
    std::cout << mensagemSenha;
    std::getline(std::cin, senha);
}

void tela::telaAcesso(const gerente& eGerente, const atendente& eAtendente) {
    int entrada;
    std::cout << mensagemSucesso << mensagemTela;
    if(eGerente.getAcesso()) {
        do {
            for(const auto& msg: mensagemTelaGerente) std::cout << msg;
            std::cin >> entrada;
            switch(entrada) {
                case 1:
                listarClientes();
                break;
                case 2:
                cadastrarCliente();
                break;
                case 3:
                atualizarCliente();
                break;
                case 4:
                removerCliente();
                break;
                case 5:
                listarAtendentes();
                break;
                case 6:
                cadastrarAtendente();
                break;
                case 7:
                atualizarAtendente();
                break;
                case 8:
                removerAtendente();
                break;
                case 9:
                listarPersonalTrainers();
                break;
                case 'a':
                cadastrarPersonalTrainer();
                break;
                case 'b':
                atualizarPersonalTrainer();
                break;
                case 'c':
                removerPersonalTrainer();
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
                listarClientes();
                break;
                case 2:
                cadastrarCliente();
                break;
                case 3:
                atualizarCliente();
                break;
                case 4:
                removerCliente();
                break;
                case 0:
                break;
            }
        } while (entrada < 0 && entrada > 4);
    } else {
        do {
            for(const auto& msg: mensagemTelaPersonalTrainer) std::cout << msg;
            std::cin >> entrada;
            switch(entrada) {
                case 1:
                listarClientes();
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
