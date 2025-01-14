#ifndef FASELEVEL1_HPP
#define FASELEVEL1_HPP

//#include "ASCII_Engine"

#include "ASCII_Engine/Fase.hpp"
#include <string>
#include <list>

#include "Fogo.hpp"
#include "Morador.hpp"
#include "Bombeiro.hpp"


class FaseLevel1 : public Fase
{
public:
	FaseLevel1(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseLevel1(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseLevel1() {}
	
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);
	
private:

	
	Fogo *fogos[3];
	Bombeiro *bombeiro;
	Morador *moradores[10];
    
	ObjetoDeJogo *extintor;
	ObjetoDeJogo *sim;
	TextSprite *life;

	
};

#endif // FASELEVEL1_HPP
