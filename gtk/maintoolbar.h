#ifndef MAIN_TOOLBAR_H
#define MAIN_TOOLBAR_H

#include <gtkmm.h>


class MainToolbar : public Gtk::Toolbar
{
public:
    /* Constructors */
    MainToolbar(void) = delete;
    MainToolbar(BaseObjectType* cobject,
                const Glib::RefPtr<Gtk::Builder>& builder);

    /* Destructor */
    virtual ~MainToolbar();

    /* Methods */
    static MainToolbar* create(
        const Glib::RefPtr<Gtk::Builder>& builder);

private:
    /* Attribute */
    const Glib::RefPtr<Gtk::Builder>& builder_;

    /* Widgets */
    Gtk::ToolButton* add_button_;
    Gtk::ToolButton* remove_button_;

    /* Methods */
    void on_toolbutton_add_clicked(void) const;
    void on_toolbutton_remove_clicked(void) const;
};

#endif