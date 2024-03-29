#include "charactermaps.hh"

std::unordered_map<std::string, std::string> Hiragana = {
    {"a", "あ"}, {"i", "い"}, {"u", "う"}, {"e", "え"}, {"o", "お"},
    {"ka", "か"}, {"ki", "き"}, {"ku", "く"}, {"ke", "け"}, {"ko", "こ"},
    {"sa", "さ"}, {"shi", "し"}, {"su", "す"}, {"se", "せ"}, {"so", "そ"},
    {"ta", "た"}, {"chi", "ち"}, {"tsu", "つ"}, {"te", "て"}, {"to", "と"},
    {"na", "な"}, {"ni", "に"}, {"nu", "ぬ"}, {"ne", "ね"}, {"no", "の"},
    {"ha", "は"}, {"hi", "ひ"}, {"fu", "ふ"}, {"he", "へ"}, {"ho", "ほ"},
    {"ma", "ま"}, {"mi", "み"}, {"mu", "む"}, {"me", "め"}, {"mo", "も"},
    {"ya", "や"}, {"yu", "ゆ"}, {"yo", "よ"},
    {"ra", "ら"}, {"ri", "り"}, {"ru", "る"}, {"re", "れ"}, {"ro", "ろ"},
    {"wa", "わ"}, {"wo", "を"},
    {"n", "ん"},
    {"ga", "が"}, {"gi", "ぎ"}, {"gu", "ぐ"}, {"ge", "げ"}, {"go", "ご"},
    {"za", "ざ"}, {"ji", "じ"}, {"zu", "ず"}, {"ze", "ぜ"}, {"zo", "ぞ"},
    {"da", "だ"}, {"dzi", "ぢ"}, {"dzu", "づ"}, {"de", "で"}, {"do", "ど"},
    {"ba", "ば"}, {"bi", "び"}, {"bu", "ぶ"}, {"be", "べ"}, {"bo", "ぼ"},
    {"pa", "ぱ"}, {"pi", "ぴ"}, {"pu", "ぷ"}, {"pe", "ぺ"}, {"po", "ぽ"},
    {"kya", "きゃ"}, {"kyu", "きゅ"}, {"kyo", "きょ"},
    {"sha", "しゃ"}, {"shu", "しゅ"}, {"she", "しぇ"}, {"sho", "しょ"},
    {"cha", "ちゃ"}, {"chu", "ちゅ"}, {"che", "ちぇ"}, {"cho", "ちょ"},
    {"nya", "にゃ"}, {"nyu", "にゅ"}, {"nyo", "にょ"},
    {"hya", "ひゃ"}, {"hyu", "ひゅ"}, {"hyo", "ひょ"},
    {"mya", "みゃ"}, {"myu", "みゅ"}, {"myo", "みょ"},
    {"rya", "りゃ"}, {"ryu", "りゅ"}, {"ryo", "りょ"},
    {"gya", "ぎゃ"}, {"gyu", "ぎゅ"}, {"gyo", "ぎょ"},
    {"ja", "じゃ"}, {"ju", "じゅ"}, {"je", "じぇ"}, {"jo", "じょ"},
    {"bya", "びゃ"}, {"byu", "びゅ"}, {"byo", "びょ"},
    {"pya", "ぴゃ"}, {"pyu", "ぴゅ"}, {"pyo", "ぴょ"},
    {"fa", "ふぁ"}, {"fi", "ふぃ"}, {"fe", "ふぇ"}, {"fo", "ふぉ"},
    {"ti", "てぃ"}, {"tu", "とぅ"},
    {"di", "でぃ"}, {"du", "どぅ"},
    {"va", "ゔぁ"}, {"vi", "ゔぃ"}, {"vu", "ゔ"}, {"ve", "ゔぇ"}, {"vo", "ゔぉ"},
    {"sakuon", "っ"}, {"pause", "ー"}
};

