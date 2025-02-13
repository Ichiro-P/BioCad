#pragma once

#include <usuarioDVO.hpp>

class PersonalTrainer : public Usuario {
public:
    PersonalTrainer(int id, const std::string &login, const std::string &senha, const std::string &nome) : Usuario(id, login, senha, nome, TipoUsuario::PERSONAL_TRAINER) { }
        
    virtual std::vector<std::string> getInterface() const override {
        return {
            "1 - Listar clientes;\n",
            "0 - Sair.\n"
        };
    }
};