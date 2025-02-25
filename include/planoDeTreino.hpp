#pragma once

#include <string>
#include <vector>
#include <memory>
#include <enums.hpp>


class PlanoDeTreinoDVO {
    std::string cpfCliente = "";
    std::string nomeCliente = "";
    std::vector<std::string> objetivosCliente = {"Ganho de massa"};
    std::vector<std::string> condicaoMedicaCliente = { "Nenhuma" };
    std::string tipoTreino = "Flexao a rodo";
    public:
    PlanoDeTreinoDVO() = default;
    PlanoDeTreinoDVO(const std::string &cpfCliente, const std::string &nomeCliente, const std::vector<std::string> &objetivosCliente, const std::vector<std::string> &condicaoMedicacliente, const std::string &tipoTreino);
    std::string getCpfCliente() const& { return cpfCliente; };
    std::string getNomeCliente() const& { return nomeCliente; };
    std::vector<std::string> getObjetivosCliente() const& { return objetivosCliente; };
    std::vector<std::string> getCondicaoMedicaCliente() const& { return condicaoMedicaCliente; };
    std::string getTipoTreino() const& { return tipoTreino; };

    void setCpfCliente(const std::string &novoCpf) { if(novoCpf.size() == 14) cpfCliente = novoCpf; };
    void setNomeCliente(const std::string &novoNome) { if(novoNome.size() <= 150) nomeCliente = novoNome; };
    void setObjetivosCliente(const std::vector<std::string> &novosObjetivos) { objetivosCliente = novosObjetivos; };
    void setCondicaoMedicaCliente(const std::vector<std::string> &novasCondicoes) { condicaoMedicaCliente = novasCondicoes; };
    void setTipoTreino(const std::string &novoTipo) { tipoTreino = novoTipo; };
};

class PlanoDeTreinoDAO {
    std::vector<std::unique_ptr<PlanoDeTreinoDVO>> planosDeTreino;
    public:
    PlanoDeTreinoDAO() = default;
    PlanoDeTreinoDAO(std::vector<PlanoDeTreinoDVO> &planos);
    void create(PlanoDeTreinoDVO &plano);
    void remover(PlanoDeTreinoDVO &plano);
    void update(PlanoDeTreinoDVO &plano);
    PlanoDeTreinoDVO getPlanoDeTreinoDVO(const std::string &cpfCliente) const&;
};

class PlanoDeTreinoManager {
    std::unique_ptr<PlanoDeTreinoDAO> planoDeTreinoDAO = nullptr;
    public:
    PlanoDeTreinoManager(PlanoDeTreinoDAO &&planoDeTreinoDAO) : planoDeTreinoDAO(std::make_unique<PlanoDeTreinoDAO>(std::move(planoDeTreinoDAO))) {};
    bool validarCpf(const std::string &cpf);
    void adicionarPlanoDeTreino(PlanoDeTreinoDVO &plano);
    void removerPlanoDeTreino(PlanoDeTreinoDVO &plano);
    void atualizarPlanoDeTreino(PlanoDeTreinoDVO &plano);
    PlanoDeTreinoDVO getPlanoDeTreinoDVO(const std::string &cpf) const&;
};