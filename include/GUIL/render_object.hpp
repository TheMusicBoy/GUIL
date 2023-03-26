#ifndef _GUIL_RENDER_OBJECT_HPP_
#define _GUIL_RENDER_OBJECT_HPP_

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <list>
#include <mutex>

namespace guil {

class ObjectBase;

////////////////////////////////////////////////////////////
/// \brief Base class of object list.
////////////////////////////////////////////////////////////
class ListBase {
 protected:
    using Container = std::list<ObjectBase*>;
    using Position  = typename Container::iterator;

    mutable std::mutex lock_;
    Container resource_;

 public:
    ListBase()                = default;
    ListBase(const ListBase&) = delete;
    ListBase(ListBase&&);
    ~ListBase();

    ListBase& operator=(ListBase&& other);

    Position attach(ObjectBase* object);
    Position attach(Position position, ObjectBase* object);

    void detach(Position position);
};

////////////////////////////////////////////////////////////
/// \brief Base class of objects.
////////////////////////////////////////////////////////////
class ObjectBase {
 protected:
    using Container = ListBase;
    using Position  = std::list<ObjectBase*>::iterator;

    Container* container_;
    Position position_;
    void* object_;

 public:
    ObjectBase(void* object_);
    ObjectBase(Container* container, void* object_);
    ObjectBase(Position position, Container* container, void* object);
    ~ObjectBase();

    void* get();

    Position attach(Container* container);
    Position attach(Position position, Container* container);

    void detach();
};

////////////////////////////////////////////////////////////
/// \brief List of object that can be drawn.
////////////////////////////////////////////////////////////
class RenderList : virtual public ListBase, public sf::Drawable {
 public:
    RenderList();
    RenderList(RenderList&& other);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

}  // namespace guil

#endif