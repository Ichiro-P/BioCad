#include <loginManager.hpp>
#include <clienteManager.hpp>
#include <usuarioManager.hpp>
#include <clienteDAO.hpp>
#include <usuarioDAO.hpp>
#include <clienteDVO.hpp>
#include <usuarioDVO.hpp>
#include <metodosTela.hpp>

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <limits>

int main() {

    auto usuarioDao = std::make_unique<UsuarioDAO>();
    LoginManager loginManager(usuarioDao.release());
    
    std::string login, senha;
    
    std::cout << "Bem-vindo ao sistema BioCad\n";
    std::cout << "Login: ";
    std::getline(std::cin, login);
    std::cout << "Senha: ";
    std::getline(std::cin, senha);

    std::shared_ptr<Usuario> usuario = loginManager.autenticar(login, senha);
    while(usuario == nullptr) {
        std::cout << "Credenciais incorretas.\nTente novamente:\n";
        std::cout << "Login: ";
        std::getline(std::cin, login);
        std::cout << "Senha: ";
        std::getline(std::cin, senha);
        usuario = loginManager.autenticar(login, senha);
    }
    
    telaInicial(usuario);
    return 0;
}