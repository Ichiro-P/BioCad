#pragma once

#include <usuarioDAO.hpp>
#include <usuarioDVO.hpp>
#include <memory>
#include <string>
#include <stdexcept>

class LoginManager {
private:
    std::shared_ptr<UsuarioDAO> usuarioDAO;
public:
    LoginManager(std::shared_ptr<UsuarioDAO> dao) : usuarioDAO(dao) {}
    
    std::shared_ptr<Usuario> autenticar(const std::string &login, const std::string &senha);
};