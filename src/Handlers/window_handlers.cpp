#include <GUIL/Handlers/window.hpp>
#include <GUIL/Handlers/window_handlers.hpp>

namespace guil {

////////////////////////////////////////////////////////////
// WindowParser implementation
////////////////////////////////////////////////////////////

WindowParser::WindowParser() : ParserBase(Handlers::Window::Count) {
    (*handlers_.push(new FocusParser()))->attach(&resource_[Handlers::Window::Focus]);

    auto handlers = WindowHandlers::getInstance();
    handlers->push(Handlers::Window::Closed, &resource_[Handlers::Window::Closed]);
    handlers->push(Handlers::Window::Resized, &resource_[Handlers::Window::Resized]);
    handlers->push(Handlers::Window::Focus, &resource_[Handlers::Window::Focus]);
}

void WindowParser::call(const sf::Event& event) {
    if (event.type == sf::Event::Closed)
        resource_[Handlers::Window::Closed].call(event);
    else if (event.type == sf::Event::Resized)
        resource_[Handlers::Window::Resized].call(event);
    else
        resource_[Handlers::Window::Focus].call(event);
}

////////////////////////////////////////////////////////////
// FocusParser implementation
////////////////////////////////////////////////////////////

FocusParser::FocusParser() : ParserBase(Handlers::Focus::Count) {
    auto handlers = FocusHandlers::getInstance();
    handlers->push(Handlers::Focus::GainedFocus, &resource_[Handlers::Focus::GainedFocus]);
    handlers->push(Handlers::Focus::LostFocus, &resource_[Handlers::Focus::LostFocus]);
}

void FocusParser::call(const sf::Event& event) {
    if (event.type == sf::Event::LostFocus)
        resource_[Handlers::Focus::LostFocus].call(event);
    else
        resource_[Handlers::Focus::GainedFocus].call(event);
}

}  // namespace guil

