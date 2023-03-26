#include <GUIL/Handlers/mouse_handlers.hpp>
#include <GUIL/Handlers/mouse.hpp>

namespace guil
{

////////////////////////////////////////////////////////////
// MouseParser implementation
////////////////////////////////////////////////////////////

MouseParser::MouseParser() : ParserBase(Handlers::Mouse::Count) {
    (*handlers_.push(new ButtonParser()))->attach(&resource_[Handlers::Mouse::MouseButton]);
    (*handlers_.push(new MouseMoveParser()))->attach(&resource_[Handlers::Mouse::MouseMovement]);

    auto handlers = MouseHandlers::getInstance();
    handlers->push(Handlers::Mouse::MouseWheel, &resource_[Handlers::Mouse::MouseWheel]);
    handlers->push(Handlers::Mouse::MouseButton, &resource_[Handlers::Mouse::MouseButton]);
    handlers->push(Handlers::Mouse::MouseMovement, &resource_[Handlers::Mouse::MouseMovement]);
}

void MouseParser::call(const sf::Event& event) {
    if (event.type <= sf::Event::MouseWheelScrolled)
        resource_[Handlers::Mouse::MouseWheel].call(event);
    else if (event.type <= sf::Event::MouseButtonReleased)
        resource_[Handlers::Mouse::MouseButton].call(event);
    else 
        resource_[Handlers::Mouse::MouseMovement].call(event);
}

////////////////////////////////////////////////////////////
// ButtonParser implementation
////////////////////////////////////////////////////////////

ButtonParser::ButtonParser() : ParserBase(sf::Mouse::ButtonCount) {
    auto handlers = ButtonHandlers::getInstance();
    for (int i = 0; i < sf::Mouse::ButtonCount; i++) {
        (*handlers_.push(new ButtonActionParser(i)))->attach(&resource_[i]);
        handlers->push(i, &resource_[i]);
    }
}

void ButtonParser::call(const sf::Event& event) {
    resource_[event.mouseButton.button].call(event);
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
        resource_[0].call(event);
    else
        resource_[1].call(event);
}

////////////////////////////////////////////////////////////
// MouseMoveParser implementation
////////////////////////////////////////////////////////////

MouseMoveParser::MouseMoveParser() : ParserBase(Handlers::Movement::Count) {
    auto handlers = MouseMoveHandlers::getInstance();
    handlers->push(Handlers::Movement::Moved, &resource_[Handlers::Movement::Moved]);
    handlers->push(Handlers::Movement::Entered, &resource_[Handlers::Movement::Entered]);
    handlers->push(Handlers::Movement::Left, &resource_[Handlers::Movement::Left]);
}

void MouseMoveParser::call(const sf::Event& event) {
    if (event.type == sf::Event::MouseMoved)
        resource_[Handlers::Movement::Moved].call(event);
    else if (event.type == sf::Event::MouseEntered)
        resource_[Handlers::Movement::Entered].call(event);
    else
        resource_[Handlers::Movement::Left].call(event);
}


} // namespace guil
