#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "enemy.h"
#include "cannon.h"



sf::RenderWindow window(sf::VideoMode(800, 600), "asd");

std::vector<Enemy> enemies(1);

std::vector<Cannon> cannon;

std::vector<sf::Vector2i> c_pos;

std::vector<std::vector<int>> path {{353,2}, {390,51}, {422,129}, {427,228}, {364,314}, {287,410}, {287,455}, {323,490}, {396,550}, {434,596}};


int main(){

	//map
	sf::Sprite background;
	
	sf::Texture backgroundtext;
	if(!backgroundtext.loadFromFile("map_test.png")){
		std::cerr << "Texture map_test not found" << std::endl;
	}
	
	background.setTexture(backgroundtext);

	//Clock	
	sf::Clock spawn_clock;
	sf::Clock fire_clock;

	while(window.isOpen()){
		
		sf::Event event;
		while(window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
			}
			if(event.type == sf::Event::MouseButtonPressed){
				sf::Vector2i m_pos = sf::Mouse::getPosition(window);


				cannon.push_back(Cannon());
				c_pos.push_back(m_pos);
			}
		}

		sf::Time spawn_elapsed = spawn_clock.getElapsedTime();
		sf::Time fire_elapsed = fire_clock.getElapsedTime();
		

		if(spawn_elapsed.asSeconds() >= 5){
			enemies.push_back(Enemy());
			spawn_clock.restart();
		}

		window.clear(sf::Color::Black);
		window.draw(background);

		for (auto& e : enemies){
			e.draw(window);
			e.move();
		}
		for (auto& c : cannon){
			for(auto& cp : c_pos){
	
				c.draw(window);
				c.setPosition(cp);
				for (int i = 0; i < enemies.size(); i++){
					if(fire_elapsed.asSeconds() >= 1){
		
						c.shoot(enemies[i], c.range);
						fire_clock.restart();
					}
	
				}
			}
		}
		window.display();
	
	//End of main loop
	}
}
