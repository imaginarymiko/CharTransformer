#include <filesystem>
#include <fstream>
#include "transformtext.hh"

enum class Direction { Null, To, From, Hiragana, Katakana };

TextType processName(std::string& lang) {
    if (lang == "Japanese" || lang == "japanese" || lang == "ja" || lang == "jp") {
        return TextType::Japanese;
    } else if (lang == "Russian" || lang == "russian" || lang == "ru") {
        return TextType::RussianCyrillic;
    } else {
        return TextType::Null;
    }
}

int main(int argc, char** argv) {
    std::string filename, language, direction;
    std::string text;
    TextType lang = TextType::Null;
    Direction d = Direction::Null;
    TransformText t;
    try {
        if (argc == 4) {
            filename = argv[1];
            language = argv[2];
            direction = argv[3];
        } else if (argc == 1) {
            std::cout << "Please provide the text you wish to convert" << std::endl;
            std::getline(std::cin, text);
            std::cout << "Please specify the language of the text" << std::endl;
            std::cin.clear();
            std::cin >> language;
            lang = processName(language);
            while (lang == TextType::Null) {
                std::cout << "That is not a valid language name.\n";
                std::cout << "Please specify the language of the text" << std::endl;
                std::cin.clear();
                std::cin >> language;
                lang = processName(language);
            }
            t.setText(text, lang);
            std::cout << "Please specify the direction of the conversion" << std::endl;
            std::cin >> direction;
            while (d == Direction::Null) {
                if (direction == "to") {
                    d = Direction::To;
                    break;
                } else if (direction == "from") {
                    d = Direction::From;
                    break;
                } else if (lang == TextType::Japanese && (direction == "hiragana" || direction == "Hiragana")) {
                    d = Direction::Hiragana;
                    break;
                } else if (lang == TextType::Japanese && (direction == "katakana" || direction == "Katakana")) {
                    d = Direction::Katakana;
                    break;
                } else {
                    std::cout << "This is not a valid direction." << std::endl;
                    std::cout << "Please specify the direction of the conversion" << std::endl;
                    std::cin.clear();
                    std::cin >> direction;
                }
            }
            switch (lang) {
                case TextType::Japanese:
                    switch (d) {
                        case Direction::To:
                            break;
                        case Direction::From:
                            break;
                        case Direction::Hiragana:
                            break;
                        case Direction::Katakana:
                            break;
                        default:
                            throw std::invalid_argument("How did you even get here?");
                    }
                    break;
                case TextType::RussianCyrillic:
                    switch (d) {
                        case Direction::To:
                            std::cout << t.latinToRussianCyrillic() << std::endl;
                            break;
                        case Direction::From:
                            std::cout << t.russianCyrillicToLatin() << std::endl;
                            break;
                        default:
                            throw std::invalid_argument("How did you even get here?");
                    }
                    break;
                default:
                    throw std::invalid_argument("How did you even get here?");
            }
        } else {
            throw std::invalid_argument("Invalid arguments count.");
        }
        return 0;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}