#include <GUIL/Handlers/global.hpp>
#include <GUIL/Handlers/global_handlers.hpp>
#include <GUIL/controller.hpp>
#include <TMBEL/utils.hpp>

namespace guil {

////////////////////////////////////////////////////////////
// Controller implementation
////////////////////////////////////////////////////////////

Controller::Controller() : render_instance_(nullptr), running_(false) {
    handlers_.push(*handler_list_.attach(new MainParser()));
    GlobalHandlers::getInstance()->push(Handlers::Global::Main, &handler_list_);
}

void Controller::close() { running_ = false; }

void Controller::attach(RenderWin* render_instance) {
    render_instance_ = render_instance;
}

void Controller::process() {
    running_ = true;

    while (running_) {
        event_queue_.splice(*render_instance_->getEvents());
        call();
    }
}

}  // namespace guil
