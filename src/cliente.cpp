#include <cliente.hpp>
#include <string>
#include <chrono>

ClienteDVO::ClienteDVO(const std::string &cpf, const std::string &nomeCompleto, const std::string &telefone, const std::string &endereco, int diaNascimento, int mesNascimento, int anoNascimento)
 : cpf(cpf), nomeCompleto(nomeCompleto), telefone(telefone), endereco(endereco) {
    std::tm tmp = {};
    this->cpf.resize(14);
    this->telefone.resize(11);
    this->nomeCompleto.resize(150);
    this->endereco.resize(150);
    tmp.tm_year = anoNascimento - 1900;
    tmp.tm_mon = mesNascimento - 1;
    tmp.tm_mday = diaNascimento;

    dataNascimento = std::chrono::system_clock::from_time_t(std::mktime(&tmp));
}

void ClienteDVO::setCpf(const std::string novoCpf) {
    cpf = novoCpf;
    cpf.resize(14);
}

void ClienteDVO::setNomeCompleto(const std::string novoNome) {
    nomeCompleto = novoNome;
    nomeCompleto.resize(150);
}

void ClienteDVO::setTelefone(const std::string novotelefone) {
    telefone = novotelefone;
    telefone.resize(11);
}

void ClienteDVO::setEndereco(const std::string novoEndereco) {
    endereco = novoEndereco;
    endereco.resize(150);
}

void ClienteDVO::setDataNascimento(int dia, int mes, int ano) {
    std::tm tmp = {};
    tmp.tm_year = ano - 1900;
    tmp.tm_mon = mes - 1;
    tmp.tm_mday = dia;
    dataNascimento = std::chrono::system_clock::from_time_t(std::mktime(&tmp));
}

ClienteDAO::ClienteDAO(std::vector<ClienteDVO> &clientes) {
    for(auto &it: clientes) {
        this->clientes.push_back(std::make_unique<ClienteDVO>(std::move(it)));
    }
}

void ClienteDAO::create(const ClienteDVO &cliente) {
    clientes.push_back(std::make_unique<ClienteDVO>(std::move(cliente)));
}

void ClienteDAO::update(const ClienteDVO &cliente) {
    for(auto &&it: clientes) {
        if(it->getCpf() == cliente.getCpf()) {
            it = std::make_unique<ClienteDVO>(std::move(cliente));
            break;
        }
    }
}

void ClienteDAO::remover(const ClienteDVO &cliente) {
    clientes.erase(std::remove_if(clientes.begin(), clientes.end(),
    [&cliente](const std::unique_ptr<ClienteDVO>& it) { return it->getCpf() == cliente.getCpf(); }), clientes.end());
}

ClienteDVO ClienteDAO::getClienteDVO(const std::string& cpfCliente) const& {
    for(auto &&it: clientes) {
        if(it->getCpf() == cpfCliente) {
            return *it;
            break;
        }
    }
    return ClienteDVO();
}

ClienteManager::ClienteManager(ClienteDAO &&clienteDAO) {
    this->clienteDAO = std::make_unique<ClienteDAO>(std::move(clienteDAO));
}

ClienteDVO ClienteManager::getClienteDVO(const std::string &cpfCliente) const& {
    return clienteDAO->getClienteDVO(cpfCliente);
}

bool ClienteManager::validarCpf(const std::string &cpf) {
    bool existe = true;
    if(cpf.size() != 14) existe = false;
    if(clienteDAO->getClienteDVO(cpf).getCpf().empty()) existe = false;
    return existe;
}

void ClienteManager::adicionarCliente(ClienteDVO &cliente) {
    if(!cliente.getCpf().empty()) clienteDAO->create(cliente);
}

void ClienteManager::atualizarCliente(ClienteDVO &cliente) {
    if(!cliente.getCpf().empty()) clienteDAO->update(cliente);
}

void ClienteManager::removerCliente(ClienteDVO &cliente) {
    if(!cliente.getCpf().empty()) clienteDAO->remover(cliente);
}