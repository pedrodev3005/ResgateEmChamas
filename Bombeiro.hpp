#ifndef BOMBEIRO_HPP
#define BOMBEIRO_HPP

#include "Personagem.hpp"

class Bombeiro : public Personagem
{
public:
    // Construtor inicializando a vida e o estado do bombeiro
    Bombeiro(const ObjetoDeJogo &obj, int vida = 100) : 
        Personagem(obj, vida), extintor(false), moradoresResgatados(0) {}

    virtual ~Bombeiro() {}

    // Método para extinguir o fogo
    int atacar() const {
        if (extintor) {
            return 10;
        }
        return 0; // Sem extintor, não dá dano no fogo
    }

    // Pega o extintor para apagar o fogo
    void pegarExtintor() { extintor = true; }

    // Verifica se o bombeiro possui o extintor
    bool possuiExtintor() const { return extintor; }

    // Método para resgatar um morador
    void resgatarMorador() { moradoresResgatados++; }

    // Verifica quantos moradores foram resgatados
    int getMoradoresResgatados() const { return moradoresResgatados; }

private:
    bool extintor;                // Indica se o bombeiro pegou o extintor
    int moradoresResgatados;      // Contador de moradores resgatados
};

#endif // BOMBEIRO_HPP
