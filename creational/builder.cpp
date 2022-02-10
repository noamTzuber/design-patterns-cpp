# include <iostream>

using namespace std;

class level {
public:
    string nameCharacter;
    int smallEnemyNumber;
    int superEnemyNumber;
    int numLevel;

    level() {};

};

// abstract builder
class builder {
protected:
    level *l;
public:
    builder(level *l) : l(l) {}

    virtual void setNameCharacter()=0;

    virtual void setSuperEnemyNumber(int x)=0;

    virtual void setSmallEnemyNumber(int x)=0;

    virtual void setLevelNum(int x) = 0;

    void getLevel() {
        cout << "level num: " << l->numLevel << endl;
        cout << l->nameCharacter << endl;
        cout << "number of small: " << l->smallEnemyNumber << endl;
        cout << "number of big: " << l->superEnemyNumber << endl;
    }
};

// builder of mario
class marioBuilder : public builder {
public:
    level *l;

    marioBuilder(level *l) : builder(l), l(l) {};

    void setNameCharacter() {
        l->nameCharacter = "mario";
    };

    void setSuperEnemyNumber(int x) {
        l->superEnemyNumber = x;
    }

    void setSmallEnemyNumber(int x) {
        l->smallEnemyNumber = x;
    }

    void setLevelNum(int x) {
        l->numLevel = x;
    }

};

// builder od aladin
class AladinBuilder : public builder {
public:
    AladinBuilder(level *l) : builder(l) {};

    void setNameCharacter() {
        l->nameCharacter = "Aladin";
    };

    void setSuperEnemyNumber(int x) {
        l->superEnemyNumber = x;
    }

    void setSmallEnemyNumber(int x) {
        l->smallEnemyNumber = x;
    }

    void setLevelNum(int x) {
        l->numLevel = x;
    }

};

// director level
class levelDirector {
public:
    virtual void createLevel(builder *b) = 0;
};

// specific level
class firstLevel : public levelDirector {
public:
    firstLevel() : levelDirector() {};

    virtual void createLevel(builder *b) {
        b->setNameCharacter();
        b->setSmallEnemyNumber(100);
        b->setSuperEnemyNumber(1);
        b->setLevelNum(1);
    };
};

// specific level
class finalLevel : public levelDirector {
public:
    finalLevel() : levelDirector() {};

    virtual void createLevel(builder *b) {
        b->setNameCharacter();
        b->setSmallEnemyNumber(1000);
        b->setSuperEnemyNumber(100);
        b->setLevelNum(10);
    };
};
//
//int main() {
//    level *maLev = new level;
//    builder *m = new marioBuilder(maLev);
//    levelDirector *first = new firstLevel();
//    first->createLevel(m);
//    m->getLevel();
//
//    cout << endl << "****************************************" << endl << endl;
//
//    level *alLev = new level;
//    builder *a = new AladinBuilder(alLev);
//    levelDirector *final = new finalLevel();
//    final->createLevel(a);
//    a->getLevel();
//
//    return 0;
//}