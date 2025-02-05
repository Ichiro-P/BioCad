#pragma once

#include <iostream>
#include <string>
#include <array>

#include <gerente.hpp>
#include <atendente.hpp>
#include <personalTrainer.hpp>
#include <dados.hpp>


class tela {
    const std::string mensagemInicio = "Bem-vindo ao sistema BioCad.\nPara continuar, informe seu id:";
    const std::string mensagemSenha = "Informe tambem sua senha:";
    const std::string mensagemSucesso = "Bem-vindo.\n";
    const std::string mensagemNegado = "Credenciais incorretas. Informe seu id novamente:\n";
    const std::string mensagemTela = "--- Sistema BioCad ---\n";

    const std::array<std::string, 13> mensagemTelaGerente {
        "1.  Listar Clientes;\n",
        "2.  Cadastrar Cliente;\n",
        "3.  Atualizar Cliente;\n",
        "4.  Remover Cliente;\n",
        "5.  Listar Atendentes;\n",
        "6.  Cadastrar Atendente;\n",
        "7.  Remover Atendente;\n",
        "8.  Listar Personal Trainer's;\n",
        "9.  Cadastrar Personal Trainer;\n",
        "a.  Remover Personal Trainer;\n",
        "b.  Atualizar Personal Trainer;\n",
        "c.  Visualizar Relatorio Financeiro;\n",
        "0.  Sair.\n"
    };

    const std::array<std::string, 11> mensagemTelaAtendente {
        "1.  Listar Clientes;\n",
        "2.  Cadastrar Cliente;\n",
        "3.  Atualizar Cliente;\n",
        "4.  Remover Cliente;\n",
        "0.  Sair.\n"
    };

    const std::array<std::string, 3> mensagemTelaPersonalTrainer {
        "1.  Listar Clientes;\n",
        "0.  Sair.\n"
    };

public:
    tela() = default;
    void telaInicial(std::string& id, std::string& senha);
    void telaAcesso(const gerente& eGerente, const atendente& eAtendente, const personalTrainer& ePersonalTrainer, dados& eDados);
    void telaNegado(std::string& id, std::string& senha);

};