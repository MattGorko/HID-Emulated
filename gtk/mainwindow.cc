#include <gtkmm/builder.h>
#include <iostream>

#include "mainwindow.h"


/**
** \brief MainWindow constructor
**
** \param cobject The base c object
** \param builder The current builder
*/
MainWindow::MainWindow(BaseObjectType* cobject,
                       const Glib::RefPtr<Gtk::Builder>& builder)
    : Gtk::Window(cobject),
    builder_(builder),
    menubar_(nullptr),
    toolbar_(nullptr)
{
    /*
     * Encapsulate the manipulation of the child widgets via
     * builder
     */
    this->builder_->get_widget("menubar", menubar_);
    this->toolbar_ = MainToolbar::create(this->builder_);
}

/**
** \brief MainWindow destructor
*/
MainWindow::~MainWindow()
{
}

/**
** \brief Create a MainWindow from an xml builder file
**
** \return The new MainWindow
*/
MainWindow* MainWindow::create(void)
{
    /* Main window */
    MainWindow* main_window = nullptr;

    /* Builder creation */
    auto builder = Gtk::Builder::create();

    /* Load ui */
    try {
        builder->add_from_file(UI_MAIN_WINDOW);
    }
    catch (const Glib::FileError& e) {
        std::cerr << "File not found: " << UI_MAIN_WINDOW;
        std::cerr << ":" << e.what() << std::endl;
    }

    /* Get main window: the derived window widget */
    builder->get_widget_derived("main_window", main_window);

    /* Title */
    main_window->set_title("HID-Emulated");

    return main_window;
}