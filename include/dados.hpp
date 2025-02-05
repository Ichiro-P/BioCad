#pragma once

#include <vector>
#include <string>
#include <gerente.hpp>
#include <atendente.hpp>
#include <cliente.hpp>
#include <personalTrainer.hpp>

class dados {
    std::vector<treinoPlano> treinos {
        treinoPlano()
    };
    std::vector<plano> planos {
        plano(
            treinos.at(0), 
            12
        )
    };
    std::vector<contrato> contratos {
        contrato(
            "Ireneu Aquino Rego",
            "05/02/2025",
            "05/02/2026",
            12,
            planos.at(0)
        )
    };
    std::vector<cliente> clientes {
        cliente(
            "Ireneu Aquino Rego",
            "123.456.789-10",
            "(44)92000-6969",
            "Av. Jacinto de Aquino Rego n.69",
            "01/11/1991",
            "05/02/2025",
            12,
            contratos.at(0)
        )
    };
    std::vector<atendente> atendentes {
        atendente(
            "lucianapaes",
            "1232"
        )
    };
    std::vector<personalTrainer> personalTrainers {
        personalTrainer(
            "eduardo",
            "4545"
        )
    };

public:
    dados() = default;
    void visualizarRelatorioFinanceiro();

    void listarClientes();
    void cadastrarCliente();
    void atualizarCliente();
    void removerCliente();

    void listarAtendentes();
    void cadastrarAtendente();
    void atualizarAtendente();
    void removerAtendente();

    void listarPersonalTrainers();
    void cadastrarPersonalTrainer();
    void atualizarPersonalTrainer();
    void removerPersonalTrainer();
};