#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>



class Enemy{
	public:
		float hp = 100.f;

		sf::Texture enemy_texture;	
		Enemy(){
			enemy.setPosition(353, -20);
			enemy_texture.loadFromFile("enemy_test.png");
			
		}

		void draw(sf::RenderWindow& window){
			window.draw(enemy);
			enemy.setTexture(enemy_texture);
		}
		void move(){
			x1 = (int)enemy.getPosition().x;
			y1 = (int)enemy.getPosition().y;

			x2 = path[current_pos][0];
			y2 = path[current_pos][1];
			
			if(x1 - x2 < 0){
				enemy.move(sf::Vector2f(0.1,0.f));
			}

			if(x1 - x2 > 0){
				enemy.move(sf::Vector2f(-0.1,0.f));
			}

			if(y1 - y2 < 0){
				enemy.move(sf::Vector2f(0.f,0.1));
			}
			
			if(y1 - y2 > 0){
				enemy.move(sf::Vector2f(0.f,-0.1));
			}

			if(x1 == x2 && y1 == y2){
				if (current_pos != path.size() -1){
	
					current_pos += 1;
				}
			}

		}

		sf::Sprite enemy;
	private:
		std::vector<std::vector<int>> path {{353,2}, {390,51}, {422,129}, {427,228}, {364,314}, {287,410}, {287,455}, {323,490}, {396,550}, {434,630}};
		int current_pos = 0;

		int x1;
		int y1;
		int x2;
		int y2;
	};
#endif /*ENEMY_H*/
