#include <string>

namespace advprint {

    enum class Color { red, white, black, yellow };

    void goTo(int x, int y);
    void setColor(Color color);
    void resetColor();
    void write(const std::string& text, Color color);
    void writeAt(int x, int y, const std::string& text, Color color);
    void clear();

}