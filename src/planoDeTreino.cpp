#include <planoDeTreino.hpp>

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <enums.hpp>

PlanoDeTreinoDVO::PlanoDeTreinoDVO(const std::string &cpfCliente, const std::string &nomeCliente, const std::vector<std::string> &objetivosCliente, const std::vector<std::string> &condicaoMedicacliente, const std::string &tipoTreino)
 : cpfCliente(cpfCliente), nomeCliente(nomeCliente), objetivosCliente(objetivosCliente), condicaoMedicaCliente(condicaoMedicaCliente), tipoTreino(tipoTreino) {
    this->cpfCliente.resize(14);
    this->nomeCliente.resize(150);
    this->tipoTreino.resize(150);
}

PlanoDeTreinoDAO::PlanoDeTreinoDAO(std::vector<PlanoDeTreinoDVO> &planos) {
    for(auto &it: planos) {
        this->planosDeTreino.push_back(std::make_unique<PlanoDeTreinoDVO>(it));
    }
}

void PlanoDeTreinoDAO::create(PlanoDeTreinoDVO &plano) {
    if(!plano.getCpfCliente().empty()) planosDeTreino.push_back(std::make_unique<PlanoDeTreinoDVO>(std::move(plano)));
}

void PlanoDeTreinoDAO::remover(PlanoDeTreinoDVO &plano) {
    planosDeTreino.erase(std::remove_if(planosDeTreino.begin(), planosDeTreino.end(),
    [&plano](const std::unique_ptr<PlanoDeTreinoDVO>& it) { return it->getCpfCliente() == plano.getCpfCliente(); }), planosDeTreino.end());
}

void PlanoDeTreinoDAO::update(PlanoDeTreinoDVO &plano) {
    for(auto &&it: planosDeTreino) {
        if(it->getCpfCliente() == plano.getCpfCliente()) {
            it = std::make_unique<PlanoDeTreinoDVO>(std::move(plano));
            break;
        }
    }
}

PlanoDeTreinoDVO PlanoDeTreinoDAO::getPlanoDeTreinoDVO(const std::string &cpfCliente) const& {
    if(cpfCliente.size() == 14) {
        for(auto &&it: planosDeTreino) {
            if(it->getCpfCliente() == cpfCliente) {
                return *it;
            }
        }
    }
    return PlanoDeTreinoDVO();
}

bool PlanoDeTreinoManager::validarCpf(const std::string &cpf) {
    bool existe = true;
    if(cpf.size() != 14) existe = false;
    if(planoDeTreinoDAO->getPlanoDeTreinoDVO(cpf).getCpfCliente().empty()) existe = false;
    return existe;
}

void PlanoDeTreinoManager::adicionarPlanoDeTreino(PlanoDeTreinoDVO &plano) {
    if(!plano.getCpfCliente().empty()) planoDeTreinoDAO->create(plano);
}

void PlanoDeTreinoManager::removerPlanoDeTreino(PlanoDeTreinoDVO &plano) {
    if(!plano.getCpfCliente().empty()) planoDeTreinoDAO->remover(plano);
}

void PlanoDeTreinoManager::atualizarPlanoDeTreino(PlanoDeTreinoDVO &plano) {
    if(!plano.getCpfCliente().empty()) planoDeTreinoDAO->update(plano);
}

PlanoDeTreinoDVO PlanoDeTreinoManager::getPlanoDeTreinoDVO(const std::string &cpf) const& {
    return planoDeTreinoDAO->getPlanoDeTreinoDVO(cpf);
}
