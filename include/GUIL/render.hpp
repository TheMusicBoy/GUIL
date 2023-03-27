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

    mutable Container resource_;
    Target* target_;

 public:
    Render();
    Render(Target* target);
    virtual ~Render() = default;

    void setTarget(Target* target);

    Position attach(ObjectBase* object);
    Position attach(Position position, ObjectBase* object);

    inline void detach(Position position);

    void draw() const;
};

class RenderWin : public sf::RenderWindow, public Render {
 protected:
    using Self       = RenderWin;
    using Base       = sf::RenderWindow;
    using EventQueue = ec::EventQueue<sf::Event>;

    EventQueue event_queue_;
    bool running_;

 public:
    RenderWin();
    RenderWin(sf::VideoMode video_mode, const std::wstring& title,
              uint32_t style,
              const sf::ContextSettings& context = sf::ContextSettings());
    ~RenderWin();

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