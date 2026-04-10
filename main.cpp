#include <SFML/Graphics.hpp>
#include <cmath>

int main() {
    // 1. Configuración de la ventana (800x600 píxeles)
    sf::RenderWindow window(sf::VideoMode(800, 600), "Circulo Siguiendo al Mouse");
    window.setFramerateLimit(60);

    // 2. Definición del círculo
    // Nota: El tamaño en píxeles depende de la densidad de tu monitor (PPI). 
    // Aproximadamente 38 píxeles suelen representar 1 cm en pantallas estándar.
    float radioCm = 38.0f; 
    sf::CircleShape circle(radioCm);
    circle.setFillColor(sf::Color::Red);
    
    // Ajustar el origen al centro del círculo para que el mouse quede en medio
    circle.setOrigin(radioCm, radioCm);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 3. Lógica de seguimiento
        // Obtenemos la posición del mouse relativa a la ventana
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        
        // Actualizamos la posición del círculo
        circle.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

        // 4. Renderizado
        window.clear(sf::Color::White); // Fondo blanco
        
        // Solo dibujamos si el mouse está dentro de los límites de la ventana
        if (mousePos.x >= 0 && mousePos.x <= 800 && mousePos.y >= 0 && mousePos.y <= 600) {
            window.draw(circle);
        }
        
        window.display();
    }

    return 0;
}