#ifndef _GUIL_GLOBAL_HANDLERS_HPP_
#define _GUIL_GLOBAL_HANDLERS_HPP_

#include <SFML/Window/Event.hpp>
#include <TMBEL/handler.hpp>

namespace guil {

////////////////////////////////////////////////////////////
/// \brief Main event parser.
////////////////////////////////////////////////////////////

class MainParser : public ec::ParserBase<sf::Event> {
 private:
    ec::UniqueContainer handlers_;

 public:
    MainParser();
    void call(const sf::Event& event) override;
};

}  // namespace guil

#endif