std::unordered_map<std::string, std::string> InvertedHiragana = {
    {"あ", "a"}, {"い", "i"}, {"う", "u"}, {"え", "e"}, {"お", "o"},
    {"か", "ka"}, {"き", "ki"}, {"く", "ku"}, {"け", "ke"}, {"こ", "ko"},
    {"さ", "sa"}, {"し", "shi"}, {"す", "su"}, {"せ", "se"}, {"そ", "so"},
    {"た", "ta"}, {"ち", "chi"}, {"つ", "tsu"}, {"て", "te"}, {"と", "to"},
    {"な", "na"}, {"に", "ni"}, {"ぬ", "nu"}, {"ね", "ne"}, {"の", "no"},
    {"は", "ha"}, {"ひ", "hi"}, {"ふ", "fu"}, {"へ", "he"}, {"ほ", "ho"},
    {"ま", "ma"}, {"み", "mi"}, {"む", "mu"}, {"め", "me"}, {"も", "mo"},
    {"や", "ya"}, {"ゆ", "yu"}, {"𛀁", "ye"}, {"よ", "yo"},
    {"ら", "ra"}, {"り", "ri"}, {"る", "ru"}, {"れ", "re"}, {"ろ", "ro"},
    {"わ", "wa"}, {"ゐ", "wi"}, {"ゑ", "we"}, {"を", "wo"},
    {"ん", "n"},
    {"が", "ga"}, {"ぎ", "gi"}, {"ぐ", "gu"}, {"げ", "ge"}, {"ご", "go"},
    {"ざ", "za"}, {"じ", "ji"}, {"ず", "zu"}, {"ぜ", "ze"}, {"ぞ", "zo"},
    {"だ", "da"}, {"ぢ", "dzi"}, {"づ", "dzu"}, {"で", "de"}, {"ど", "do"},
    {"ば", "ba"}, {"び", "bi"}, {"ぶ", "bu"}, {"べ", "be"}, {"ぼ", "bo"},
    {"ぱ", "pa"}, {"ぴ", "pi"}, {"ぷ", "pu"}, {"ぺ", "pe"}, {"ぽ", "po"},
    {"きゃ", "kya"}, {"きゅ", "kyu"}, {"きょ", "kyo"},
    {"しゃ", "sha"}, {"しゅ", "shu"}, {"しぇ", "she"}, {"しょ", "sho"},
    {"ちゃ", "cha"}, {"ちゅ", "chu"}, {"ちぇ", "che"}, {"ちょ", "cho"},
    {"にゃ", "nya"}, {"にゅ", "nyu"}, {"にょ", "nyo"},
    {"ひゃ", "hya"}, {"ひゅ", "hyu"}, {"ひょ", "hyo"},
    {"みゃ", "mya"}, {"みゅ", "myu"}, {"みょ", "myo"},
    {"りゃ", "rya"}, {"りゅ", "ryu"}, {"りょ", "ryo"},
    {"ぎゃ", "gya"}, {"ぎゅ", "gyu"}, {"ぎょ", "gyo"},
    {"じゃ", "ja"}, {"じゅ", "ju"}, {"じぇ", "je"}, {"じょ", "jo"},
    {"びゃ", "bya"}, {"びゅ", "byu"}, {"びょ", "byo"},
    {"ぴゃ", "pya"}, {"ぴゅ", "pyu"}, {"ぴょ", "pyo"},
    {"ふぁ", "fa"}, {"ふぃ", "fi"}, {"ふぇ", "fe"}, {"ふぉ", "fo"},
    {"てぃ", "ti"}, {"とぅ", "tu"},
    {"でぃ", "di"}, {"どぅ", "du"},
    {"ゔぁ", "va"}, {"ゔぃ", "vi"}, {"ゔ", "vu"}, {"ゔぇ", "ve"}, {"ゔぉ", "vo"},
    {"っ", "sakuon"}, {"ー", "pause"}
};

