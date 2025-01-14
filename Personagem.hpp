#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Personagem : public ObjetoDeJogo
{
public:
    // Construtor inicializando a vida do personagem
    Personagem(const ObjetoDeJogo &obj, int vida) : 
        ObjetoDeJogo(obj), vida(vida) {}

    virtual ~Personagem() {}

    // Verifica se o personagem ainda está vivo
    bool estaVivo() const { return vida > 0; }

    // Retorna a vida atual do personagem
    int getVida() const { return vida; }

    // Método para sofrer dano
    void sofrerDano(int dano) { vida = (vida - dano >= 0) ? (vida - dano) : 0; }

protected:
    int vida;  // Vida do personagem
};

#endif // PERSONAGEM_HPP
