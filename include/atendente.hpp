#pragma once

#include <string>
#include <vector>

class atendente {
    std::string id;
    std::string senha;
    bool acessoPermitido = false;

    public:
    atendente(const std::string& id, const std::string& senha);
    virtual std::string getId() const&;
    virtual std::string getSenha() const&;
    virtual bool getAcesso() const&;
    bool validarAtendente();
};