#ifndef MAIN_LEVEL_H
#define MAIN_LEVEL_H

#include "character_factory.h"
#include "base.h"

#include <ijengine/level.h>
#include <ijengine/texture.h>
#include <ijengine/event.h>

#include <string>
#include <memory>
#include <vector>
#include <utility>

using std::pair;
using std::string;
using std::vector;
using std::shared_ptr;

using ijengine::Level;
using ijengine::Canvas;
using ijengine::Texture;
using ijengine::Event;

#define MAX_W 16
#define MAX_H 12

class MainLevel : public Level {
public:
	MainLevel(const string& next = "", vector < int > players_characters = {});
    ~MainLevel();

    enum {
        INFILTRATOR,
        MAGE,
        SOLDIER,
        KNIGHT
    };

    enum {
        PLAYER_1,
        PLAYER_2,
        PLAYER_3,
        PLAYER_4
    };
    
	bool done() const;
	string next() const;
    string audio() const;

protected:
    void update_self(unsigned now, unsigned last);
    void draw_self(Canvas *canvas, unsigned now, unsigned last);
    void set_players_characters_position(unsigned player_id, double& x_pos, double& y_pos);
    void verify_bases();

private:
    bool m_done;
    string m_next;
    int m_start;
    bool m_has_winner;

    vector <Base* > m_bases;
    vector < int > m_players_characters;
    shared_ptr<Texture> m_texture;
    int m_map[MAX_W][MAX_H];
    CharacterFactory m_character_factory;
};

#endif
