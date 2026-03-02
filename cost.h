#ifndef COST_H
#define COST_H

struct Cost {
    int hrn;
    float kop; 

    void add(Cost other);
    void multiply(int quantity);
    void round_to_10();
    void print() const;
};

#endif