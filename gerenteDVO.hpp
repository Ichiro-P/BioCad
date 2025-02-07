#pragma once

#include <usuarioDVO.hpp>


class Gerente : public Usuario {
public:
    Gerente(int id, const std::string &login, const std::string &senha, const std::string &nome)
        : Usuario(id, login, senha, nome, TipoUsuario::GERENTE) { }
        
    virtual std::vector<std::string> getInterfaceOptions() const override {
        return {
            "1 - Listar clientes;\n",
            "2 - Cadastrar cliente;\n",
            "3 - Listar atendentes;\n",
            "4 - Cadastrar atendente;\n",
            "5 - Listar personal trainers;\n",
            "6 - Cadastrar personal trainer;\n",
            "0 - Sair.\n"
        };
    }
};