#include <GUIL/Handlers/global.hpp>
#include <GUIL/Handlers/global_handlers.hpp>
#include <GUIL/Handlers/window_handlers.hpp>
#include <GUIL/Handlers/keyboard_handlers.hpp>
#include <GUIL/Handlers/mouse_handlers.hpp>

namespace guil {

////////////////////////////////////////////////////////////
// MainEventParser implementation
////////////////////////////////////////////////////////////

MainParser::MainParser() : ParserBase(Handlers::Global::Count) {

    handlers_.push(*resource_[Handlers::Global::Window].attach(new WindowParser()));
    handlers_.push(*resource_[Handlers::Global::Keyboard].attach(new KeyboardParser()));
    handlers_.push(*resource_[Handlers::Global::Mouse].attach(new MouseParser()));


    auto global_handlers = GlobalHandlers::getInstance();
    global_handlers->push(Handlers::Global::Window, &resource_[Handlers::Global::Window]);
    global_handlers->push(Handlers::Global::Keyboard,
                          &resource_[Handlers::Global::Keyboard]);
    global_handlers->push(Handlers::Global::Mouse, &resource_[Handlers::Global::Mouse]);
    global_handlers->push(Handlers::Global::Other, &resource_[Handlers::Global::Other]);
}

void MainParser::call(const sf::Event& event) {
    if (event.type <= sf::Event::GainedFocus)
        resource_[Handlers::Global::Window].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
    else if (event.type <= sf::Event::KeyReleased)
        resource_[Handlers::Global::Keyboard].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
    else if (event.type <= sf::Event::MouseLeft)
        resource_[Handlers::Global::Mouse].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
    else
        resource_[Handlers::Global::Other].map(
            [&event](ec::Handler<sf::Event>* el) { el->call(event); });
}

}  // namespace guil
