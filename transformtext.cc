#include "transformtext.hh"

// Constructors
TransformText::TransformText(): text{""}, textType{TextType::Null} {}

TransformText::TransformText(std::string& text, TextType& texttype):
    text{text}, textType{texttype} {
        if (texttype == TextType::Null && !text.empty()) {
            throw std::invalid_argument("Non-empty text cannot be of type Null");
        }
    }

// Accessors
std::string TransformText::getText() const {
    return this->text;
}

TextType TransformText::getTextType() const {
    return this->textType;
}

void TransformText::setText(std::string& text, TextType& texttype) {
    this->text = text;
    this->textType = texttype;
    if (texttype == TextType::Null && !text.empty()) {
        throw std::invalid_argument("Non-empty text cannot be of type Null");
    }
}

// Methods
std::string TransformText::romajiToJapanese() const {
    bool katakana = false;
    size_t length = this->text.length();
    std::string transformed_text(this->text);
    transform(transformed_text.begin(), transformed_text.end(), transformed_text.begin(), ::tolower);
    std::string converted = "";
    size_t i = 0;
    try {
        while (i < length) {
            if (this->text[i] == '*') {
                // '*' denotes Hiragana/Katakana switch
                katakana = !katakana;
                ++i;
            } else if (isspace(this->text[i])) {
                // isolated wa -> ha
                if (i + 3 < length && this->text.substr(i, 4) == " wa ") {
                    // wa -> ha
                    converted += " " + (katakana ? Katakana : Hiragana).at("ha") + " ";
                    i += 4;
                    continue;
                }
                converted += " ";
                ++i;
            } else if (i + 2 < length && this->text.substr(i, 2) == "nn" && (katakana ? Katakana : Hiragana).find(this->text.substr(i + 1, 2)) == (katakana ? Katakana : Hiragana).end()) {
                // n rule
                converted += (katakana ? Katakana["sakuon"] : Hiragana["sakuon"]);
            } else {
                std::size_t compare = std::min<std::size_t>(3, length - i);
                while (compare > 0) {
                    std::string comparatorString = this->text.substr(i, compare);
                    if ((katakana ? Katakana : Hiragana).find(comparatorString) != (katakana ? Katakana : Hiragana).end()) {
                        converted += (katakana ? Katakana : Hiragana).at(comparatorString);
                        i += compare;
                        if (i < length) {
                            if (this->text[i] == 'o' && this->text[i - 1] == 'o' && !katakana) {
                                // oo -> ou
                                converted += Hiragana.at("u");
                                ++i;
                            } else if (this->text[i] == 'e' && this->text[i - 1] == 'e' && !katakana) {
                                // ee -> ei
                                converted += Hiragana.at("i");
                                ++i;
                            } else if (this->text[i] == this->text[i - 1] && katakana) {
                                if (this->text[i] == 'n') {
                                    break;
                                } else if (this->text[i] == 'a' || this->text[i] == 'e' || this->text[i] == 'i' || this->text[i] == 'o' || this->text[i] == 'u') {
                                    converted += Katakana.at("pause");
                                } else {
                                    converted += Katakana.at("sakuon");
                                }
                                ++i;
                            }
                            break;
                        } else if (compare == 1) {
                            // process punctuation: '?', '.', '!' -> '。'
                            if (comparatorString == "?" || comparatorString == "." || comparatorString == "!")
                                converted += "。";
                        } else if (!(comparatorString >= "a" && comparatorString <= "z")) {
                            converted += comparatorString;
                        } else if (i + 1 < length) {
                            // process little tsu
                            if (comparatorString == this->text.substr(i + 1, 1))
                                converted += (katakana ? Katakana : Hiragana).at("sakuon");
                        }
                        ++i;
                        break;
                    }
                    --compare;
                }
            }
        }
        return converted;
    } catch (...) {
        throw;
    }
}

