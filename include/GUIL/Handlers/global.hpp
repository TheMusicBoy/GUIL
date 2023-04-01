#ifndef _GUIL_HANDLERS_GLOBAL_HPP_
#define _GUIL_HANDLERS_GLOBAL_HPP_

#include <SFML/Window/Event.hpp>
#include <TMBEL/global_container.hpp>
#include <TMBEL/utils.hpp>

namespace guil {

namespace Handlers {
namespace Global {
enum {
    Main,
    Window,
    Keyboard,
    Mouse,
    Other,

    Count
};
}
}  // namespace Handlers

class GlobalHandlers : public ec::GlobalMasBase<sf::Event>,
                       public ec::Singleton<GlobalHandlers> {
 protected:
    friend ec::Singleton<GlobalHandlers>;

    GlobalHandlers() { setCount(Handlers::Global::Count); }
};

namespace Main {
enum {
    Window,
    Keyboard,
    Mouse,
    Other,

    Count
};

}

}  // namespace guil

#endif