#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>


#include <gerente.hpp>
#include <atendente.hpp>
#include <cliente.hpp>
#include <hashes.hpp>

int main() {
    const std::string mensagemInicio = "Bem-vindo ao sistema BioCad.\nPara continuar, informe seu id:\n";
    const std::string mensagemSenha = "Informe tambem sua senha:\n";
    const std::string mensagemSucesso = "Bem-vindo.\n";
    const std::string mensagemNegado = "Credenciais incorretas. Informe seu id novamente:\n";

    const std::string mensagemTela = "--- Sistema BioCad ---\n";

    const std::array<std::string, 11> mensagemTelaAtendente {
        "1.  Listar Clientes;\n",
        "2.  Cadastrar Cliente;\n",
        "3.  Atualizar Cliente;\n",
        "4.  Remover Cliente;\n",
        "0.  Sair.\n"
    };

    const std::array<std::string, 3> mensagemTelaPersonalTrainer {
        "1.  Listar Clientes;\n",
        "2.  Listar Personal Trainer's;\n",
        "0.  Sair.\n"
    };

    const std::array<std::string, 12> mensagemTelaGerente {
        "a.  Listar Relatorio Financeiro;\n",
        "1.  Listar Clientes;\n",
        "2.  Cadastrar Cliente;\n",
        "3.  Atualizar Cliente;\n",
        "4.  Remover Cliente;\n",
        "5.  Listar Atendentes;\n",
        "6.  Cadastrar Atendente;\n",
        "7.  Remover Atendente;\n",
        "8.  Listar Personal Trainer's;\n",
        "8.  Cadastrar Personal Trainer;\n",
        "9.  Remover Personal Trainer;\n",
        "0.  Sair.\n"
    };

    std::string id;
    std::string senha;
    std::cout << mensagemInicio;
    std::getline(std::cin, id);
    std::cout << mensagemSenha;
    std::getline(std::cin, senha);

    gerente Gerente = gerente(id, senha);
    atendente Atendente = atendente(id, senha);

    bool eGerente = Gerente.validarGerente(hashGerente);
    bool eAtendente = Atendente.validarAtendente(hashesAtendente);

    while(!eGerente && !eAtendente) {
        std::cout << mensagemNegado;
        std::getline(std::cin, id);
        std::cout << mensagemSenha;
        std::getline(std::cin, senha);


        Gerente = gerente(id, senha);
        Atendente = atendente(id, senha);

        eGerente = Gerente.validarGerente(hashGerente);
        eAtendente = Atendente.validarAtendente(hashesAtendente);
    }
    int entrada;
    if(eGerente) {
        do {
            std::cout << mensagemSucesso << mensagemTela;
            for(const auto& msg: mensagemTelaGerente) std::cout << msg;
            std::cin >> entrada;
            switch(entrada) {
                case 'a':
                break;
                case 1:
                break;
                case 2:
                break;
                case 3:
                break;
                case 4:
                break;
                case 5:
                break;
                case 6:
                break;
                case 7:
                break;
                case 8:
                break;
                case 9:
                break;
                case 0:
                return 0;
            }
        } while (entrada != 'a' && entrada < 0 && entrada > 9);
    } else if (eAtendente) {
        do {
            std::cout << mensagemSucesso << mensagemTela;
            for(const auto& msg: mensagemTelaAtendente) std::cout << msg;
            std::cin >> entrada;
            switch(entrada) {
                case 1:
                break;
                case 2:
                break;
                case 3:
                break;
                case 4:
                break;
                case 0:
                return 0;
            }
        } while (entrada < 0 && entrada > 4);
    }
}