std::string TransformText::latinToRussianCyrillic() const {
    size_t length = this->text.length();
    std::string converted = "";
    size_t i = 0;
    try {
        while (i < length) {
            wchar_t ch = this->text[i];
            switch (ch) {
            case L's':
            case L'S':
                if (i + 3 <= length && this->text.substr(i + 1, 3) == "hch") {
                    converted += RussianCyrillic.at(std::iswupper(ch) ? "Shch" : "shch");
                    i += 3;
                } else if (i + 1 <= length && this->text[i + 1] == 'h') {
                    converted += RussianCyrillic.at(std::iswupper(ch) ? "Sh" : "sh");
                    ++i;
                } else {
                    converted += RussianCyrillic.at(std::iswupper(ch) ? "S" : "s");
                }
                break;
            case L'š':
            case L'Š':
                if (i + 1 <= length && this->text[i + 1] == L'č') {
                    converted += RussianCyrillic.at(std::iswupper(ch) ? "Shch" : "shch");
                    ++i;
                } else {
                    converted += RussianCyrillic.at(std::iswupper(ch) ? "Sh" : "sh");
                }
                break;
            case L'z':
            case L'Z':
                if (i + 1 <= length && this->text[i + 1] == 'h') {
                    converted += RussianCyrillic.at(std::iswupper(ch) ? "Zh" : "zh");
                    ++i;
                } else {
                    converted += RussianCyrillic.at(std::iswupper(ch) ? "Z" : "z");
                }
                break;
            case L'y':
            case L'Y':
            case L'j':
            case L'J':
                // handle ya/ja/yu/ju/yo/jo in the same case
                if (i + 1 <= length && this->text[i + 1] == 'o') {
                    converted += RussianCyrillic.at(std::iswupper(ch) ? "Yo" : "yo");
                    ++i;
                } else if (i + 1 <= length && this->text[i + 1] == 'u') {
                    converted += RussianCyrillic.at(std::iswupper(ch) ? "Yu" : "yu");
                    ++i;
                } else if (i + 1 <= length && this->text[i + 1] == 'a') {
                    converted += RussianCyrillic.at(std::iswupper(ch) ? "Ya" : "ya");
                    ++i;
                } else {
                    // 'y' and 'j' map to different characters
                    converted += RussianCyrillic.at(std::iswupper(ch) ? (ch == 'Y' ? "Y" : "J") : (ch == 'y' ? "y" : "j"));
                }
            case L'k':
            case L'K':
                if (i + 1 <= length && this->text[i + 1] == 'h') {
                    converted += RussianCyrillic.at(std::iswupper(ch) ? "Kh" : "kh");
                    ++i;
                } else {
                    converted += RussianCyrillic.at(std::iswupper(ch) ? "K" : "k");
                }
            case L't':
            case L'T':
                if (i + 1 <= length && this->text[i + 1] == 's') {
                    converted += RussianCyrillic.at(std::iswupper(ch) ? "Ts" : "ts");
                    ++i;
                } else {
                    converted += RussianCyrillic.at(std::iswupper(ch) ? "T" : "t");
                }
            case L'c':
            case L'C':
                if (i + 1 <= length && this->text[i + 1] == 'h') {
                    converted += RussianCyrillic.at(std::iswupper(ch) ? "Ch" : "ch");
                } else {
                    // maps to the same thing as 'ts'
                    converted += RussianCyrillic.at(std::iswupper(ch) ? "C" : "c");
                }
            default:
                std::wstring ws(1, ch);
                std::string s(ws.begin(), ws.end());
                if (RussianCyrillic.find(s) == RussianCyrillic.end()) {
                    converted += s;
                } else {
                    converted += RussianCyrillic.at(s);
                }
                break;
            }
            ++i;
        }
        return converted;
    } catch (...) {
        throw;
    }
}

std::string TransformText::russianCyrillicToLatin() const {
    size_t length = this->text.length();
    std::string converted = "";
    size_t i = 0;
    while (i < length) {
        std::wstring ws(1, this->text[i]);
        std::string s(ws.begin(), ws.end());
        if (RussianCyrillic.find(s) == RussianCyrillic.end()) {
            converted += s;
        } else {
            converted += RussianCyrillic.at(s);
        }
        ++i;
    }
    return converted;
}