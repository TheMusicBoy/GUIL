#ifndef _GUIL_WINDOW_HANDLERS_HPP_
#define _GUIL_WINDOW_HANDLERS_HPP_

#include <SFML/Window/Event.hpp>
#include <TMBEL/handler.hpp>

namespace guil {

////////////////////////////////////////////////////////////
/// \brief Class used to parse window events
////////////////////////////////////////////////////////////
class WindowParser : public ec::ParserBase<sf::Event> {
 protected:
    ec::UniqueContainer handlers_;

 public:
    WindowParser();

    void call(const sf::Event& event) override;
};

////////////////////////////////////////////////////////////
/// \brief Class used to parse window focus events
////////////////////////////////////////////////////////////
class FocusParser : public ec::ParserBase<sf::Event> {
 public:
    FocusParser();

    void call(const sf::Event& event) override;
};

}  // namespace guil

#endif