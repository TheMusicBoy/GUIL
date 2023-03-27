#include <GUIL/Handlers/mouse.hpp>
#include <GUIL/Handlers/window.hpp>
#include <GUIL/controller.hpp>
#include <TMBEL.hpp>
#include <iostream>
#include <thread>

int main() {
    guil::RenderWin render;
    guil::Controller controller;

    controller.attach(&render);

    render.open(sf::VideoMode(200, 200), L"Proga", sf::Style::Default);

    auto window_handlers = guil::WindowHandlers::getInstance();
    auto button_handlers = guil::ButtonHandlers::getInstance();

    ec::UniqueContainer handlers_;

    handlers_.push(*ec::syncHandler<sf::Event>(
        window_handlers->get(guil::Handlers::Window::Closed),
        [&render, &controller](const sf::Event&) {
            render.close();
            controller.close();
        }));

    handlers_.push(*ec::syncHandler<sf::Event>(
        button_handlers->get(sf::Mouse::Left),
        [](const sf::Event&) { std::cout << "aaa\n"; }));

    std::thread render_thread(&guil::RenderWin::process, std::ref(render));
    std::thread controller_thread(&guil::Controller::process,
                                  std::ref(controller));

    render_thread.join();
    controller_thread.join();

    ec::clearResource();
}