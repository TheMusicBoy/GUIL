#include <GUIL/Handlers/window.hpp>
#include <GUIL/Handlers/window_handlers.hpp>

namespace guil {

////////////////////////////////////////////////////////////
// WindowParser implementation
////////////////////////////////////////////////////////////

WindowParser::WindowParser() : ParserBase(Handlers::Window::Count) {
    handlers_.push(*resource_[Handlers::Window::Focus].attach(new FocusParser()));

    auto handlers = WindowHandlers::getInstance();
    handlers->push(Handlers::Window::Closed, &resource_[Handlers::Window::Closed]);
    handlers->push(Handlers::Window::Resized, &resource_[Handlers::Window::Resized]);
    handlers->push(Handlers::Window::Focus, &resource_[Handlers::Window::Focus]);
}

void WindowParser::call(const sf::Event& event) {
    if (event.type == sf::Event::Closed)
        resource_[Handlers::Window::Closed].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
    else if (event.type == sf::Event::Resized)
        resource_[Handlers::Window::Resized].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
    else
        resource_[Handlers::Window::Focus].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
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
        resource_[Handlers::Focus::LostFocus].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
    else
        resource_[Handlers::Focus::GainedFocus].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
}

}  // namespace guil

