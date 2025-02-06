#pragma once

#include <usuarioDAO.hpp>
#include <usuarioDVO.hpp>
#include <memory>
#include <string>
#include <stdexcept>

class LoginManager {
private:
    std::unique_ptr<UsuarioDAO> usuarioDAO;
public:
    LoginManager(UsuarioDAO* dao) : usuarioDAO(dao) {}
    
    std::shared_ptr<Usuario> autenticar(const std::string &login, const std::string &senha);
};