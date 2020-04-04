#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include <gtkmm/window.h>

#include "app.h"
#include "maintoolbar.h"


#define UI_MAIN_WINDOW UI_PATH("main_window.ui")


class MainWindow : public Gtk::Window
{
public:
    /* Constructors */
    MainWindow(void) = delete;
    MainWindow(BaseObjectType* cobject,
               const Glib::RefPtr<Gtk::Builder>& builder);

    /* Destructor */
    virtual ~MainWindow();

    /* Methods */
    static MainWindow* create(void);

private:
    /* Attributes */
    Glib::RefPtr<Gtk::Builder> builder_;

    /* Widgets */
    Gtk::MenuBar* menubar_;
    MainToolbar* toolbar_;
};

#endif