#ifndef _GUIL_HANDLERS_MOUSE_HPP_
#define _GUIL_HANDLERS_MOUSE_HPP_

#include <TMBEL/global_container.hpp>
#include <TMBEL/utils.hpp>

namespace guil {

namespace Handlers {
namespace Mouse {
enum {
    MouseWheel,
    MouseButton,
    MouseMovement,

    Count
};
}

namespace ButtonAction {
enum { None, Pressed = 1 << 6, Released = 1 << 7 };
}

namespace Movement {
enum {
    Moved,
    Entered,
    Left,

    Count
};
}
}  // namespace Handlers

////////////////////////////////////////////////////////////
/// \brief Class that contains main mouse handler lists
////////////////////////////////////////////////////////////
class MouseHandlers : public ec::GlobalMasBase,
                      public ec::Singleton<MouseHandlers> {
 private:
    friend ec::Singleton<MouseHandlers>;
    MouseHandlers() { setCount(Handlers::Mouse::Count); }
};

////////////////////////////////////////////////////////////
/// \brief Class that contains button handler lists
////////////////////////////////////////////////////////////
class ButtonHandlers : public ec::GlobalMasBase,
                       public ec::Singleton<ButtonHandlers> {
 private:
    friend ec::Singleton<ButtonHandlers>;
    ButtonHandlers() { setCount(1 << 8); }
};

////////////////////////////////////////////////////////////
/// \brief Class that contains movement handler lists
////////////////////////////////////////////////////////////
class MouseMoveHandlers : public ec::GlobalMasBase,
                          public ec::Singleton<MouseMoveHandlers> {
 private:
    friend ec::Singleton<MouseMoveHandlers>;
    MouseMoveHandlers() { setCount(Handlers::Movement::Count); }
};

}  // namespace guil

#endif