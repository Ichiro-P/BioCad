#pragma once

#include <string>
#include <vector>
#include <chrono>
#include <memory>
#include <planoFinanceiro.hpp>
#include <enums.hpp>

class ContratoDVO {
    std::string cpfCliente = "";
    std::string nomeCliente = "";
    CondicaoContrato condicao = CondicaoContrato::ATIVO;
    std::shared_ptr<PlanoFinanceiroDVO> plano = nullptr;
    std::chrono::system_clock::time_point dataInicio = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point dataFim = std::chrono::system_clock::now();

    public:
    ContratoDVO() = default;
    ContratoDVO(const std::string &cpfCliente, const std::string &nomeCliente, const CondicaoContrato &condicao, const PlanoFinanceiroDVO &planoDVO, int dia, int mes, int ano);

    std::string getCpfCliente() const& { return cpfCliente; };
    std::string getNomeCliente() const& { return nomeCliente; };
    CondicaoContrato getCondicao() const& { return condicao; };
    PlanoFinanceiroDVO getPlano() const& { return *plano; };
    std::chrono::system_clock::time_point getDataInicio() const& { return dataInicio; };
    std::chrono::system_clock::time_point getFim() const& { return dataFim; };

    void setCpfCliente(const std::string &novoCpf);
    void setNomeCliente(const std::string &novoNome);
    void setCondicao(const CondicaoContrato &novaCondicao);
    void setDataFim(int dia, int mes, int ano);
};

class ContratoDAO {
    std::vector<std::unique_ptr<ContratoDVO>> contratos = {};
    public:
    ContratoDAO() = default;
    ContratoDAO(std::vector<ContratoDVO> &contratos);
    void create(ContratoDVO &contrato);
    void update(ContratoDVO &contrato);
    ContratoDVO getContratoDVO(const std::string &cpfCliente) const&;
};

class ContratoManager {
    std::unique_ptr<ContratoDAO> contratoDAO = nullptr;
    public:
    ContratoManager() = default;
    ContratoManager(ContratoDAO &&contratoDAO) : contratoDAO(std::make_unique<ContratoDAO>(std::move(contratoDAO))) {};
    bool validarCpf(const std::string &cpf);
    bool validarContrato(const ContratoDVO &contrato);
    void salvarContrato(ContratoDVO &contrato);
    void atualizarContrato(ContratoDVO &contrato);
    bool setContratoCancelado(ContratoDVO &contrato);
    ContratoDVO renovarContrato(ContratoDVO &contrato, const std::tm novaDataFim) const&;
    ContratoDVO getContratoDVO(const std::string &cpfCliente) const&;
};