#include "../include/printer.hpp"
#include <cstdio>

namespace advprint {

    struct RGB { int r, g, b; };

    static RGB toRGB(Color color) {
        switch (color) {
            case Color::red:   return {255, 0, 0};
            case Color::white: return {255, 255, 255};
            case Color::black: return {0, 0, 0};
            case Color::yellow: return {255,255,0};
        }
        return {255, 255, 255};
    }

    void goTo(int x, int y) { 
        std::printf("\x1B[%d;%dH", y, x); 
    }

    void resetColor() { 
        std::printf("\x1B[0m"); 
    }


    void setColor(Color color) {
        RGB c = toRGB(color);
        std::printf("\x1B[38;2;%d;%d;%dm", c.r, c.g, c.b);
    }

    void write(const std::string& text, Color color) {
        setColor(color);
        std::printf("%s", text.c_str());
        resetColor();
        std::fflush(stdout);
    }

    void writeAt(int x, int y, const std::string& text, Color color) {
        goTo(x, y);
        write(text, color);
    }

    void clear() {
        std::printf("\x1B[2J\x1B[H");
        std::fflush(stdout);
    }

}