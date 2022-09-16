//
// Created by p.gutsche on 16.09.2022.
//

class Window {
private:
    int width, height;
    string title;
    long glfwWindow;
    static Window* window;

    Window() {
        this.width = 1920;
        this.height = 1280;
        this.title = "BunkerGame";
        this.r = 1;
        this.g = 1;
        this.b = 1;
        this.a = 1;
    }

public:
    float r, g, b, a;

    static Window* get() {
        if (window == nullptr) {
            window = ~Window();
        }
        return window;
    }

    void run() {
        init();
        loop();
    }
};
