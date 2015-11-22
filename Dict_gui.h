#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class Dict_gui : public Gtk::Window
{
public:
  Dict_gui();
  virtual ~Dict_gui();

protected:

  void fill_buffers();
  Gtk::Entry m_entry;
  Gtk::Box m_addbox;
  Gtk::Button button;
  
  //Signal handlers:
  void on_button_quit();
  void on_button_buffer1();
  void on_button_buffer2();
  void search_clicked();
  //Child widgets:
  Gtk::Box m_VBox;

  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TextView m_TextView;
  
  Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer1, m_refTextBuffer2;

  Gtk::ButtonBox m_ButtonBox;
  Gtk::Button m_Button_Quit, m_Button_Buffer1, m_Button_Buffer2;
};

#endif //GTKMM_EXAMPLEWINDOW_H
