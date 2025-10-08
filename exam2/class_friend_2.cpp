class Engine;
class Car {
    int hp = 300;
    friend class Engine;   // Engine’s member functions get access
};
class Engine {
public:
    void tune(Car& c) { c.hp += 50; }
};
