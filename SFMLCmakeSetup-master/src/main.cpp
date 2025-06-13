
#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    sf::Color colors[2] = { sf::Color::Red, sf::Color::Green };
	sf::Color ballColors[2] = { sf::Color::Blue, sf::Color::Yellow };
    int ballX = 640 / 2;
	int bally = 480 / 2;

    sf::RenderWindow window({ 640, 480 }, "Hexagons", sf::Style::Default, sf::ContextSettings(0, 0, 8));

    sf::CircleShape hexagon(25, 6);
    hexagon.setOutlineColor(sf::Color::Black);
    hexagon.setOutlineThickness(5);
    hexagon.setFillColor(sf::Color::White);
    hexagon.setOrigin(25, 25);

	sf::CircleShape circle(20);
	circle.setFillColor(sf::Color::Blue);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (ballX > 0) // 20 es el radio del círculo
                ballX -= 1;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (ballX + 20 < 640)
                ballX += 1;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (bally > 0)
                circle.setFillColor(ballColors[bally % 2]);
                bally -= 1;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if (bally + 20 < 480)
                circle.setFillColor(ballColors[bally % 2]);
                bally += 1;
        }
        



        window.clear(sf::Color::White);



        for (int y = 0; y < 10; ++y) {
            for (int x = 0; x < 10; ++x) {
                // The horizontal/vertical offsets of 50 and 40
                // might feel off, but that's due to the way SFML
                // calculates the circle outline
                hexagon.setPosition((y % 2 ? 75 : 50) + x * 50.f, 50 + y * 40.f);
                hexagon.setFillColor(colors[y % 2]);
                window.draw(hexagon);
            }
        }

        //(y % 2 ? 75 : 50) + x * 50.f
        circle.setPosition(ballX, bally);

		window.draw(circle);

        window.display();
    }
}