
#include <GUIL/Handlers/keyboard_handlers.hpp>
#include <GUIL/Handlers/keyboard.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace guil
{

////////////////////////////////////////////////////////////
// KeyboardParser implementation
////////////////////////////////////////////////////////////

KeyboardParser::KeyboardParser() : ParserBase(Handlers::Keyboard::Count) {
    handlers_.push(*resource_[Handlers::Keyboard::Keys].attach(new KeyParser()));
    auto handlers = KeyboardHandlers::getInstance();

    handlers->push(Handlers::Keyboard::Text, &resource_[Handlers::Keyboard::Text]);
    handlers->push(Handlers::Keyboard::Keys, &resource_[Handlers::Keyboard::Keys]);
}

void KeyboardParser::call(const sf::Event& event) {
    if (event.type == sf::Event::TextEntered)
        resource_[0].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
    else resource_[1].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
}

////////////////////////////////////////////////////////////
// KeyParser implementation
////////////////////////////////////////////////////////////

KeyParser::KeyParser() : ParserBase(sf::Keyboard::KeyCount) {
    auto handlers = KeyHandlers::getInstance();
    for (int i = 0; i < sf::Keyboard::KeyCount; i++) {
        handlers_.push(*resource_[i].attach(new KeyActionParser(i)));
        handlers->push(i, &resource_[i]);
    }
}

void KeyParser::call(const sf::Event& event) {
    resource_[event.key.code].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
}

////////////////////////////////////////////////////////////
// KeyActionParser implementation
////////////////////////////////////////////////////////////

KeyActionParser::KeyActionParser(uint32_t key) : ParserBase(2) {
    auto handlers = KeyHandlers::getInstance();
    handlers->push(key | Handlers::KeyAction::Pressed, &resource_[0]);
    handlers->push(key | Handlers::KeyAction::Released, &resource_[1]);
}

void KeyActionParser::call(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed)
        resource_[0].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
    else resource_[1].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
}

} // namespace guil
