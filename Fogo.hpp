#ifndef FOGO_HPP
#define FOGO_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Fogo : public ObjetoDeJogo
{
public:
    // Construtor inicializando a intensidade do fogo e a contagem de movimentos para causar dano
    Fogo(const ObjetoDeJogo &obj, int intensidade = 30, int intervaloDano = 3) :
        ObjetoDeJogo(obj), intensidade(intensidade), intervaloDano(intervaloDano), contDano(intervaloDano) {}

    virtual ~Fogo() {}

    // Verifica se o fogo ainda está "ativo"
    bool estaQueimando() const { return intensidade != 0; }

    // Método para reduzir a intensidade do fogo (por exemplo, quando é apagado)
    void reduzirIntensidade(int reducao) {
        intensidade = (intensidade - reducao >= 0) ? (intensidade - reducao) : 0;
    }

    // Método para causar dano a cada 3 movimentos
    int causarDano() {
        if (--contDano == 0) {
            contDano = intervaloDano;
            return 10; // Causa 10 de dano
        }
        return 0; // Não causa dano nesse movimento
    }

    // Método para retornar a intensidade atual do fogo
    int getIntensidade() const {
        return intensidade;
    }

private:
    int intensidade;          // Intensidade (vida) do fogo
    int intervaloDano;        // Intervalo de movimentos para causar dano
    int contDano;             // Contador para controlar quando o fogo causa dano
};

#endif // FOGO_HPP
