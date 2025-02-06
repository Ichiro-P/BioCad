#pragma once

#include <usuarioDVO.hpp>


class Gerente : public Usuario {
public:
    Gerente(int id, const std::string &login, const std::string &senha, const std::string &nome)
        : Usuario(id, login, senha, nome, TipoUsuario::GERENTE) { }
        
    virtual std::vector<std::string> getInterfaceOptions() const override {
        return {
            "1 - Gerenciar Funcionários",
            "2 - Gerar Relatórios Financeiros",
            "3 - Controlar Acesso e Cadastros",
            "4 - Configurar Sistema"
        };
    }
};