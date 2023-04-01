#include <GUIL/Handlers/mouse.hpp>
#include <GUIL/Handlers/mouse_handlers.hpp>

namespace guil {

////////////////////////////////////////////////////////////
// MouseParser implementation
////////////////////////////////////////////////////////////

MouseParser::MouseParser() : ParserBase(Handlers::Mouse::Count) {
    handlers_.push(
        *resource_[Handlers::Mouse::MouseButton].attach(new ButtonParser()));
    handlers_.push(*resource_[Handlers::Mouse::MouseMovement].attach(
        new MouseMoveParser()));

    MouseHandlers* handlers = MouseHandlers::getInstance();
    ec::GlobalMasBase<sf::Event>* pointer = handlers;

    handlers->push(uint32_t(Handlers::Mouse::MouseWheel),
                   &resource_[Handlers::Mouse::MouseWheel]);
    handlers->push(Handlers::Mouse::MouseButton,
                   &resource_[Handlers::Mouse::MouseButton]);   
    handlers->push(Handlers::Mouse::MouseMovement,
                   &resource_[Handlers::Mouse::MouseMovement]);
}

void MouseParser::call(const sf::Event& event) {
    if (event.type <= sf::Event::MouseWheelScrolled)
        resource_[Handlers::Mouse::MouseWheel].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
    else if (event.type <= sf::Event::MouseButtonReleased)
        resource_[Handlers::Mouse::MouseButton].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
    else
        resource_[Handlers::Mouse::MouseMovement].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
}

////////////////////////////////////////////////////////////
// ButtonParser implementation
////////////////////////////////////////////////////////////

ButtonParser::ButtonParser() : ParserBase(sf::Mouse::ButtonCount) {
    auto handlers = ButtonHandlers::getInstance();
    for (int i = 0; i < sf::Mouse::ButtonCount; i++) {
        handlers_.push(*resource_[i].attach(new ButtonActionParser(i)));
        handlers->push(i, &resource_[i]);
    }
}

void ButtonParser::call(const sf::Event& event) {
    resource_[event.mouseButton.button].map(
        [&event](ec::Handler<sf::Event>* el) { el->call(event); });
}

////////////////////////////////////////////////////////////
// ButtonActionParser implementation
////////////////////////////////////////////////////////////

ButtonActionParser::ButtonActionParser(uint32_t button) : ParserBase(2) {
    auto handlers = ButtonHandlers::getInstance();
    handlers->push(button | Handlers::ButtonAction::Pressed, &resource_[0]);
    handlers->push(button | Handlers::ButtonAction::Released, &resource_[1]);
}

void ButtonActionParser::call(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed)
        resource_[0].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
    else
        resource_[1].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
}

////////////////////////////////////////////////////////////
// MouseMoveParser implementation
////////////////////////////////////////////////////////////

MouseMoveParser::MouseMoveParser() : ParserBase(Handlers::Movement::Count) {
    auto handlers = MouseMoveHandlers::getInstance();
    handlers->push(Handlers::Movement::Moved,
                   &resource_[Handlers::Movement::Moved]);
    handlers->push(Handlers::Movement::Entered,
                   &resource_[Handlers::Movement::Entered]);
    handlers->push(Handlers::Movement::Left,
                   &resource_[Handlers::Movement::Left]);
}

void MouseMoveParser::call(const sf::Event& event) {
    if (event.type == sf::Event::MouseMoved)
        resource_[Handlers::Movement::Moved].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
    else if (event.type == sf::Event::MouseEntered)
        resource_[Handlers::Movement::Entered].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
    else
        resource_[Handlers::Movement::Left].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
}

}  // namespace guil
