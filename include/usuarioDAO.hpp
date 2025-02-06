#pragma once

#include <usuarioDVO.hpp>
#include <memory>
#include <string>
#include <vector>

class UsuarioDAO {
private:
    std::vector<std::shared_ptr<Usuario>> usuarios;
public:
    UsuarioDAO();
    std::shared_ptr<Usuario> buscarPorLogin(const std::string &login);
    std::shared_ptr<Usuario> buscarPorId(int id);

    bool adicionar(const std::shared_ptr<Usuario> usuario);
    bool atualizar(const std::shared_ptr<Usuario> usuario);
    bool remover(int id);
    std::vector<std::shared_ptr<Usuario>> listar();
};