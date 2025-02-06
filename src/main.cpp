#include <loginManager.hpp>
#include <clienteManager.hpp>
#include <clienteDAO.hpp>
#include <usuarioDAO.hpp>
#include <clienteDVO.hpp>
#include <usuarioDVO.hpp>

#include <iostream>
#include <memory>
#include <vector>
#include <string>

int main() {

    auto usuarioDao = std::make_unique<UsuarioDAO>();
    LoginManager loginManager(usuarioDao.release());
    
    std::string login, senha;
    
    std::cout << "Bem-vindo ao sistema BioCad\n";
    std::cout << "Login: ";
    std::getline(std::cin, login);
    std::cout << "Senha: ";
    std::getline(std::cin, senha);
    
    try {

        std::shared_ptr<Usuario> usuario = loginManager.autenticar(login, senha);
        std::cout << "Bem-vindo, " << usuario->getNome() << "!" << std::endl;
        

        std::vector<std::string> opcoes = usuario->getInterfaceOptions();
        std::cout << "Opções disponíveis:" << std::endl;
        for (const auto &opcao : opcoes)
            std::cout << opcao << std::endl;
        

        if (usuario->getTipo() == TipoUsuario::ATENDENTE ||
            usuario->getTipo() == TipoUsuario::GERENTE) {
            auto clienteDao = std::make_unique<ClienteDAO>();
            ClienteManager clienteManager(clienteDao.get());

            Cliente novoCliente(100, "Maria Souza", "maria@exemplo.com");
            

            clienteManager.cadastrarCliente(novoCliente);
            std::cout << "Cliente cadastrado: " << novoCliente.getNome() << std::endl;
            

            std::vector<Cliente> clientes = clienteManager.listarClientes();
            std::cout << "Clientes cadastrados:" << std::endl;
            for (const auto &c : clientes)
                std::cout << "ID: " << c.getId() << " - " << c.getNome() << std::endl;
        }
        
    } catch (const std::exception &ex) {
        std::cerr << "Erro: " << ex.what() << std::endl;
        return 1;
    }
    
    return 0;
}