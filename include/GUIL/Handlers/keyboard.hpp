#ifndef _GUIL_HANDLERS_KEYBOARD_HPP_
#define _GUIL_HANDLERS_KEYBOARD_HPP_

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <TMBEL/global_container.hpp>

namespace guil {

namespace Handlers {
namespace Keyboard {
enum {
    Text,
    Keys,

    Count
};
}

namespace KeyAction {
enum { None = 0, Pressed = 1 << 7, Released = 1 << 8 };
}
}  // namespace Handlers

////////////////////////////////////////////////////////////
/// \brief Class that contains main keyboard handlers
////////////////////////////////////////////////////////////
class KeyboardHandlers : public ec::GlobalMasBase<sf::Event>,
                         public ec::Singleton<KeyboardHandlers> {
 protected:
    friend ec::Singleton<KeyboardHandlers>;
    KeyboardHandlers() { setCount(Handlers::Keyboard::Count); }
};

////////////////////////////////////////////////////////////
/// \brief Class that contains key handlers
////////////////////////////////////////////////////////////
class KeyHandlers : public ec::GlobalMasBase<sf::Event>,
                    public ec::Singleton<KeyHandlers> {
 protected:
    friend ec::Singleton<KeyHandlers>;
    KeyHandlers() { setCount(1 << 9); }
};

}  // namespace guil

#endif