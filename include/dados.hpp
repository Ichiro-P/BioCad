#pragma once

#include <vector>
#include <string>
#include <gerente.hpp>
#include <atendente.hpp>
#include <cliente.hpp>


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
        "Irineu Pereira dos Santos", 
        "01/02/2025",
        "01/02/2026",
        12,
        planos.at(0)
    )
};

std::vector<cliente> clientes {
    cliente(
        "Irineu Pereira dos Santos",
        "123.456.789-00",
        "(44)92001-3020",
        "R. Jose boiko n. 13",
        "11/11/2001",
        "01/02/2025",
        12,
        contratos.at(0)
    )
};
std::vector<atendente> atendentes;

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