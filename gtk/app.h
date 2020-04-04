#ifndef APP_H
#define APP_H

#include <gtkmm.h>
#include <gtkmm/window.h>


/* UI Dir */
#ifndef UI_DIR
#define UI_DIR "ui"
#endif

/* UI Ressources */
#define UI_PATH(FILENAME) (UI_DIR "/" FILENAME)

/* Application ID */
#define APP_ID "org.hid.emulated"


class Application : public Gtk::Application
{
public:
    /* Constructors */
    Application(void) = delete;
    Application(int argc, char *argv[]);

    /* Destructors */
    virtual ~Application();

protected:
    /* Methods */
    void on_activate(void) override;

private:
    /* Methods */
    Gtk::Window *create_main_window(void);
    void on_hide_window(Gtk::Window* window);

    /* Attributes */
    Gtk::Window *main_window;

};

#endif