#ifndef TEST_LEVEL_FACTORY_H
#define TEST_LEVEL_FACTORY_H

#include <ijengine/level_factory.h>
#include "character_choose_level.h"

using namespace ijengine;

class TestLevelFactory : public LevelFactory {
public:
    Level * make_level(const string& level_id);
    void release(Level *level);

private:
    CharacterChooseLevel* m_character_choose_level;
};

#endif
