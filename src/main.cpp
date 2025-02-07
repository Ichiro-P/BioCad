#include <loginManager.hpp>
#include <clienteManager.hpp>
#include <usuarioManager.hpp>
#include <clienteDAO.hpp>
#include <usuarioDAO.hpp>
#include <clienteDVO.hpp>
#include <usuarioDVO.hpp>
#include <telaManager.hpp>

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <limits>

int main() {
    std::vector<std::shared_ptr<Cliente>> clientes {
        std::make_shared<Cliente>(1, "Joao Silva", "123.456.789-00", "Rua A, 123", "(11) 98765-4321", "01/01/2001", "06/02/2025"),
        std::make_shared<Cliente>(2, "Maria Oliveira", "987.654.321-00", "Rua B, 456", "(11) 91234-5678", "02/01/2001", "02/02/2025"),
        std::make_shared<Cliente>(3, "Carlos Santos", "111.222.333-44", "Av. C, 789", "(11) 99876-5432", "10/01/2001", "06/02/2025"),
        std::make_shared<Cliente>(4, "Ana Paula", "555.666.777-88", "Rua D, 101", "(11) 90000-0000", "01/10/2001", "06/12/2025"),
        std::make_shared<Cliente>(5, "Mariana Costa", "999.888.777-66", "Av. E, 202", "(11) 91111-2222", "01/01/2001", "06/02/2025")
    };

    std::unique_ptr<Atendente> eduardo = std::make_unique<Atendente>(1, "eduardo", "maromba", "Eduardo");
    std::unique_ptr<PersonalTrainer> suteam = std::make_unique<PersonalTrainer>(2, "suteam", "mateus", "Matheus Vinicius");
    std::unique_ptr<Gerente> root = std::make_unique<Gerente>(3, "root", "root", "Administrador");

    std::vector<std::shared_ptr<Usuario>> usuarios;
    usuarios.push_back(std::make_shared<Atendente>(1, "eduardo", "maromba", "Eduardo"));
    usuarios.push_back(std::make_shared<PersonalTrainer>(2, "suteam", "mateus", "Matheus Vinicius"));
    usuarios.push_back(std::make_shared<Gerente>(3, "root", "root", "Administrador"));

    std::shared_ptr<UsuarioDAO> usuarioDAO = std::make_shared<UsuarioDAO>(UsuarioDAO(usuarios));
    std::shared_ptr<LoginManager> loginManager = std::make_shared<LoginManager>(usuarioDAO);
    std::shared_ptr<UsuarioManager> usuarioManager = std::make_shared<UsuarioManager>(usuarioDAO);

    std::shared_ptr<ClienteManager> clienteManager = std::make_shared<ClienteManager>(std::make_shared<ClienteDAO>(clientes));
    
    std::string login, senha;
    
    std::cout << "Bem-vindo ao sistema BioCad\n";
    std::cout << "Login: ";
    std::getline(std::cin, login);
    std::cout << "Senha: ";
    std::getline(std::cin, senha);

    std::shared_ptr<Usuario> usuario = loginManager->autenticar(login, senha);
    while(usuario == nullptr) {
        std::cout << "Credenciais incorretas.\nTente novamente:\n";
        std::cout << "Login: ";
        std::getline(std::cin, login);
        std::cout << "Senha: ";
        std::getline(std::cin, senha);
        usuario = loginManager->autenticar(login, senha);
    }

    telaInicial(usuario, loginManager, clienteManager, usuarioManager);
    
    return 0;
}