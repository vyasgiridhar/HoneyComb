
#include "Dict_gui.h"
#include <string.h>
#include <iostream>


using namespace std;


Dict_gui::Dict_gui()
: m_VBox(Gtk::ORIENTATION_VERTICAL),
  m_Button_Quit("_Quit", true),
  m_Button_Buffer1("Use buffer 1"),
  m_Button_Buffer2("Use buffer 2"),
  button("Search")

{
  set_title("Honey Comb Dictionary");
  set_border_width(5);
  set_default_size(400, 200);

  add(m_VBox);

  //Add the TreeView, inside a ScrolledWindow, with the button underneath:
  m_ScrolledWindow.add(m_TextView);

  //Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  

  m_entry.set_placeholder_text("Enter a RSS Url");
  
  m_addbox.pack_start(m_entry,Gtk::PACK_EXPAND_WIDGET);
  m_addbox.pack_start(button,Gtk::PACK_SHRINK);
  m_VBox.pack_start(m_addbox,Gtk::PACK_SHRINK);
  m_VBox.pack_start(m_ScrolledWindow);

  //Add buttons:
  m_VBox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);

  m_ButtonBox.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);
  m_ButtonBox.set_border_width(5);
  m_ButtonBox.set_spacing(5);
  m_ButtonBox.set_layout(Gtk::BUTTONBOX_END);

  //Connect signals:
  m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this,
              &Dict_gui::on_button_quit) );
  button.signal_clicked().connect(sigc::mem_fun(*this,&Dict_gui::search_clicked));
  fill_buffers();
  on_button_buffer1();

  show_all_children();
}

void Dict_gui::fill_buffers()
{
  m_refTextBuffer1 = Gtk::TextBuffer::create();
  m_refTextBuffer1->set_text("Enter a string to find the defenition");


}

Dict_gui::~Dict_gui()
{
}

void Dict_gui::on_button_quit()
{
  hide();
}

void Dict_gui::on_button_buffer1()
{
  m_TextView.set_buffer(m_refTextBuffer1);
}

void Dict_gui::on_button_buffer2()
{}
void Dict_gui::search_clicked(){

		string Dict = m_entry.get_text().raw();

		cout<<Dict;
}