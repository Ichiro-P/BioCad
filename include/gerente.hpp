#pragma once

#include <string>

class gerente {
    std::string id;
    std::string senha;
    bool acessoPermitido = false;

    public:
    gerente(const std::string& id, const std::string& senha);
    virtual std::string getId() const&;
    virtual std::string getSenha() const&;
    virtual bool getAcesso() const&;
    bool validarGerente();
};