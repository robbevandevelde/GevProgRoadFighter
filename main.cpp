//
// Created by thibaut on 17.11.18.
//
#include <SFML/Graphics.hpp>

int main(int argc,char* argv[]){
    sf::RenderWindow window(sf::VideoMode(1000,1000), "ROAD FIGHTERS",sf::Style::Default);
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
    }
}