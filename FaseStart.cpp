#include "FaseStart.hpp"

void FaseStart::init()
{
	caminhaomove = new ObjetoDeJogo("caminhao",SpriteAnimado("rsc/caminhao.anm",2),25,120);
	objs.push_back(caminhaomove);

    tapete_entrada = new ObjetoDeJogo("Tapete",SpriteBuffer(17,1),25,2);
	objs.push_back(tapete_entrada);
}

unsigned FaseStart::run(SpriteBuffer &screen)
{
	std::string ent;
	
	//padrão
	draw(screen);
	system("cls");
	show(screen);
	
	while (true)
	{
		//lendo entrada
		getline(std::cin,ent);
		if (ent == "q")
			return Fase::END_GAME;
		
        caminhaomove->moveLeft();

        if (caminhaomove->colideCom(*tapete_entrada))
        {
            return Fase::LEVEL_COMPLETE;
        }
		
		//padrão
		update();
		draw(screen);
		system("cls");
		show(screen);
	}
	
	return Fase::END_GAME; // não necessário
}
