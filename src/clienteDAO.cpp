#include <clienteDAO.hpp>
#include <algorithm>
#include <memory>

ClienteDAO::ClienteDAO(const std::vector<std::shared_ptr<Cliente>>& vetorClientes) {
    for(const auto& it: vetorClientes) {
        clientes.push_back(it);
    }
}

bool ClienteDAO::adicionar(std::shared_ptr<Cliente> cliente) {
    clientes.push_back(cliente);
    return true;
}

bool ClienteDAO::atualizar(std::shared_ptr<Cliente> cliente) {
    for (auto &c : clientes) {
        if (c->getId() == cliente->getId()) {
            c = cliente;
            return true;
        }
    }
    return false;
}

bool ClienteDAO::fazerCheckin(std::shared_ptr<Cliente> cliente) {
    cliente->setCheckIns(cliente->getCheckIns() + 1);
    return true;
}

bool ClienteDAO::fazerCheckOut(std::shared_ptr<Cliente> cliente) {
    cliente->setCheckOuts(cliente->getCheckOuts() + 1);
    return true;
}

bool ClienteDAO::remover(int id) {
    auto it = std::find_if(clientes.begin(), clientes.end(), [id](const std::shared_ptr<Cliente> c) {
        return c->getId() == id;
    });
    if (it != clientes.end()) {
        clientes.erase(it);
        return true;
    }
    return false;
}
std::shared_ptr<Cliente> ClienteDAO::buscar(int id) {
    for (const auto &c : clientes) {
        if (c->getId() == id)
            return c;
    }
    return nullptr;
}

std::vector<std::shared_ptr<Cliente>> ClienteDAO::login() {
    return clientes;
}