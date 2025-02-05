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
    int dataRelativaVencimento;
    float valor;
    statusPagamento status = statusPagamento::pendente;

    public:
    mensalidade(const float& valor, const int& dataRelativaVencimento);
    void pagar();
};


class treinoPlano {
    std::vector<std::string> objetivosCliente;
    std::string condicaoMedica;

    public:
    treinoPlano(const std::vector<std::string>& objetivosCliente = {"Ganho de massa muscular"}, const std::string& condicaomedica = "Nenhuma");
};


class plano {
    tipoPlano tipo;
    treinoPlano treino;
    std::vector<mensalidade> mensalidades;

    public:
    plano(const treinoPlano& treino, const int& duracao, const tipoPlano& tipo = tipoPlano::anual);
};

class contrato {
    std::string nomeCliente;
    std::string dataInicio;
    std::string dataVencimento;
    int duracao;

    plano planoVigente;
    public:
    contrato(const std::string& nomeCliente, const std::string& dataInicio, const std::string& dataVencimento, const int& duracao, const plano& planoVigente);
};


class cliente {
    std::string nome;
    int id;
    std::string cpf;
    std::string telefone;
    std::string endereco;
    std::string dataNascimento;
    std::string dataCadastro;

    contrato contratoVigente;
    public:
    cliente(const std::string& nome, const std::string& cpf, const std::string& telefone, const std::string& endereco, const std::string& dataNascimento, const std::string& dataCadastro, const int& duracao, const contrato& contratoVigente);

    virtual int getId() const&;
    virtual std::string getNome() const&;
};