#include <GUIL/render.hpp>

namespace guil {

////////////////////////////////////////////////////////////
// Render implementation
////////////////////////////////////////////////////////////

Render::Render() : target_(nullptr) {}

Render::Render(Target* target) : target_(target) {}

void Render::setTarget(Target* target) { target_ = target; }

std::list<ObjectBase*>::iterator Render::attach(ObjectBase* object) {
    return object->attach(&resource_);
}

std::list<ObjectBase*>::iterator Render::attach(Position position,
                                                ObjectBase* object) {
    return object->attach(position, &resource_);
}

void Render::detach(Position position) { resource_.detach(position); }

void Render::draw() const {
    if (target_ != nullptr) {
        target_->clear();
        target_->draw(resource_);
    }
}

////////////////////////////////////////////////////////////
// RenderWin implementation
////////////////////////////////////////////////////////////

RenderWin::RenderWin() : running_(false) { this->setTarget(this); }

RenderWin::RenderWin(sf::VideoMode video_mode, const std::wstring& title,
                     uint32_t style,
                     const sf::ContextSettings& context)
    : Base(video_mode, title, style, context) {
    this->setTarget(this);
    running_ = true;
}

RenderWin::~RenderWin() {
    if (this->isOpen())
        this->Base::close();
}

void RenderWin::open(
    sf::VideoMode video_mode, const std::wstring& title, uint32_t style,
    const sf::ContextSettings& context) {
    this->create(video_mode, title, style, context);
    running_ = true;
}

void RenderWin::close() {
    running_ = false;
}

ec::EventQueue<sf::Event>* RenderWin::getEvents() { return &event_queue_; }

void RenderWin::call() {
    sf::Event event;
    while (this->pollEvent(event)) event_queue_.push(event);
    this->Render::draw();
    this->Base::display();
}

void RenderWin::process() { 
    while (running_)
        this->call();
}

}  // namespace guil