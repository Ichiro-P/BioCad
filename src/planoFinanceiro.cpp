#include <vector>
#include <string>
#include <memory>
#include <optional>
#include <algorithm>
#include <planoFinanceiro.hpp>

PlanoFinanceiroDAO::PlanoFinanceiroDAO(std::vector<PlanoFinanceiroDVO> &planos) {
    for(auto &it: planos) {
        this->planos.push_back(std::make_unique<PlanoFinanceiroDVO>(std::move(it)));
    }
}

void PlanoFinanceiroDAO::create(PlanoFinanceiroDVO &plano) {
    planos.push_back(std::make_unique<PlanoFinanceiroDVO>(std::move(plano)));
}

void PlanoFinanceiroDAO::update(PlanoFinanceiroDVO &plano) {
    for(auto &&it: planos) {
        if(it->getNomePlano() == plano.getNomePlano()) {
            it->setTipoPlano(plano.getTipoPlano());
        }
    }
}

void PlanoFinanceiroDAO::remover(PlanoFinanceiroDVO &plano) {
    planos.erase(std::remove_if(planos.begin(), planos.end(),
    [&plano](const std::unique_ptr<PlanoFinanceiroDVO>& it) { return it->getNomePlano() == plano.getNomePlano(); }), planos.end());
}

PlanoFinanceiroDVO PlanoFinanceiroDAO::getPlanoFinanceiroDVO(const std::string &nome) {
    for(auto &it: planos) {
        if(it->getNomePlano() == nome) {
            return *it;
        }
    }
    return PlanoFinanceiroDVO();
}

void PlanoFinanceiroManager::adicionarPlano(PlanoFinanceiroDVO &plano) {
    if(!plano.getNomePlano().empty()) {
        planoFinanceiroDAO->create(plano);
    }
}

void PlanoFinanceiroManager::atualizarPlano(PlanoFinanceiroDVO &plano) {
    if(!plano.getNomePlano().empty()) {
        planoFinanceiroDAO->update(plano);
    }
}

void PlanoFinanceiroManager::removerPlano(PlanoFinanceiroDVO &plano) {
    if(!plano.getNomePlano().empty()) {
        planoFinanceiroDAO->remover(plano);
    }
}
