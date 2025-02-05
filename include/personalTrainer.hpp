#pragma once

#include <string>

class personalTrainer {
    std::string id;
    std::string senha;
    bool acessoPermitido = false;

    public:
    personalTrainer(const std::string& id, const std::string& senha);
    virtual std::string getId() const&;
    virtual std::string getSenha() const&;
    virtual bool getAcesso() const&;
    bool validarPersonalTrainer();
};