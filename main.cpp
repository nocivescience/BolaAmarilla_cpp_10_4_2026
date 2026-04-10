#include <SFML/Graphics.hpp>
#include <string>
#include <optional>
#include <string>
#include <iostream>

int main() {
    // 1. Crear la ventana con SFML 3
    // Ahora se usa sf::VideoMode({ancho, alto}) con llaves
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML 3 - Circulo Seguimiento");
    
    sf::Font font;
    if (!font.openFromFile("arial.ttf")) {
        std::cerr << "Error: No se pudo cargar arial.ttf" << std::endl;
    }

    sf::Text texto(font, "Sigue el circulo con el mouse", 24);
    texto.setFillColor(sf::Color::Black);
    texto.setPosition({20.f, 20.f});

    window.setFramerateLimit(60);

    // 2. Configurar el círculo
    // 1 cm ≈ 38 píxeles (basado en 96 DPI estándar)
    float radioCm = 38.0f;
    sf::CircleShape circle(radioCm);
    circle.setFillColor(sf::Color::Red);
    
    // En SFML 3, establecer el origen al centro
    circle.setOrigin({radioCm, radioCm});

    
    while (window.isOpen()) {
        // 3. Manejo de eventos (Nueva sintaxis SFML 3)
        // handleEvents procesa los eventos internamente
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        
        // 4. Lógica de seguimiento
        // Obtener posición del mouse relativa a la ventana
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        
        // Convertir a float para posicionar el círculo
        circle.setPosition({static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)});
        
        // 5. Renderizado
        window.clear(sf::Color::White);
        window.draw(texto);

        // Verificamos si el mouse está sobre la ventana para dibujar
        // window.getSize() devuelve un Vector2u (unsigned)
        auto size = window.getSize();
        if (mousePos.x >= 0 && mousePos.y >= 0 && 
            mousePos.x <= static_cast<int>(size.x) && 
            mousePos.y <= static_cast<int>(size.y)) {
            window.draw(circle);
        }

        window.display();
    }

    return 0;
}