std::unordered_map<std::string, std::string> Katakana = {
    {"a", "ア"}, {"i", "イ"}, {"u", "ウ"}, {"e", "エ"}, {"o", "オ"},
    {"ka", "カ"}, {"ki", "キ"}, {"ku", "ク"}, {"ke", "ケ"}, {"ko", "コ"},
    {"sa", "サ"}, {"shi", "シ"}, {"su", "ス"}, {"se", "セ"}, {"so", "ソ"},
    {"ta", "タ"}, {"chi", "チ"}, {"tsu", "ツ"}, {"te", "テ"}, {"to", "ト"},
    {"na", "ナ"}, {"ni", "ニ"}, {"nu", "ヌ"}, {"ne", "ネ"}, {"no", "ノ"},
    {"ha", "ハ"}, {"hi", "ヒ"}, {"fu", "フ"}, {"he", "ヘ"}, {"ho", "ホ"},
    {"ma", "マ"}, {"mi", "ミ"}, {"mu", "ム"}, {"me", "メ"}, {"mo", "モ"},
    {"ya", "ヤ"}, {"yu", "ユ"}, {"yo", "ヨ"},
    {"ra", "ラ"}, {"ri", "リ"}, {"ru", "ル"}, {"re", "レ"}, {"ro", "ロ"},
    {"wa", "ワ"}, {"wo", "ヲ"},
    {"n", "ン"},
    {"ga", "ガ"}, {"gi", "ギ"}, {"gu", "グ"}, {"ge", "ゲ"}, {"go", "ゴ"},
    {"za", "ザ"}, {"ji", "ジ"}, {"zu", "ズ"}, {"ze", "ゼ"}, {"zo", "ゾ"},
    {"da", "ダ"}, {"dzi", "ヂ"}, {"dzu", "ヅ"}, {"de", "デ"}, {"do", "ド"},
    {"ba", "バ"}, {"bi", "ビ"}, {"bu", "ブ"}, {"be", "ベ"}, {"bo", "ボ"},
    {"pa", "パ"}, {"pi", "ピ"}, {"pu", "プ"}, {"pe", "ペ"}, {"po", "ポ"},
    {"kya", "キャ"}, {"kyu", "キュ"}, {"kyo", "キョ"},
    {"sha", "シャ"}, {"shu", "シュ"}, {"she", "シェ"}, {"sho", "ショ"},
    {"cha", "チャ"}, {"chu", "チュ"}, {"che", "チェ"}, {"cho", "チョ"},
    {"nya", "ニャ"}, {"nyu", "ニュ"}, {"nyo", "ニョ"},
    {"hya", "ヒャ"}, {"hyu", "ヒュ"}, {"hyo", "ヒョ"},
    {"mya", "ミャ"}, {"myu", "ミュ"}, {"myo", "ミョ"},
    {"rya", "リャ"}, {"ryu", "リュ"}, {"ryo", "リョ"},
    {"gya", "ギャ"}, {"gyu", "ギュ"}, {"gyo", "ギョ"},
    {"ja", "ジャ"}, {"ju", "ジュ"}, {"je", "ジェ"}, {"jo", "ジョ"},
    {"bya", "ビャ"}, {"byu", "ビュ"}, {"byo", "ビョ"},
    {"pya", "ピャ"}, {"pyu", "ピュ"}, {"pyo", "ピョ"},
    {"fa", "ファ"}, {"fi", "フィ"}, {"fe", "フェ"}, {"fo", "フォ"},
    {"ti", "ティ"}, {"tu", "トゥ"},
    {"di", "ディ"}, {"du", "ドゥ"},
    {"wi", "ウィ"}, {"we", "ウェ"},
    {"va", "ヴァ"}, {"vi", "ヴィ"}, {"vu", "ヴ"}, {"ve", "ヴェ"}, {"vo", "ヴォ"},
    {"sakuon", "ッ"}, {"pause", "ー"}
};

