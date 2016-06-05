#ifndef SKILL_H
#define SKILL_H

#include <ijengine/game_object.h>
#include <ijengine/rectangle.h>
#include <ijengine/canvas.h>
#include <ijengine/collidable.h>
#include <ijengine/engine.h>

using namespace ijengine;

class Skill : public GameObject, public Collidable  {
public:
    Skill(GameObject *parent, double xp, double yp);
    ~Skill();

    virtual bool active() const = 0;
    virtual const Rectangle& bounding_box() const = 0;
    virtual const list<Rectangle>& hit_boxes() const = 0;
    virtual pair<double, double> direction() const = 0;

    virtual void on_collision(const Collidable *who, const Rectangle& where, unsigned now, unsigned last) = 0;
    int damage() const;

protected:
    unsigned m_character_id;
    double m_dx, m_dy;
    int m_damage;
    double m_speed;

};

#endif