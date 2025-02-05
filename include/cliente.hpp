#pragma once

#include <string>
#include <vector>

enum class tipoPlano {
    mensal,
    trimestral,
    anual
};

enum class statusPagamento {
    pendente,
    pago
};

class mensalidade {
    std::string dataVencimento;
    float valor;
    statusPagamento status;
};


class treinoPlano {
    std::vector<std::string> objetivosCliente;
    std::string condicaoMedica;
};


class plano {
    std::string nomePlano;
    tipoPlano tipoPlano;
    treinoPlano treino;
    std::vector<mensalidade> mensalidades;
};

class contrato {
    std::string nomeCliente;
    std::string dataInicio;
    std::string dataVencimento;

    plano planoVigente;
};


class cliente {
    std::string nome;
    int id;
    std::string CPF;
    std::string telefone;
    std::string endereco;
    std::string dataNascimento;
    std::string dataCadastro;

    contrato contratoVigente;
};