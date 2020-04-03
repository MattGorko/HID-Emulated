#include <gtkmm.h>
#include <iostream>


#define UI_PATH(FILENAME) (UI_DIR "/" FILENAME)
#define UI_MAIN_WINDOW UI_PATH("main_window.ui")


/**
** \brief Entry point of the gtk app
**
** \param argc The argc
** \param argv The argv
** \return 0
*/
int main(int argc, char *argv[])
{
    /* App creation */
    auto app = Gtk::Application::create(argc, argv,
                                        "org.HID-Emulated");

    /* Builder */
    auto builder = Gtk::Builder::create();

    /* Load ui */
    try {
        builder->add_from_file(UI_MAIN_WINDOW);
    }
    catch (const Glib::FileError& e) {
        std::cerr << "File not found: " << UI_MAIN_WINDOW;
        std::cerr << std::endl;
    }

    /* Main window */
    Gtk::Window *main_window = nullptr;
    builder->get_widget("main_window", main_window);

    /* Run app */
    if (main_window != nullptr)
        app->run(*main_window);

    /* Destructors */
    delete(main_window);

    return 0;
}