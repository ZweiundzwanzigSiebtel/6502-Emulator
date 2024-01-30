#include <gtkmm.h>
#include <iostream>

namespace {
    Glib::RefPtr<Gtk::Application> app;
    Gtk::Window* window = nullptr;
    Gtk::TextView* editor = nullptr;
    Gtk::TextView* hex_editor_view = nullptr;
    Gtk::Button* run_btn = nullptr;
    Gtk::Button* save_btn = nullptr;
    Gtk::DrawingArea* drawing_area = nullptr;

    void on_save_clicked() {
        std::cout << "save" << std::endl;
    }

    void on_run_clicked() {
        const std::shared_ptr<Gtk::TextBuffer> text_buffer = editor->get_buffer();
        const Glib::ustring text = text_buffer->get_text();
        std::cout << text << std::endl;
    }

    template<typename T>
    auto set_css(const Glib::RefPtr<Gtk::CssProvider>& provider, const T& widget) {
        auto context = widget->get_style_context();
        context->add_provider(provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    }


    void on_app_activate() {
        // Erstelle das GtkBuilder-Objekt
        auto builder = Gtk::Builder::create();

        try {
            // Lade die Glade-Datei
            builder->add_from_file("../view/gui.glade");
        } catch (const Glib::FileError& ex) {
            std::cerr << "FileError: " << ex.what() << std::endl;
            return;
        } catch (const Glib::MarkupError& ex) {
            std::cerr << "MarkupError: " << ex.what() << std::endl;
            return;
        } catch (const Gtk::BuilderError& ex) {
            std::cerr << "BuilderError: " << ex.what() << std::endl;
            return;
        }

        // Erhalte das GtkWindow-Objekt und das GtkPaned-Objekt aus dem Builder
        window = builder->get_widget<Gtk::Window>("window");

        run_btn = builder->get_widget<Gtk::Button>("run_btn");
        run_btn->signal_clicked().connect(sigc::ptr_fun(&on_run_clicked));

        save_btn = builder->get_widget<Gtk::Button>("save_btn");
        save_btn->signal_clicked().connect(sigc::ptr_fun(&on_save_clicked));


        // Erhalte die GtkTextView-Objekte aus dem Builder
        editor = builder->get_widget<Gtk::TextView>("text_view");
        hex_editor_view = builder->get_widget<Gtk::TextView>("hex_editor_view");
        drawing_area = builder->get_widget<Gtk::DrawingArea>("drawing_area");

        auto css_provider = Gtk::CssProvider::create();
        css_provider->load_from_path("../view/styles/editor.css");
        auto editor_style = editor->get_style_context();
        editor_style->add_provider(css_provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
        set_css(css_provider, editor);

        if (!window || !editor || !hex_editor_view || !run_btn) {
            std::cerr << "Unable to get necessary widgets from the builder." << std::endl;
            return;
        }

        // Setze den Text im TextView
        editor->get_buffer()->set_text("Hello, Gtkmm!");
        std::string line = "0000 0000 0000 0000 0000 0000 0000 0000 ................\n";
        std::string complete = "";
        for(int i = 0; i < 65536; ++i) {
            complete += line;
        }
        hex_editor_view->get_buffer()->set_text(complete);

        app->add_window(*window);
        window->show();
    }
} // anonymous namespace

int main(int argc, char* argv[]) {
    // Initialisiere die GTK-Anwendung
    app = Gtk::Application::create("org.gtkmm.example");

    // Connect the "activate" signal to the handler function
    app->signal_activate().connect([]() { on_app_activate(); });

    // Run the application
    return app->run(argc, argv);
}
