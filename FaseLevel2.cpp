#include "FaseLevel2.hpp"


#include <iostream>

void FaseLevel2::init()
{	
	//Objetos de jogo

	fogos[0] = new Fogo(ObjetoDeJogo("Fogo1",Sprite("rsc/fogo.img"),10,2));
	objs.push_back(fogos[0]);

	fogos[1] = new Fogo(ObjetoDeJogo("Fogo2",Sprite("rsc/fogo.img"),40,180));
	objs.push_back(fogos[1]);
	
	fogos[2] = new Fogo(ObjetoDeJogo("Fogo3",Sprite("rsc/fogo.img"),19,117));
	objs.push_back(fogos[2]);
	
    grade = new ObjetoDeJogo("grade_janela",Sprite("rsc/grade.img"),16,1);
	objs.push_back(grade);

	moradores[0] = new Morador(ObjetoDeJogo("Morador1",Sprite("rsc/morador.img"),16,10));
	objs.push_back(moradores[0]);

	moradores[1] = new Morador(ObjetoDeJogo("Morador2",Sprite("rsc/morador.img"),16,68));
	objs.push_back(moradores[1]);

	moradores[2] = new Morador(ObjetoDeJogo("Morador3",Sprite("rsc/morador.img"),16,125));
	objs.push_back(moradores[2]);
	
	moradores[3] = new Morador(ObjetoDeJogo("Morador4",Sprite("rsc/morador.img"),16,185));
	objs.push_back(moradores[3]);

	moradores[4] = new Morador(ObjetoDeJogo("Morador5",Sprite("rsc/morador.img"),16,243));
	objs.push_back(moradores[4]);



	moradores[5] = new Morador(ObjetoDeJogo("Morador6",Sprite("rsc/morador.img"),37,10));
	objs.push_back(moradores[5]);

	moradores[6] = new Morador(ObjetoDeJogo("Morador7",Sprite("rsc/morador.img"),37,68));
	objs.push_back(moradores[6]);

	moradores[7] = new Morador(ObjetoDeJogo("Morador8",Sprite("rsc/morador.img"),37,125));
	objs.push_back(moradores[7]);
	
	moradores[8] = new Morador(ObjetoDeJogo("Morador9",Sprite("rsc/morador.img"),37,185));
	objs.push_back(moradores[8]);

	moradores[9] = new Morador(ObjetoDeJogo("Morador10",Sprite("rsc/morador.img"),37,243));
	objs.push_back(moradores[9]);

	bombeiro = new Bombeiro(ObjetoDeJogo("Bombeiro",Sprite("rsc/bombeiro.img"),46,108));
	objs.push_back(bombeiro);


	extintor = new ObjetoDeJogo("extintor",Sprite("rsc/extintor.img"),28,15);
	objs.push_back(extintor);
													 

	sim = new ObjetoDeJogo("sim",TextSprite("SIM"),9,152);
	objs.push_back(sim);
	sim->desativarObj();


													   //std::string(20,'#')
	objs.push_back(new ObjetoDeJogo("Life",TextSprite("####################"),9,71));
	SpriteBase *tmp = const_cast<SpriteBase*> (objs.back()->getSprite());
	life = dynamic_cast<TextSprite*> (tmp);
	
}

unsigned FaseLevel2::run(SpriteBuffer &screen)
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
		
		//processando entradas
		int posL = bombeiro->getPosL(), posC = bombeiro->getPosC();
		
		if (ent == "w" && bombeiro->getPosL() > 15)
			bombeiro->moveUp(5);
		else if (ent == "s" && bombeiro->getPosL() < 47)
			bombeiro->moveDown(5);
		else if (ent == "a" && bombeiro->getPosC() > 4)
			bombeiro->moveLeft(5);
		else if (ent == "d" && bombeiro->getPosC() < screen.getLargura() - bombeiro->getSprite()->getLargura() - 13)
			bombeiro->moveRight(5);
		else if (ent == "x") {
			for (int g = 0 ; g < 3 ; g++)
				if (bombeiro->colideCom(*fogos[g])) {
					fogos[g]->reduzirIntensidade(bombeiro->atacar());
					if (!fogos[g]->estaQueimando()){
						for (int i = 0; i < 10; i++)
						{
							if (moradores[i]->colideCom(*fogos[g]))
							{
								moradores[i]->desativarObj();
								bombeiro->resgatarMorador();

							}
							
						}
						fogos[g]->desativarObj();
					}
                }
		}
		
		

		else if (ent == "q")
			return Fase::END_GAME;		
		

		//processando eventos
		for (int g = 0 ; g < 3 ; g++)
				if (bombeiro->colideCom(*fogos[g])) {
					bombeiro->sofrerDano(fogos[g]->causarDano());
					
					if (!bombeiro->estaVivo())
						return Fase::GAME_OVER;
					
					life->setText(std::string(bombeiro->getVida()/5,'#'));
				}
		
		for (int i = 0; i < 10; i++)
		{
			for (int g = 0 ; g < 3 ; g++)
			{
				if (moradores[i]->colideCom(*fogos[g]))
				{
					moradores[i]->sofrerDano(fogos[g]->causarDano());
					if (!moradores[i]->estaVivo())
					{
						moradores[i]->desativarObj();
					}
					
				}
			}

			
			if (bombeiro->colideCom(*moradores[i]) && ( i == 2 || i == 8))
			{
				bombeiro->resgatarMorador();
				moradores[i]->desativarObj();
			}
		
		}
		if (bombeiro->colideCom(*extintor))
		{
			extintor->desativarObj();
			bombeiro->pegarExtintor();
			sim->ativarObj();
		}

		if (bombeiro->getMoradoresResgatados()==3)
		{

			return Fase::LEVEL_COMPLETE;
		}
		
		if (!moradores[0]->estaVivo() || !moradores[2]->estaVivo() || !moradores[8]->estaVivo())
		{
			return Fase::GAME_OVER;
		}
		

		//padrão
		update();
		draw(screen);
		system("cls");
		show(screen);
	}
	
	return Fase::END_GAME; // não necessário
}

