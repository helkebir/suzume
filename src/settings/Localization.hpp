//
// Created by Hamza El-Kebir on 12/4/21.
//

#ifndef SUZUME_LOCALIZATION_HPP
#define SUZUME_LOCALIZATION_HPP

#include "Languages.hpp"
#include "tiles/TilesEnum.hpp"
#include "settings/GlobalFlags.hpp"

#include <string>
#include <map>

#define ADD_LOCALIZATION(LANGUAGE, VALUE, STR) \
template <> \
struct Localization<LANGUAGE, typeof(VALUE), VALUE> { \
    static constexpr const char* str = STR; \
}

#define MAKE_MAP(LANGUAGE, TYPE, CONTENT) \
template <> \
class LocalizationMap<LANGUAGE, TYPE> {   \
public:                                   \
    static const std::map <TYPE, const char *> map; \
    static const char * get(TYPE value)                \
    {                                     \
        try {                             \
            return map.at(value);         \
        } catch (std::out_of_range &e) {  \
            return "N/A";                 \
        };                                \
    }                                     \
private:                                  \
    static std::map<TYPE, const char *> createMap() \
    { \
        std::map<TYPE, const char *> m;   \
        CONTENT                           \
        return m;                         \
    }                                     \
};

#define INIT_LOCALIZATION_MAP(LANGUAGE, TYPE) \
const std::map <TYPE, const char *> LocalizationMap<LANGUAGE, TYPE>::map = LocalizationMap<LANGUAGE, TYPE>::createMap()

#define GET_LOCALIZATION_DYN(LANGUAGE, VALUE) \
LocalizationMap<LANGUAGE, typeof(VALUE)>::get(VALUE)

#define GET_LOCALIZATION(LANGUAGE, VALUE) \
Localization<LANGUAGE, typeof(VALUE), VALUE>::str

#define ADD_MAP_ENTRY(LANGUAGE, VALUE) \
m[VALUE] = GET_LOCALIZATION(LANGUAGE, VALUE);

namespace szm {
    template <Languages TLanguage, typename TType, TType TValue>
    struct Localization;

    template <Languages TLanguage, typename TType>
    class LocalizationMap;

    template <Languages TLanguage, typename TType, TType TValue>
    struct Localization {
        static constexpr const char* str = "N/A";
    };

    template <Languages TLanguage, typename TType>
    class LocalizationMap {
    public:
        static const char * get(TType value)
        {
            return "N/A";
        }
    };

    // INSERT LOCALIZATIONS BELOW
    // --------------------------

    // TILE WAITS
    // English
    ADD_LOCALIZATION(Languages::English, TileWaits::Ryanmen, "two-sided wait");
    ADD_LOCALIZATION(Languages::English, TileWaits::Kanchan, "center wait");
    ADD_LOCALIZATION(Languages::English, TileWaits::Penchan, "one-sided wait");
    ADD_LOCALIZATION(Languages::English, TileWaits::Shanpon, "double-pon wait");
    ADD_LOCALIZATION(Languages::English, TileWaits::Tanki, "pair wait");

    MAKE_MAP(Languages::English, TileWaits,
             ADD_MAP_ENTRY(Languages::English, TileWaits::Ryanmen)
             ADD_MAP_ENTRY(Languages::English, TileWaits::Kanchan)
             ADD_MAP_ENTRY(Languages::English, TileWaits::Penchan)
             ADD_MAP_ENTRY(Languages::English, TileWaits::Shanpon)
             ADD_MAP_ENTRY(Languages::English, TileWaits::Tanki)
    );

    // Japanese
    ADD_LOCALIZATION(Languages::Japanese, TileWaits::Ryanmen, "?????????????????????");
    ADD_LOCALIZATION(Languages::Japanese, TileWaits::Kanchan, "?????????????????????");
    ADD_LOCALIZATION(Languages::Japanese, TileWaits::Penchan, "?????????????????????");
    ADD_LOCALIZATION(Languages::Japanese, TileWaits::Shanpon, "?????????????????????");
    ADD_LOCALIZATION(Languages::Japanese, TileWaits::Tanki, "???????????????");

