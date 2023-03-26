#ifndef _GUIL_KEYBOARD_HANDLERS_HPP_
#define _GUIL_KEYBOARD_HANDLERS_HPP_

#include <SFML/Window/Event.hpp>
#include <TMBEL/global_container.hpp>
#include <TMBEL/handler.hpp>
#include <TMBEL/utils.hpp>

namespace guil {

////////////////////////////////////////////////////////////
/// \brief Class used to parse keyboard event
////////////////////////////////////////////////////////////
class KeyboardParser : public ec::ParserBase<sf::Event> {
 private:
    ec::UniqueContainer handlers_;

 public:
    KeyboardParser();
    void call(const sf::Event& event) override;
};

////////////////////////////////////////////////////////////
/// \brief Class used to parse event by keys
////////////////////////////////////////////////////////////
class KeyParser : public ec::ParserBase<sf::Event> {
 protected:
    ec::UniqueContainer handlers_;
    
 public:
    KeyParser();
    void call(const sf::Event& event) override;
};

////////////////////////////////////////////////////////////
/// \brief Class used to parse event by actions
////////////////////////////////////////////////////////////
class KeyActionParser : public ec::ParserBase<sf::Event> {
 public:
    KeyActionParser(uint32_t key);
    void call(const sf::Event& event) override;
};

}  // namespace guil

#endif