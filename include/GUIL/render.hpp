#ifndef _GUIL_RENDER_HPP_
#define _GUIL_RENDER_HPP_

#include <GUIL/render_object.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <TMBEL/controller.hpp>
#include <string>

namespace guil {

class Render {
 protected:
    using Container = RenderList;
    using Position  = std::list<ObjectBase*>::iterator;
    using Target    = sf::RenderTarget;

    Container resource_;
    Target* target_;

 public:
    Render();
    Render(Target* target);

    inline void setTarget(Target* target);

    inline Position attach(ObjectBase* object);
    inline Position attach(Position position, ObjectBase* object);

    inline void detach(Position position);

    void draw();
};

class RenderWin : public sf::RenderWindow {
 protected:
    using Self       = RenderWin;
    using Base       = sf::RenderWindow;
    using EventQueue = ec::EventQueue<sf::Event>;

    EventQueue event_queue_;
    Render render_;
    bool running_;

 public:
    RenderWin();
    RenderWin(sf::VideoMode video_mode, const std::wstring& title,
              uint32_t style,
              const sf::ContextSettings& context = sf::ContextSettings());

    void open(sf::VideoMode video_mode, const std::wstring& title,
              uint32_t style,
              const sf::ContextSettings& context = sf::ContextSettings());

    void close();

    EventQueue* getEvents();

    void call();

    void process();
};

}  // namespace guil

#endif