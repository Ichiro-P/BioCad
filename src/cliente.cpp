#include <string>
#include <cliente.hpp>
#include <dados.hpp>

cliente::cliente(const std::string &nome, const std::string &cpf, const std::string &telefone, const std::string &endereco, const std::string &dataNascimento, const std::string &dataCadastro, const int& duracao, const contrato &contratoVigente) 
: nome(nome), cpf(cpf), telefone(telefone), endereco(endereco), dataNascimento(dataNascimento), dataCadastro(dataCadastro), contratoVigente(contratoVigente) {
    id = clientes.size() + 1;
}

int cliente::getId() const& {
    return id;
}

std::string cliente::getNome() const& {
    return nome;
}

contrato::contrato(const std::string &nomeCliente, const std::string &dataInicio, const std::string &dataVencimento, const int& duracao, const plano &planoVigente) 
: nomeCliente(nomeCliente), dataInicio(dataInicio), dataVencimento(dataVencimento), duracao(duracao), planoVigente(planoVigente) {}

plano::plano(const treinoPlano& treino, const int& duracao, const tipoPlano& tipo) : tipo(tipo), treino(treino) {
    for(int i = 0; i < duracao; ++i) {
        mensalidades.emplace_back(60.f, i+1);
    }

}

treinoPlano::treinoPlano(const std::vector<std::string>& objetivosCliente, const std::string& condicaomedica) : objetivosCliente(objetivosCliente), condicaoMedica(condicaoMedica) {
}

mensalidade::mensalidade(const float &valor, const int& dataRelativaVencimento) : valor(valor), dataRelativaVencimento(dataRelativaVencimento) {
}

void mensalidade::pagar() {
    status = statusPagamento::pago;
}
