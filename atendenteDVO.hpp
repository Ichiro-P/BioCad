#pragma once

#include <usuarioDVO.hpp>

class Atendente : public Usuario {
public:
    Atendente(int id, const std::string &login, const std::string &senha, const std::string &nome) : Usuario(id, login, senha, nome, TipoUsuario::ATENDENTE) { }
        
    virtual std::vector<std::string> getInterfaceOptions() const override {
        return {
            "1 - Listar clientes;\n",
            "2 - Cadastrar cliente;\n",
            "0 - Sair.\n"
        };
    }
};