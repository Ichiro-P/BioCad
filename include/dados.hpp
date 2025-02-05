#pragma once

#include <vector>
#include <string>
#include <gerente.hpp>
#include <atendente.hpp>
#include <cliente.hpp>


class dados {
    std::vector<treinoPlano> treinos;
    std::vector<plano> planos;
    std::vector<contrato> contratos;
    std::vector<cliente> clientes;
    std::vector<atendente> atendentes;


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