std::unordered_map<std::string, std::string> InvertedKatakana = {
    {"ア", "a"}, {"イ", "i"}, {"ウ", "u"}, {"エ", "e"}, {"オ", "o"},
    {"カ", "ka"}, {"キ", "ki"}, {"ク", "ku"}, {"ケ", "ke"}, {"コ", "ko"},
    {"サ", "sa"}, {"シ", "shi"}, {"ス", "su"}, {"セ", "se"}, {"ソ", "so"},
    {"タ", "ta"}, {"チ", "chi"}, {"ツ", "tsu"}, {"テ", "te"}, {"ト", "to"},
    {"ナ", "na"}, {"ニ", "ni"}, {"ヌ", "nu"}, {"ネ", "ne"}, {"ノ", "no"},
    {"ハ", "ha"}, {"ヒ", "hi"}, {"フ", "fu"}, {"ヘ", "he"}, {"ホ", "ho"},
    {"マ", "ma"}, {"ミ", "mi"}, {"ム", "mu"}, {"メ", "me"}, {"モ", "mo"},
    {"ヤ", "ya"}, {"ユ", "yu"}, {"ヨ", "yo"},
    {"ラ", "ra"}, {"リ", "ri"}, {"ル", "ru"}, {"レ", "re"}, {"ロ", "ro"},
    {"ワ", "wa"}, {"ヲ", "wo"},
    {"ン", "n"},
    {"ガ", "ga"}, {"ギ", "gi"}, {"グ", "gu"}, {"ゲ", "ge"}, {"ゴ", "go"},
    {"ザ", "za"}, {"ジ", "ji"}, {"ズ", "zu"}, {"ゼ", "ze"}, {"ゾ", "zo"},
    {"ダ", "da"}, {"ヂ", "dzi"}, {"ヅ", "dzu"}, {"デ", "de"}, {"ド", "do"},
    {"バ", "ba"}, {"ビ", "bi"}, {"ブ", "bu"}, {"ベ", "be"}, {"ボ", "bo"},
    {"パ", "pa"}, {"ピ", "pi"}, {"プ", "pu"}, {"ペ", "pe"}, {"ポ", "po"},
    {"キャ", "kya"}, {"キュ", "kyu"}, {"キョ", "kyo"},
    {"シャ", "sha"}, {"シュ", "shu"}, {"シェ", "she"}, {"ショ", "sho"},
    {"チャ", "cha"}, {"チュ", "chu"}, {"チェ", "che"}, {"チョ", "cho"},
    {"ニャ", "nya"}, {"ニュ", "nyu"}, {"ニョ", "nyo"},
    {"ヒャ", "hya"}, {"ヒュ", "hyu"}, {"ヒョ", "hyo"},
    {"ミャ", "mya"}, {"ミュ", "myu"}, {"ミョ", "myo"},
    {"リャ", "rya"}, {"リュ", "ryu"}, {"リョ", "ryo"},
    {"ギャ", "gya"}, {"ギュ", "gyu"}, {"ギョ", "gyo"},
    {"ジャ", "ja"}, {"ジュ", "ju"}, {"ジェ", "je"}, {"ジョ", "jo"},
    {"ビャ", "bya"}, {"ビュ", "byu"}, {"ビョ", "byo"},
    {"ピャ", "pya"}, {"ピュ", "pyu"}, {"ピョ", "pyo"},
    {"ファ", "fa"}, {"フィ", "fi"}, {"フェ", "fe"}, {"フォ", "fo"},
    {"ティ", "ti"}, {"トゥ", "tu"},
    {"ディ", "di"}, {"ドゥ", "du"},
    {"ウィ", "wi"}, {"ウェ", "we"},
    {"ヴァ", "va"}, {"ヴィ", "vi"}, {"ヴ", "vu"}, {"ヴェ", "ve"}, {"ヴォ", "vo"},
    {"ッ", "sakuon"}, {"ー", "pause"}
};

