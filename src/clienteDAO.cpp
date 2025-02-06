#include <clienteDAO.hpp>
#include <algorithm>

ClienteDAO::ClienteDAO() {
        clientes.push_back(Cliente(1, "Joao Silva", "123.456.789-00", "Rua A, 123", "(11) 98765-4321", "01/01/2001", "06/02/2025"));
        clientes.push_back(Cliente(2, "Maria Oliveira", "987.654.321-00", "Rua B, 456", "(11) 91234-5678", "02/01/2001", "02/02/2025"));
        clientes.push_back(Cliente(3, "Carlos Santos", "111.222.333-44", "Av. C, 789", "(11) 99876-5432", "10/01/2001", "06/02/2025"));
        clientes.push_back(Cliente(4, "Ana Paula", "555.666.777-88", "Rua D, 101", "(11) 90000-0000", "01/10/2001", "06/12/2025"));
        clientes.push_back(Cliente(5, "Mariana Costa", "999.888.777-66", "Av. E, 202", "(11) 91111-2222", "01/01/2001", "06/02/2025"));
}

bool ClienteDAO::adicionar(const Cliente &cliente)
{
    clientes.push_back(cliente);
    return true;
}

bool ClienteDAO::atualizar(const Cliente &cliente) {
    for (auto &c : clientes) {
        if (c.getId() == cliente.getId()) {
            c = cliente;
            return true;
        }
    }
    return false;
}

bool ClienteDAO::remover(int id) {
    auto it = std::remove_if(clientes.begin(), clientes.end(), [id](const Cliente &c) { return c.getId() == id; });
    if (it != clientes.end()) {
        clientes.erase(it, clientes.end());
        return true;
    }
    return false;
}

Cliente ClienteDAO::buscar(int id) {
    for (const auto &c : clientes) {
        if (c.getId() == id)
            return c;
    }
    return Cliente();
}

std::vector<Cliente> ClienteDAO::listar() {
    return clientes;
}