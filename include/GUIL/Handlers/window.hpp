#ifndef _HANDLERS_WINDOW_HPP_
#define _HANDLERS_WINDOW_HPP_

#include <SFML/Window/Event.hpp>
#include <TMBEL/global_container.hpp>
#include <TMBEL/utils.hpp>

namespace guil {

namespace Handlers {
namespace Window {
enum {
    Closed,
    Resized,
    Focus,

    Count
};
}
}  // namespace Handlers

////////////////////////////////////////////////////////////
/// \brief Class that contains handlers of window events
////////////////////////////////////////////////////////////
class WindowHandlers : public ec::GlobalMasBase<sf::Event>,
                       public ec::Singleton<WindowHandlers> {
 protected:
    friend ec::Singleton<WindowHandlers>;
    WindowHandlers() { setCount(Handlers::Window::Count); }
};

namespace Handlers {
namespace Focus {
enum {
    LostFocus,
    GainedFocus,

    Count
};
}
}  // namespace Handlers

////////////////////////////////////////////////////////////
/// \brief Class that contains handlers of focus events
////////////////////////////////////////////////////////////
class FocusHandlers : public ec::GlobalMasBase<sf::Event>,
                       public ec::Singleton<FocusHandlers> {
 protected:
    friend ec::Singleton<FocusHandlers>;
    FocusHandlers() { setCount(Handlers::Focus::Count); }
};

}  // namespace guil

#endif