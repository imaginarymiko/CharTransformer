#pragma once
#include <algorithm>
#include <cctype>
#include <filesystem>
#include <iostream>
#include <locale>
#include <string>
#include "charactermaps.hh"

enum class TextType { Null, // Null is used for empty strings
                      Japanese, RussianCyrillic,
                      /* OldRussianCyrillic, UkrainianCyrillic, BelorussianCyrillic, SerbianCyrillic, KazakhCyrillic */  // TODO: Other scripts
                      /* PolishCyrillic, ChineseCyrillic, Bopomofo */ // ? Experimental scripts, to be implemented in the future potentially
                      };

class TransformText {
    std::string text;
    TextType textType;
  public:
    // Constructors
    TransformText();
    TransformText(std::string& text, TextType& texttype);

    // Accessors
    std::string getText() const;
    TextType getTextType() const;
    void setText(std::string& text, TextType& texttype);

    // Methods
    std::string romajiToJapanese() const;
    std::string japaneseToRomaji() const;
    std::string latinToRussianCyrillic() const;
    std::string russianCyrillicToLatin() const;
};

