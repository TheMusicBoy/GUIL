#ifndef _GUIL_MOUSE_HANDLERS_HPP_
#define _GUIL_MOUSE_HANDLERS_HPP_

#include <SFML/Window/Event.hpp>
#include <TMBEL/handler.hpp>
#include <TMBEL/utils.hpp>

namespace guil {

////////////////////////////////////////////////////////////
/// \brief Class used to parse mouse events
////////////////////////////////////////////////////////////
class MouseParser : public ec::ParserBase<sf::Event> {
 private:
    ec::UniqueContainer handlers_;

 public:
    MouseParser();
    void call(const sf::Event& event) override;
};

////////////////////////////////////////////////////////////
/// \brief Class used to parse button events
////////////////////////////////////////////////////////////
class ButtonParser : public ec::ParserBase<sf::Event> {
 private:
    ec::UniqueContainer handlers_;

 public:
    ButtonParser();
    void call(const sf::Event& event) override;
};

////////////////////////////////////////////////////////////
/// \brief Class used to parse button actions
////////////////////////////////////////////////////////////
class ButtonActionParser : public ec::ParserBase<sf::Event> {
 public:
    ButtonActionParser(uint32_t button);
    void call(const sf::Event& event) override;
};

////////////////////////////////////////////////////////////
/// \brief Class used to parse mouse movement events
////////////////////////////////////////////////////////////
class MouseMoveParser : public ec::ParserBase<sf::Event> {
 public:
    MouseMoveParser();
    void call(const sf::Event& event) override;
};

}  // namespace guil

#endif