#pragma once

#include <vector>
#include <string>
#include <gerente.hpp>
#include <atendente.hpp>
#include <cliente.hpp>

std::vector<cliente> clientes;
std::vector<atendente> atendentes;

void visualizarRelatorioFinanceiro();

void listarClientes();
void cadastrarCliente();
void atualizarCliente();
void removerCliente();

void listarAtendentes();
void cadastrarAtendente();
void atualizarAtendente();
void removerAtendente();

void listarPersonalTrainers();
void cadastrarPersonalTrainer();
void atualizarPersonalTrainer();
void removerPersonalTrainer();