#include <GUIL/render_object.hpp>

namespace guil {

////////////////////////////////////////////////////////////
// ListBase implementation
////////////////////////////////////////////////////////////

ListBase::ListBase(ListBase&& other) { *this = std::move(other); }

ListBase::~ListBase() { std::lock_guard lock(lock_); }

ListBase& ListBase::operator=(ListBase&& other) {
    other.lock_.lock();
    this->lock_.lock();

    resource_ = std::move(other.resource_);

    this->lock_.unlock();
    other.lock_.unlock();

    return *this;
}

std::list<ObjectBase*>::iterator ListBase::attach(ObjectBase* object) {
    std::lock_guard lock(lock_);
    resource_.push_back(object);
    return std::prev(resource_.end());
}

std::list<ObjectBase*>::iterator ListBase::attach(Position position,
                                                  ObjectBase* object) {
    std::lock_guard lock(lock_);
    return resource_.insert(position, object);
}

void ListBase::detach(Position position) {
    std::lock_guard lock(lock_);
    resource_.erase(position);
}

////////////////////////////////////////////////////////////
// ObjectBase implementation
////////////////////////////////////////////////////////////

ObjectBase::ObjectBase(void* object) : container_(nullptr), object_(object) {}

ObjectBase::ObjectBase(Container* container, void* object)
    : ObjectBase(object) {
    attach(container);
}

ObjectBase::ObjectBase(Position position, Container* container, void* object)
    : ObjectBase(object) {
    attach(position, container);
}

ObjectBase::~ObjectBase() { detach(); }

std::list<ObjectBase*>::iterator ObjectBase::attach(Container* container) {
    detach();
    container_       = container;
    return position_ = container_->attach(this);
}

std::list<ObjectBase*>::iterator ObjectBase::attach(Position position,
                                                    Container* container) {
    detach();
    container_       = container;
    return position_ = container_->attach(position, this);
}

void ObjectBase::detach() {
    if (container_ != nullptr) {
        container_->detach(position_);
        container_ = nullptr;
    }
}

////////////////////////////////////////////////////////////
// RenderList implementation
////////////////////////////////////////////////////////////

RenderList::RenderList() : ListBase() {}

RenderList::RenderList(RenderList&& other) : ListBase(std::move(other)) {}

void RenderList::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    std::lock_guard lock(lock_);
    for (auto& el : resource_)
        target.draw(*static_cast<sf::Drawable*>(el->get()), states);
}

}  // namespace guil
