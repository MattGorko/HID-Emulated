#include <glib.h>
#include <gtkmm.h>
#include <gtkmm/application.h>
#include <gtkmm/builder.h>
#include <iostream>

#include "app.h"
#include "mainwindow.h"


/**
** \brief Application constructor
**
** \param argc The argc
** \param argv The argv
*/
Application::Application(int argc, char *argv[])
    : Gtk::Application(argc, argv, APP_ID),
    main_window(nullptr)
{
}

/**
** \brief Application destructor
*/
Application::~Application()
{
}

/**
** \brief Create the main_window
**
** \return The main_window
*/
Gtk::Window *Application::create_main_window(void)
{
    auto main_window = MainWindow::create();

    this->add_window(*main_window);

    main_window->signal_hide().connect(
        sigc::bind<Gtk::Window*>(sigc::mem_fun(
            *this,
            &Application::on_hide_window), main_window)
        );

    return main_window;
}

/**
** \brief Application on activate handler
*/
void Application::on_activate(void)
{
    /* Build main window  */
    this->main_window = this->create_main_window();
    this->main_window->present();
}

/**
** \brief Application on hide handler
**
** \param window The hidden window
*/
void Application::on_hide_window(Gtk::Window* window)
{
    delete window;
}

/**
** \brief Entry point of the gtk app
**
** \param argc The argc
** \param argv The argv
** \return 0
*/
int main(int argc, char *argv[])
{
    /* Application creation */
    auto app = Application(argc, argv);

    /* Application run */
    return app.run();
}