    MAKE_MAP(Languages::Japanese, TileWaits,
             ADD_MAP_ENTRY(Languages::Japanese, TileWaits::Ryanmen)
                     ADD_MAP_ENTRY(Languages::Japanese, TileWaits::Kanchan)
                     ADD_MAP_ENTRY(Languages::Japanese, TileWaits::Penchan)
                     ADD_MAP_ENTRY(Languages::Japanese, TileWaits::Shanpon)
                     ADD_MAP_ENTRY(Languages::Japanese, TileWaits::Tanki)
    );

    // Japanese Kanji
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileWaits::Ryanmen, "????????????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileWaits::Kanchan, "????????????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileWaits::Penchan, "????????????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileWaits::Shanpon, "????????????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileWaits::Tanki, "????????????");

    MAKE_MAP(Languages::JapaneseKanji, TileWaits,
             ADD_MAP_ENTRY(Languages::JapaneseKanji, TileWaits::Ryanmen)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileWaits::Kanchan)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileWaits::Penchan)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileWaits::Shanpon)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileWaits::Tanki)
    );

    // Japanese Phonetic
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileWaits::Ryanmen, "?????????????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileWaits::Kanchan, "?????????????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileWaits::Penchan, "?????????????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileWaits::Shanpon, "?????????????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileWaits::Tanki, "???????????????");

    MAKE_MAP(Languages::JapanesePhonetic, TileWaits,
             ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileWaits::Ryanmen)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileWaits::Kanchan)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileWaits::Penchan)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileWaits::Shanpon)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileWaits::Tanki)
    );

    // TILE LOCATIONS
    // English
    ADD_LOCALIZATION(Languages::English, TileLocations::Yama, "wall");
    ADD_LOCALIZATION(Languages::English, TileLocations::Kawa, "discards");
    ADD_LOCALIZATION(Languages::English, TileLocations::Te, "hand");

    MAKE_MAP(Languages::English, TileLocations,
             ADD_MAP_ENTRY(Languages::English, TileLocations::Yama)
             ADD_MAP_ENTRY(Languages::English, TileLocations::Kawa)
             ADD_MAP_ENTRY(Languages::English, TileLocations::Te)
    );

    // Japanese
    ADD_LOCALIZATION(Languages::Japanese, TileLocations::Yama, "???");
    ADD_LOCALIZATION(Languages::Japanese, TileLocations::Kawa, "???");
    ADD_LOCALIZATION(Languages::Japanese, TileLocations::Te, "???");

    MAKE_MAP(Languages::Japanese, TileLocations,
             ADD_MAP_ENTRY(Languages::Japanese, TileLocations::Yama)
                     ADD_MAP_ENTRY(Languages::Japanese, TileLocations::Kawa)
                     ADD_MAP_ENTRY(Languages::Japanese, TileLocations::Te)
    );

    // Japanese Kanji
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileLocations::Yama, "???");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileLocations::Kawa, "???");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileLocations::Te, "???");

    MAKE_MAP(Languages::JapaneseKanji, TileLocations,
             ADD_MAP_ENTRY(Languages::JapaneseKanji, TileLocations::Yama)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileLocations::Kawa)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileLocations::Te)
    );

    // Japanese Phonetic
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileLocations::Yama, "??????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileLocations::Kawa, "??????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileLocations::Te, "???");

    MAKE_MAP(Languages::JapanesePhonetic, TileLocations,
             ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileLocations::Yama)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileLocations::Kawa)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileLocations::Te)
    );

    // TILE ORIGINS
    // English
    ADD_LOCALIZATION(Languages::English, TileOrigins::Haiyama, "undealts");
    ADD_LOCALIZATION(Languages::English, TileOrigins::Toncha, "East player");
    ADD_LOCALIZATION(Languages::English, TileOrigins::Nancha, "South player");
    ADD_LOCALIZATION(Languages::English, TileOrigins::Shacha, "West player");
    ADD_LOCALIZATION(Languages::English, TileOrigins::Peicha, "North player");

    MAKE_MAP(Languages::English, TileOrigins,
             ADD_MAP_ENTRY(Languages::English, TileOrigins::Haiyama)
                     ADD_MAP_ENTRY(Languages::English, TileOrigins::Toncha)
                     ADD_MAP_ENTRY(Languages::English, TileOrigins::Nancha)
                     ADD_MAP_ENTRY(Languages::English, TileOrigins::Shacha)
                     ADD_MAP_ENTRY(Languages::English, TileOrigins::Peicha)
    );

    // Japanese
    ADD_LOCALIZATION(Languages::Japanese, TileOrigins::Haiyama, "??????");
    ADD_LOCALIZATION(Languages::Japanese, TileOrigins::Toncha, "??????");
    ADD_LOCALIZATION(Languages::Japanese, TileOrigins::Nancha, "??????");
    ADD_LOCALIZATION(Languages::Japanese, TileOrigins::Shacha, "??????");
    ADD_LOCALIZATION(Languages::Japanese, TileOrigins::Peicha, "??????");

    MAKE_MAP(Languages::Japanese, TileOrigins,
             ADD_MAP_ENTRY(Languages::Japanese, TileOrigins::Haiyama)
                     ADD_MAP_ENTRY(Languages::Japanese, TileOrigins::Toncha)
                     ADD_MAP_ENTRY(Languages::Japanese, TileOrigins::Nancha)
                     ADD_MAP_ENTRY(Languages::Japanese, TileOrigins::Shacha)
                     ADD_MAP_ENTRY(Languages::Japanese, TileOrigins::Peicha)
    );

    // Japanese Kanji
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileOrigins::Haiyama, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileOrigins::Toncha, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileOrigins::Nancha, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileOrigins::Shacha, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileOrigins::Peicha, "??????");

    MAKE_MAP(Languages::JapaneseKanji, TileOrigins,
             ADD_MAP_ENTRY(Languages::JapaneseKanji, TileOrigins::Haiyama)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileOrigins::Toncha)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileOrigins::Nancha)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileOrigins::Shacha)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileOrigins::Peicha)
    );

    // Japanese Phonetic
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileOrigins::Haiyama, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileOrigins::Toncha, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileOrigins::Nancha, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileOrigins::Shacha, "???????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileOrigins::Peicha, "????????????");

    MAKE_MAP(Languages::JapanesePhonetic, TileOrigins,
             ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileOrigins::Haiyama)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileOrigins::Toncha)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileOrigins::Nancha)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileOrigins::Shacha)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileOrigins::Peicha)
    );

    // TILE STATES
    // English
    ADD_LOCALIZATION(Languages::English, TileStates::Open, "open");
    ADD_LOCALIZATION(Languages::English, TileStates::Closed, "closed");
    ADD_LOCALIZATION(Languages::English, TileStates::Wanpai, "dead wall");
    ADD_LOCALIZATION(Languages::English, TileStates::Dora, "dora");
    ADD_LOCALIZATION(Languages::English, TileStates::UraDora, "hidden dora");
    ADD_LOCALIZATION(Languages::English, TileStates::AkaDora, "red dora");
    ADD_LOCALIZATION(Languages::English, TileStates::DoraIndicator, "dora indicator");
    ADD_LOCALIZATION(Languages::English, TileStates::UraDoraIndicator, "hidden dora indicator");
    ADD_LOCALIZATION(Languages::English, TileStates::Tehai, "tile in hand");
    ADD_LOCALIZATION(Languages::English, TileStates::Sutehai, "discarded hand");
    ADD_LOCALIZATION(Languages::English, TileStates::Kanpai, "kan tile");
    ADD_LOCALIZATION(Languages::English, TileStates::Ponpai, "pon tile");
    ADD_LOCALIZATION(Languages::English, TileStates::Ronpai, "ron tile");
    ADD_LOCALIZATION(Languages::English, TileStates::Tsumohai, "drawn tile");
    ADD_LOCALIZATION(Languages::English, TileStates::Chiipai, "chii tile");
    ADD_LOCALIZATION(Languages::English, TileStates::Yamahai, "wall tile");
    ADD_LOCALIZATION(Languages::English, TileStates::Haipai, "dealt tile");

    MAKE_MAP(Languages::English, TileStates,
             ADD_MAP_ENTRY(Languages::English, TileStates::Open)
                     ADD_MAP_ENTRY(Languages::English, TileStates::Closed)
                     ADD_MAP_ENTRY(Languages::English, TileStates::Wanpai)
                     ADD_MAP_ENTRY(Languages::English, TileStates::Dora)
                     ADD_MAP_ENTRY(Languages::English, TileStates::UraDora)
                     ADD_MAP_ENTRY(Languages::English, TileStates::AkaDora)
                     ADD_MAP_ENTRY(Languages::English, TileStates::DoraIndicator)
                     ADD_MAP_ENTRY(Languages::English, TileStates::UraDoraIndicator)
                     ADD_MAP_ENTRY(Languages::English, TileStates::Tehai)
                     ADD_MAP_ENTRY(Languages::English, TileStates::Sutehai)
                     ADD_MAP_ENTRY(Languages::English, TileStates::Kanpai)
                     ADD_MAP_ENTRY(Languages::English, TileStates::Ponpai)
                     ADD_MAP_ENTRY(Languages::English, TileStates::Ronpai)
                     ADD_MAP_ENTRY(Languages::English, TileStates::Tsumohai)
                     ADD_MAP_ENTRY(Languages::English, TileStates::Chiipai)
                     ADD_MAP_ENTRY(Languages::English, TileStates::Yamahai)
                     ADD_MAP_ENTRY(Languages::English, TileStates::Haipai)
    );

    // Japanese
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Open, "???");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Closed, "???");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Wanpai, "??????");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Dora, "??????");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::UraDora, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::AkaDora, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::DoraIndicator, "????????????");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::UraDoraIndicator, "???????????????");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Tehai, "??????");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Sutehai, "??????");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Kanpai, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Ponpai, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Ronpai, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Tsumohai, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Chiipai, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Yamahai, "??????");
    ADD_LOCALIZATION(Languages::Japanese, TileStates::Haipai, "??????");

    MAKE_MAP(Languages::Japanese, TileStates,
             ADD_MAP_ENTRY(Languages::Japanese, TileStates::Open)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::Closed)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::Wanpai)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::Dora)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::UraDora)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::AkaDora)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::DoraIndicator)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::UraDoraIndicator)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::Tehai)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::Sutehai)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::Kanpai)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::Ponpai)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::Ronpai)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::Tsumohai)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::Chiipai)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::Yamahai)
                     ADD_MAP_ENTRY(Languages::Japanese, TileStates::Haipai)
    );

    // Japanese Kanji
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Open, "???");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Closed, "???");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Wanpai, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Dora, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::UraDora, "?????????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::AkaDora, "?????????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::DoraIndicator, "????????????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::UraDoraIndicator, "???????????????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Tehai, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Sutehai, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Kanpai, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Ponpai, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Ronpai, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Tsumohai, "?????????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Chiipai, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Yamahai, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, TileStates::Haipai, "??????");

    MAKE_MAP(Languages::JapaneseKanji, TileStates,
             ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Open)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Closed)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Wanpai)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Dora)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::UraDora)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::AkaDora)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::DoraIndicator)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::UraDoraIndicator)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Tehai)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Sutehai)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Kanpai)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Ponpai)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Ronpai)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Tsumohai)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Chiipai)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Yamahai)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, TileStates::Haipai)
    );

    // Japanese Phonetic
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Open, "??????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Closed, "??????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Wanpai, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Dora, "??????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::UraDora, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::AkaDora, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::DoraIndicator, "??????????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::UraDoraIndicator, "????????????????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Tehai, "?????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Sutehai, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Kanpai, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Ponpai, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Ronpai, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Tsumohai, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Chiipai, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Yamahai, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, TileStates::Haipai, "????????????");

    MAKE_MAP(Languages::JapanesePhonetic, TileStates,
             ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Open)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Closed)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Wanpai)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Dora)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::UraDora)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::AkaDora)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::DoraIndicator)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::UraDoraIndicator)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Tehai)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Sutehai)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Kanpai)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Ponpai)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Ronpai)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Tsumohai)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Chiipai)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Yamahai)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, TileStates::Haipai)
    );

    // TILES
    // English

    ADD_LOCALIZATION(Languages::English, Tiles::Man1, "1 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::Man2, "2 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::Man3, "3 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::Man4, "4 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::Man5, "5 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::ManR5, "red 5 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::Man6, "6 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::Man7, "7 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::Man8, "8 characters");
    ADD_LOCALIZATION(Languages::English, Tiles::Man9, "9 characters");

    ADD_LOCALIZATION(Languages::English, Tiles::Pin1, "1 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::Pin2, "2 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::Pin3, "3 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::Pin4, "4 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::Pin5, "5 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::PinR5, "red 5 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::Pin6, "6 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::Pin7, "7 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::Pin8, "8 dots");
    ADD_LOCALIZATION(Languages::English, Tiles::Pin9, "9 dots");

    ADD_LOCALIZATION(Languages::English, Tiles::Sou1, "1 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::Sou2, "2 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::Sou3, "3 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::Sou4, "4 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::Sou5, "5 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::SouR5, "red 5 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::Sou6, "6 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::Sou7, "7 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::Sou8, "8 sticks");
    ADD_LOCALIZATION(Languages::English, Tiles::Sou9, "9 sticks");

    ADD_LOCALIZATION(Languages::English, Tiles::Ton, "East");
    ADD_LOCALIZATION(Languages::English, Tiles::Nan, "South");
    ADD_LOCALIZATION(Languages::English, Tiles::Sha, "West");
    ADD_LOCALIZATION(Languages::English, Tiles::Pei, "North");

    ADD_LOCALIZATION(Languages::English, Tiles::Haku, "white dragon");
    ADD_LOCALIZATION(Languages::English, Tiles::Hatu, "green dragon");
    ADD_LOCALIZATION(Languages::English, Tiles::Chun, "red dragon");

    MAKE_MAP(Languages::English, Tiles,
             ADD_MAP_ENTRY(Languages::English, Tiles::Man1)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Man2)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Man3)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Man4)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Man5)
                     ADD_MAP_ENTRY(Languages::English, Tiles::ManR5)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Man6)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Man7)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Man8)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Man9)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin1)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin2)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin3)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin4)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin5)
                     ADD_MAP_ENTRY(Languages::English, Tiles::PinR5)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin6)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin7)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin8)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pin9)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou1)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou2)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou3)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou4)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou5)
                     ADD_MAP_ENTRY(Languages::English, Tiles::SouR5)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou6)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou7)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou8)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sou9)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Ton)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Nan)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Sha)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Pei)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Haku)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Hatu)
                     ADD_MAP_ENTRY(Languages::English, Tiles::Chun)
    );

    // Japanese

    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man1, "???" MAWA "???");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man2, "???" MAWA "???");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man3, "???" MAWA "???");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man4, "???" MAWA "???");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man5, "???" MAWA "???");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::ManR5, "??????" MAWA "???");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man6, "???" MAWA "???");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man7, "???" MAWA "???");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man8, "???" MAWA "???");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Man9, "???" MAWA "???");

    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin1, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin2, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin3, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin4, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin5, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::PinR5, "????????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin6, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin7, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin8, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pin9, "?????????");

    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou1, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou2, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou3, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou4, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou5, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::SouR5, "????????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou6, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou7, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou8, "?????????");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sou9, "?????????");

    ADD_LOCALIZATION(Languages::Japanese, Tiles::Ton, "???");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Nan, "???");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Sha, "???");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Pei, "???");

    ADD_LOCALIZATION(Languages::Japanese, Tiles::Haku, "???");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Hatu, "???");
    ADD_LOCALIZATION(Languages::Japanese, Tiles::Chun, "???");

    MAKE_MAP(Languages::Japanese, Tiles,
             ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man1)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man2)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man3)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man4)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man5)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::ManR5)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man6)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man7)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man8)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Man9)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin1)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin2)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin3)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin4)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin5)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::PinR5)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin6)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin7)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin8)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pin9)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou1)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou2)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou3)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou4)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou5)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::SouR5)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou6)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou7)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou8)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sou9)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Ton)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Nan)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Sha)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Pei)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Haku)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Hatu)
                     ADD_MAP_ENTRY(Languages::Japanese, Tiles::Chun)
    );

    // Japanese???Kanji

    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man1, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man2, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man3, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man4, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man5, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::ManR5, "?????????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man6, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man7, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man8, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Man9, "??????");

    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin1, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin2, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin3, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin4, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin5, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::PinR5, "?????????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin6, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin7, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin8, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pin9, "??????");

    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou1, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou2, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou3, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou4, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou5, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::SouR5, "?????????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou6, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou7, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou8, "??????");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sou9, "??????");

    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Ton, "???");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Nan, "???");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Sha, "???");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Pei, "???");

    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Haku, "???");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Hatu, "???");
    ADD_LOCALIZATION(Languages::JapaneseKanji, Tiles::Chun, "???");

    MAKE_MAP(Languages::JapaneseKanji, Tiles,
             ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man1)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man2)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man3)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man4)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man5)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::ManR5)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man6)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man7)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man8)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Man9)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin1)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin2)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin3)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin4)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin5)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::PinR5)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin6)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin7)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin8)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pin9)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou1)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou2)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou3)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou4)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou5)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::SouR5)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou6)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou7)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou8)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sou9)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Ton)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Nan)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Sha)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Pei)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Haku)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Hatu)
                     ADD_MAP_ENTRY(Languages::JapaneseKanji, Tiles::Chun)
    );

    // Japanese Phonetic

    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man1, "??????" MAWA "???");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man2, "?????????" MAWA "???");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man3, "??????" MAWA "???");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man4, "??????" MAWA "???");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man5, "??????" MAWA "???");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::ManR5, "????????????" MAWA "???");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man6, "??????" MAWA "???");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man7, "??????" MAWA "???");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man8, "??????" MAWA "???");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Man9, "?????????" MAWA "???");

    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin1, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin2, "???????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin3, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin4, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin5, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::PinR5, "??????????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin6, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin7, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin8, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pin9, "???????????????");

    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou1, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou2, "???????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou3, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou4, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou5, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::SouR5, "??????????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou6, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou7, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou8, "????????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sou9, "???????????????");

    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Ton, "??????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Nan, "??????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Sha, "?????????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Pei, "??????");

    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Haku, "??????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Hatu, "??????");
    ADD_LOCALIZATION(Languages::JapanesePhonetic, Tiles::Chun, "?????????");

    MAKE_MAP(Languages::JapanesePhonetic, Tiles,
             ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man1)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man2)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man3)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man4)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man5)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::ManR5)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man6)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man7)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man8)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Man9)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin1)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin2)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin3)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin4)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin5)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::PinR5)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin6)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin7)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin8)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pin9)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou1)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou2)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou3)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou4)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou5)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::SouR5)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou6)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou7)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou8)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sou9)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Ton)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Nan)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Sha)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Pei)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Haku)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Hatu)
                     ADD_MAP_ENTRY(Languages::JapanesePhonetic, Tiles::Chun)
    );
}

#endif //SUZUME_LOCALIZATION_HPP
