#ifndef _GUIL_CONTROLLER_HPP_
#define _GUIL_CONTROLLER_HPP_

#include <GUIL/render.hpp>
#include <SFML/Window/Event.hpp>
#include <TMBEL/controller.hpp>
#include <TMBEL/global_container.hpp>

namespace guil {


////////////////////////////////////////////////////////////
/// \brief Class that controlls window events
////////////////////////////////////////////////////////////

class Controller : public ec::ControllerBase<sf::Event> {
 protected:
    using Self = Controller;
    using Base = ec::ControllerBase<sf::Event>;

    ec::UniqueContainer handlers_;
    RenderWin* render_instance_;
    bool running_;

 public:
    Controller();
    ~Controller() = default;

    void close();

    void attach(RenderWin* render_instance);

    void process() override;
};

}  // namespace guil

#endif