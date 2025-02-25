#pragma once

#include <string>
#include <vector>
#include <memory>
#include <optional>
#include <enums.hpp>

class PlanoFinanceiroDVO {
    std::string nomePlano = "";
    TipoPlanoFinanceiro tipoPlano = TipoPlanoFinanceiro::MENSAL;
    public:
    PlanoFinanceiroDVO() = default;
    PlanoFinanceiroDVO(const std::string &nomePlano, const TipoPlanoFinanceiro &tipoPlano) : nomePlano(nomePlano), tipoPlano(tipoPlano) {};

    std::string getNomePlano() const& { return nomePlano; };
    TipoPlanoFinanceiro getTipoPlano() const& { return tipoPlano; };

    void setNomePlano(const std::string &novoNome) { nomePlano = novoNome; }
    void setTipoPlano(const TipoPlanoFinanceiro &novoTipoPlano) { tipoPlano = novoTipoPlano; }
};

class PlanoFinanceiroDAO {
    std::vector<std::unique_ptr<PlanoFinanceiroDVO>> planos = {}; 
    public:
    PlanoFinanceiroDAO() = default;
    PlanoFinanceiroDAO(std::vector<PlanoFinanceiroDVO> &planos);
    void create(PlanoFinanceiroDVO &plano);
    void update(PlanoFinanceiroDVO &plano);
    void remover(PlanoFinanceiroDVO &plano);
    PlanoFinanceiroDVO getPlanoFinanceiroDVO(const std::string &nome);
};

class PlanoFinanceiroManager {
    std::unique_ptr<PlanoFinanceiroDAO> planoFinanceiroDAO = nullptr;
    public:
    PlanoFinanceiroManager() = default;
    PlanoFinanceiroManager(PlanoFinanceiroDAO &&planoFinanceiroDAO) : planoFinanceiroDAO(std::make_unique<PlanoFinanceiroDAO>(std::move(planoFinanceiroDAO))) {};
    void adicionarPlano(PlanoFinanceiroDVO &plano);
    void atualizarPlano(PlanoFinanceiroDVO &plano);
    void removerPlano(PlanoFinanceiroDVO &plano);
    PlanoFinanceiroDVO getPlanoFinanceiroDVO(const std::string &nome) const& ;
};