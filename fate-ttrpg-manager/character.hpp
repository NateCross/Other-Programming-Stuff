#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

static const int ASPECT_MAX = 100;
static const int STRING_MAX = 200;

class Character {
    public:
        Character();
        Character(const std::string&);                    // Sets name
        Character(const std::string&, const int&);        // Name and Fate Pts

        void              setName           (const std::string&);
        void              setAspect         (const std::string&, const int&);
        void              setFatePts        (const int&);

        const std::string getName           ();
        const std::string getAspect         (const int&);
        const int         getFatePts        ();
        const int         getAspectNum      ();

        void              addAspect         (const std::string&);
        bool              deleteAspect      (const int&);
        void              swapAspect        (const int&, const int&);
        // void              countAspects      ();
        const void        displayAllAspects ();

        void              addFatePoint      ();
        void              removeFatePoint   ();

    protected:
        std::string  characterName;
        std::string  aspect[ASPECT_MAX];
        unsigned int aspectNum;
        unsigned int fatePts;
};

#endif
