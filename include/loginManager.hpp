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
    LoginManager(std::unique_ptr<UsuarioDAO> dao) : usuarioDAO(std::move(dao)) {}
    
    std::shared_ptr<Usuario> autenticar(const std::string &login, const std::string &senha);
};