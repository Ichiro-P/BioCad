#pragma once

#include <string>
#include <vector>
#include <chrono>
#include <memory>
#include <enums.hpp>
#include <mensalidade.hpp>

class DescontoDVO {
    float valor = 0.f;
    public:
    DescontoDVO() = default;
    DescontoDVO(float valor) : valor(valor) {};
    float getValor() const& { return valor; };
    void setValor(float novoValor) { valor = novoValor; };
};

class DescontoManager {
    public:
    DescontoManager() = default;
    bool validarDesconto(const MensalidadeDVO &mensalidade);
    float calcularDesconto(const MensalidadeDVO &mensalidade);
};