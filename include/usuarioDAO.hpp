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
};