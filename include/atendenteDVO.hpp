#pragma once

#include <usuarioDVO.hpp>

class Atendente : public Usuario {
public:
    Atendente(int id, const std::string &login, const std::string &senha, const std::string &nome) : Usuario(id, login, senha, nome, TipoUsuario::ATENDENTE) { }
        
    virtual std::vector<std::string> getInterfaceOptions() const override {
        return {
            "1 - Cadastrar Cliente",
            "2 - Agendar Aula",
            "3 - Consultar Clientes"
        };
    }
};