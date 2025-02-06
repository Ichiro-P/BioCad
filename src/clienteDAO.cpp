#include <clienteDAO.hpp>
#include <algorithm>

bool ClienteDAO::adicionar(const Cliente &cliente) {
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