#include <iostream>

#include "maintoolbar.h"


/**
** \brief MainToolbar constructor
**
** \param cobject The base c object
** \param builder The current builder
*/
MainToolbar::MainToolbar(BaseObjectType* cobject,
                         const Glib::RefPtr<Gtk::Builder>& builder)
    : Toolbar(cobject),
    builder_(builder),
    add_button_(nullptr),
    remove_button_(nullptr)
{
    /* Get buttons */
    this->builder_->get_widget("toolbutton_add", this->add_button_);
    this->builder_->get_widget("toolbutton_remove",
                               this->remove_button_);

    /* Connect buttons */
    if (this->add_button_ != nullptr)
        this->add_button_->signal_clicked().connect(
            sigc::mem_fun(
                *this,
                &MainToolbar::on_toolbutton_add_clicked)
        );
    if (this->remove_button_ != nullptr)
        this->remove_button_->signal_clicked().connect(
            sigc::mem_fun(
                *this,
                &MainToolbar::on_toolbutton_remove_clicked)
        );
}

/**
** \brief MainToolbar destructor
*/
MainToolbar::~MainToolbar()
{
}

/**
** \brief Create a MainToolbar from an xml builder file
**
** \return The new MainToolbar
*/
MainToolbar* MainToolbar::create(
        const Glib::RefPtr<Gtk::Builder>& builder)
{
    /* Main toolbar */
    MainToolbar* main_toolbar = nullptr;

    /* Get main toolbar: the derived toolbar widget */
    builder->get_widget_derived("toolbar", main_toolbar);

    return main_toolbar;
}

/**
** \brief Add toolbutton handler
*/
void MainToolbar::on_toolbutton_add_clicked(void) const
{
    std::cout << "MainToolbar::on_toolbutton_add" << std::endl;
}

/**
** \brief Add toolbutton handler
*/
void MainToolbar::on_toolbutton_remove_clicked(void) const
{
    std::cout << "MainToolbar::on_toolbutton_remove" << std::endl;
}