std::unordered_map<std::string, std::string> RussianCyrillic = {
    {"a", "а"}, {"b", "б"}, {"v", "в"}, {"g", "г"}, {"d", "д"},
    {"e", "е"}, {"yo", "ё"}, {"zh", "ж"}, {"z", "з"}, {"i", "и"},
    {"j", "й"}, {"k", "к"}, {"l", "л"}, {"m", "м"}, {"n", "н"},
    {"o", "о"}, {"p", "п"}, {"r", "р"}, {"s", "с"}, {"t", "т"},
    {"u", "у"}, {"f", "ф"}, {"kh", "х"}, {"ts", "ц"}, {"ch", "ч"},
    {"sh", "ш"}, {"shch", "щ"}, {"y", "ы"}, {"\'", "ь"}, {"\"", "ъ"},
    {"è", "э"}, {"yu", "ю"}, {"ya", "я"},
    {"A", "А"}, {"B", "Б"}, {"V", "В"}, {"G", "Г"}, {"D", "Д"},
    {"E", "Е"}, {"Yo", "Ё"}, {"Zh", "Ж"}, {"Z", "З"}, {"I", "И"},
    {"J", "Й"}, {"K", "К"}, {"L", "Л"}, {"M", "М"}, {"N", "Н"},
    {"O", "О"}, {"P", "П"}, {"R", "Р"}, {"S", "С"}, {"T", "Т"},
    {"U", "У"}, {"F", "Ф"}, {"Kh", "Х"}, {"Ts", "Ц"}, {"Ch", "Ч"},
    {"Sh", "Ш"}, {"Shch", "Щ"}, {"Y", "Ы"}, {"È", "Э"}, {"Yu", "Ю"}, 
    {"Ya", "Я"}, 
    {"jo", "ё"}, {"ž", "ж"}, {"h", "х"}, {"c", "ц"}, {"č", "ч"},
    {"š", "ш"}, {"šč", "щ"}, {"ju", "ю"}, {"ja", "я"}, {"ŝ", "щ"},
    {"Jo", "Ё"}, {"Ž", "Ж"}, {"H", "Х"}, {"C", "Ц"}, {"Č", "Ч"}, 
    {"Š", "Ш"}, {"Šč", "Щ"}, {"Ju", "Ю"}, {"Ja", "Я"}, {"Ŝ", "Щ"}
};

std::unordered_map<std::string, std::string> InvertedRussianCyrillic = {
    {"а", "a"}, {"б", "b"}, {"в", "v"}, {"г", "g"}, {"д", "d"},
    {"е", "e"}, {"ё", "yo"}, {"ж", "zh"}, {"з", "z"}, {"и", "i"},
    {"й", "j"}, {"к", "k"}, {"л", "l"}, {"м", "m"}, {"н", "n"},
    {"о", "o"}, {"п", "p"}, {"р", "r"}, {"с", "s"}, {"т", "t"},
    {"у", "u"}, {"ф", "f"}, {"х", "h"}, {"ц", "ts"}, {"ч", "ch"},
    {"ш", "sh"}, {"щ", "shch"}, {"ы", "y"}, {"ь", "\'"}, {"ъ", "\""}, 
    {"э", "e"}, {"ю", "yu"}, {"я", "ya"},
    {"А", "A"}, {"Б", "B"}, {"В", "V"}, {"Г", "G"}, {"Д", "D"},
    {"Е", "E"}, {"Ё", "Yo"}, {"Ж", "Zh"}, {"З", "Z"}, {"И", "I"},
    {"Й", "J"}, {"К", "K"}, {"Л", "L"}, {"М", "M"}, {"Н", "N"},
    {"О", "O"}, {"П", "P"}, {"Р", "R"}, {"С", "S"}, {"Т", "T"},
    {"У", "U"}, {"Ф", "F"}, {"Х", "H"}, {"Ц", "Ts"}, {"Ч", "Ch"},
    {"Ш", "Sh"}, {"Щ", "Shch"}, {"Ы", "Y"}, {"Ь", "\'"}, {"Ъ", "\""}, 
    {"Э", "E"}, {"Ю", "Yu"}, {"Я", "Ya"}
};